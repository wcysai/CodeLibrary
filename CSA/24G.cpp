#include <bits/stdc++.h>
#define MAXN 400005
#define MAXM 55
#define MOD 924844033
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int g=5; 
int two[31];
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
int dbit(int x)
{
    while(x!=(x&-x)) x+=(x&-x);
    return x;
}
int n,m;
int fact[MAXN],invf[MAXN],ans[MAXN];
int stirling[MAXN][MAXM],coef[MAXN],A[MAXN],B[MAXN];
void solve(int l,int r)
{
    if(l==r) 
    {
        if(l==0) ans[l]=1;
        else ans[l]=(1LL*ans[l]*pow_mod(l,MOD-2))%MOD;
        return;
    }
    int mid=(l+r)/2;
    solve(l,mid);
    int len=dbit(mid-l+r-l+1);
    for(int i=0;i<len;i++)
        A[i]=B[i]=0;
    for(int i=l;i<=mid;i++)
        A[i-l]=ans[i];
    for(int i=0;i<r-l+1;i++)
        B[i]=coef[i];
    ntt(len,A,1);ntt(len,B,1);
    for(int i=0;i<len;i++)
        A[i]=1LL*A[i]*B[i]%MOD;
    ntt(len,A,-1);
    for(int i=mid+1;i<=r;i++)
        ans[i]=(ans[i]+A[i-l])%MOD;
    solve(mid+1,r);
}
int main()
{
    scanf("%d%d",&n,&m);
     for(int i=1;i<=30;i++)
        two[i]=pow_mod(1<<i,MOD-2); 
    fact[0]=1;
    invf[0]=1;
    for(int i=1;i<=n;i++)
    {
        fact[i]=1LL*fact[i-1]*i%MOD;
        invf[i]=pow_mod(fact[i],MOD-2);
    }
    stirling[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            stirling[i][j]=(1LL*stirling[i-1][j]*j+stirling[i-1][j-1])%MOD;
    for(int i=1;i<=n;i++)
        coef[i]=1LL*stirling[i][m]*fact[m]%MOD*pow_mod(i,i-2)%MOD*invf[i-1]%MOD;
    solve(0,n);
    for(int i=1;i<=n;i++)
        printf("%d\n",1LL*ans[i]*fact[i]%MOD);
    return 0;
}
