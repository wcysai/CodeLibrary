#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 998244353
#define INF 1000000000
#define F first
#define S second
using namespace std;  
typedef long long ll;
typedef pair<int,int> P;    
const int g=3; 
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
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
void ntt(int n,ll A[],int on)
{
    int r=0;  
    for(;;r++) if((1<<r)==n)  break;   
    for(int i=0;i<n;i++)  
    {  
        int tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(int s=1;s<=r;s++)  
    {  
        int m=1<<s;  
        ll wn=pow_mod(g,(MOD-1)/m);  
        for(int k=0;k<n;k+=m)  
        {  
            ll w=1;  
            for(int j=0;j<m/2;j++)  
            {  
                ll t,u;  
                t=w*(A[k+j+m/2]%MOD)%MOD;  
                u=A[k+j]%MOD;  
                A[k+j]=(u+t)%MOD;  
                A[k+j+m/2]=((u-t)%MOD+MOD)%MOD;  
                w=w*wn%MOD;  
            }  
        }  
    }  
    if(on==-1)  
    {  
        for(int i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);  
        ll inv=pow_mod(n,MOD-2);  
        for(int i=0;i<n;i++)  
            A[i]=A[i]%MOD*inv%MOD;  
    }  
}
ll n,a[MAXN],blocks,sz; 
ll before[MAXN],later[MAXN],A[MAXN],B[MAXN];
int main()
{
    scanf("%lld",&n);
    ll len=1;
    while(len<30000) len*=2;
    len*=2;
    memset(before,0,sizeof(before));
    memset(later,0,sizeof(later));
    blocks=max(n,30LL);
    sz=(n-1)/blocks+1;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        later[a[i]]++;
    }
    for(ll i=0;i<sz;i++)
    {
        ll s=i*blocks,t=(i+1)*blocks;
        if(t>n) t=n;
        for(ll j=s;j<t;j++)
            later[a[j]]--;
        for(ll j=1;j<=30000;j++)
        {
            A[j]=before[j];
            B[j]=later[j];
        }
        ntt(len,A,1);
        ntt(len,B,1);
        for(ll j=1;j<=30000;j++)
            A[j]=A[j]*B[j]%MOD;
        ntt(len,A,-1);
        for(ll j=s;j<t;j++)
        {
            ll num=2*a[j];
            if(1<=num&&num<=30000) ans+=A[num];
        }
        for(ll j=s;j<t;j++)
        {
            for(ll k=j+1;k<t;k++)
            {
                ll num=a[j]*2-a[k];
                if(1<=num&&num<=30000) ans+=before[num];
                num=a[k]*2-a[j];
                if(1<=num&&num<=30000) ans+=later[num];
            }
            before[a[j]]++;
        }
    }
    printf("%lld\n",ans);
    return 0;  
}
