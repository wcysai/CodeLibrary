#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
const double PI=acos(-1.0);
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
namespace fft
{
    struct num
    {
        double x,y;
        num() {x=y=0;}
        num(double x,double y):x(x),y(y){}
    };
    inline num operator+(num a,num b) {return num(a.x+b.x,a.y+b.y);}
    inline num operator-(num a,num b) {return num(a.x-b.x,a.y-b.y);}
    inline num operator*(num a,num b) {return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
    inline num conj(num a) {return num(a.x,-a.y);}

    int base=1;
    vector<num> roots={{0,0},{1,0}};
    vector<int> rev={0,1};
    const double PI=acosl(-1.0);

    void ensure_base(int nbase)
    {
        if(nbase<=base) return;
        rev.resize(1<<nbase);
        for(int i=0;i<(1<<nbase);i++)
            rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
        roots.resize(1<<nbase);
        while(base<nbase)
        {
            double angle=2*PI/(1<<(base+1));
            for(int i=1<<(base-1);i<(1<<base);i++)
            {
                roots[i<<1]=roots[i];
                double angle_i=angle*(2*i+1-(1<<base));
                roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<num> &a,int n=-1)
    {
        if(n==-1) n=a.size();
        assert((n&(n-1))==0);
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for(int i=0;i<n;i++)
            if(i<(rev[i]>>shift))
                swap(a[i],a[rev[i]>>shift]);
        for(int k=1;k<n;k<<=1)
        {
            for(int i=0;i<n;i+=2*k)
            {
                for(int j=0;j<k;j++)
                {
                    num z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }

    vector<num> fa,fb;

    vector<int> multiply(vector<int> &a, vector<int> &b)
    {
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<sz;i++)
        {
            int x=(i<(int)a.size()?a[i]:0);
            int y=(i<(int)b.size()?b[i]:0);
            fa[i]=num(x,y);
        }
        fft(fa,sz);
        num r(0,-0.25/sz);
        for(int i=0;i<=(sz>>1);i++)
        {
            int j=(sz-i)&(sz-1);
            num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
            if(i!=j) fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
            fa[i]=z;
        }
        fft(fa,sz);
        vector<int> res(need);
        for(int i=0;i<need;i++) res[i]=fa[i].x+0.5;
        return res;
    }

    vector<int> multiply_mod(vector<int> &a,vector<int> &b,int m,int eq=0)
    {
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<(int)a.size();i++)
        {
            int x=(a[i]%m+m)%m;
            fa[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
        fft(fa,sz);
        if(sz>(int)fb.size()) fb.resize(sz);
        if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
        else
        {
            for(int i=0;i<(int)b.size();i++)
            {
                int x=(b[i]%m+m)%m;
                fb[i]=num(x&((1<<15)-1),x>>15);
            }
            fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
            fft(fb,sz);
        }
        double ratio=0.25/sz;
        num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
        for(int i=0;i<=(sz>>1);i++)
        {
            int j=(sz-i)&(sz-1);
            num a1=(fa[i]+conj(fa[j]));
            num a2=(fa[i]-conj(fa[j]))*r2;
            num b1=(fb[i]+conj(fb[j]))*r3;
            num b2=(fb[i]-conj(fb[j]))*r4;
            if(i!=j)
            {
                num c1=(fa[j]+conj(fa[i]));
                num c2=(fa[j]-conj(fa[i]))*r2;
                num d1=(fb[j]+conj(fb[i]))*r3;
                num d2=(fb[j]-conj(fb[i]))*r4;
                fa[i]=c1*d1+c2*d2*r5;
                fb[i]=c1*d2+c2*d1;
            }
            fa[j]=a1*b1+a2*b2*r5;
            fb[j]=a1*b2+a2*b1;
        }
        fft(fa,sz);fft(fb,sz);
        vector<int> res(need);
        for(int i=0;i<need;i++)
        {
            ll aa=fa[i].x+0.5;
            ll bb=fb[i].x+0.5;
            ll cc=fa[i].y+0.5;
            res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
        }
        return res;
    }
    vector<int> square_mod(vector<int> &a,int m)
    {
        return multiply_mod(a,a,m,1);
    }
};
const int g=3;
int tot=1;
int dbit(int x)
{
    while((x&-x)!=x) x+=x&-x;
    return x;
}
int two[32];
int pow_mod(int a,int i)
{
    if(i==0) return 1;
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%MOD;
         a=(1LL*a*a)%MOD;
         i>>=1;
     }
     return s;
}
int rev(int x,int r)  
{  
    int ans=0;  
    for(int i=0;i<r;i++)  
        if(x&(1<<i)) ans+=1<<(r-i-1);   
    return ans;  
}  
void ntt(int n,int A[],int on)
{
    int r=0,cnt=0,t=n; 
    while(t>1) {cnt++; t/=2;} 
    for(;;r++) if((1<<r)==n)  break;   
    for(int i=0;i<n;i++)  
    {  
        int tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(int s=1;s<=r;s++)  
    {  
        int m=1<<s;  
        int wn=pow_mod(g,(MOD-1)/m);  
        for(int k=0;k<n;k+=m)  
        {  
            int w=1;  
            for(int j=0;j<m/2;j++)  
            {  
                int t,u;  
                t=1LL*w*A[k+j+m/2]%MOD;  
                u=A[k+j];  
                A[k+j]=(u+t);
                if(A[k+j]>=MOD) A[k+j]-=MOD;  
                A[k+j+m/2]=u+MOD-t;
                if(A[k+j+m/2]>=MOD) A[k+j+m/2]-=MOD;
                w=1LL*w*wn%MOD;  
            }  
        }  
    }  
    if(on==-1)  
    {  
        for(int i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);    
        for(int i=0;i<n;i++)  
            A[i]=1LL*A[i]*two[cnt]%MOD;  
    }  
}
int A[MAXN],B[MAXN],C[80000000];
struct atom
{
    int l,r;
};
atom solve(int l,int r)
{
    if (l>r){ C[++tot]=1; return (atom){tot,tot};}
    if (l==r){ C[++tot]=l; C[++tot]=1; return (atom){tot-1,tot};}
    int mid=(l+r)/2; atom k1=solve(l,mid),k2=solve(mid+1,r);
    int n=max(mid-l+1,r-mid),sz=1;
    while (sz<=(n<<1)) sz*=2;
    for (int i=0;i<sz;i++){A[i]=0; B[i]=0;}
    for (int i=k1.l;i<=k1.r;i++) A[i-k1.l]=C[i]; 
    for (int i=k2.l;i<=k2.r;i++) B[i-k2.l]=C[i];
    ntt(sz,A,1); ntt(sz,B,1);
    for (int i=0;i<sz;i++) A[i]=1LL*A[i]*B[i]%MOD;
    ntt(sz,A,-1);
    atom ans; ans.l=tot+1;
    for (int i=0;i<=r-l+1;i++) C[++tot]=A[i]; 
    ans.r=tot; 
    return ans;
}
vector<int> construct(int len)
{
	tot=1;
	vector<int> v; v.resize(len);
	atom ans=solve(0,len-1); 
	for(int i=0;i<len;i++) v[i]=C[ans.r-i];
	return v;
}
vector<vector<int> > v;
vector<int> solve_fft(int l,int r)
{
	if(l==r) return v[l];
	int mid=(l+r)/2;
	vector<int> lhs=solve_fft(l,mid);
	vector<int> rhs=solve_fft(mid+1,r);
	return fft::multiply_mod(lhs,rhs,MOD);
}
int cnt[MAXN];
int main()
{
	for(int i=1;i<=30;i++)
        two[i]=pow_mod(1<<i,MOD-2);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i])
		{
			vector<int> tmp=construct(cnt[i]);
			v.push_back(tmp);
		}
	}
	int sz=(int)v.size();
	vector<int> res=solve_fft(0,sz-1);
	if(k>n) k-=2*(k-n)/2;
	int ans=0;
	for(int i=k;i>=0;i-=2)
	{
		if(i<(int)res.size()) add(ans,res[i]);
	}
	printf("%d\n",ans);
	return 0;
}