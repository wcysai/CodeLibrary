#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1024*1024*4
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int fact[MAXM],invf[MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
const int g=3; 
int two[31];
int dbit(int x)
{
    while(x!=(x&-x)) x+=(x&-x);
    return x;
}
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
ll m;
int A[MAXM];
int main()
{
    for(int i=1;i<=30;i++) two[i]=pow_mod(1<<i,MOD-2);
    fact[0]=invf[0]=1;
    for(int i=1;i<4*1024*1024;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[4*1024*1024-1]=pow_mod(fact[4*1024*1024-1],MOD-2);
    for(int i=4*1024*1024-2;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%lld%d",&n,&m,&k);
    if(m%k) {puts("0"); return 0;}
    m/=k;
    if(n<k){
        int ans=invf[n];
        for(ll i=m;i>=m-n+1;i--) ans=1LL*ans*(i%MOD)%MOD;
        printf("%d\n",ans);
    }
    int num=n+1-k;
    for(int i=0;i<=k-1;i++){
        A[i]=1;
    }
    ntt(4*1024*1024,A,1);
    for(int i=0;i<4*1024*1024;i++) A[i]=pow_mod(A[i],num);
    ntt(4*1024*1024,A,-1);
    int res=1,ans=0;
    //comb(m+n-1,n-1);
    int pw=0;
    for(ll i=m+n-1;i>=m+1;i--) {
        if((i%MOD==0)) {pw++; res=1LL*res*(i/MOD)%MOD;}
        else res=1LL*res*(i%MOD)%MOD;
    }
    for(int i=0;i<=min(m,1LL*num*(k-1));i++){
        if(!pw) add(ans,1LL*res*invf[n-1]%MOD*A[i]%MOD);
        if(((m+n-1-i)%MOD==0)) {pw--; res=1LL*res*pow_mod((m+n-1-i)/MOD,MOD-2)%MOD;}
        else res=1LL*res*pow_mod((m+n-1-i)%MOD,MOD-2)%MOD;
        if(((m-i)%MOD==0)) {pw++; res=1LL*res*((m-i)/MOD)%MOD;}
        else res=1LL*res*((m-i)%MOD)%MOD;
    }
    printf("%d\n",ans);
    return 0;
}

