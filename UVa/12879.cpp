#include<bits/stdc++.h>
#define MAXN 200005
#define MOD 998244353
#define INF 1000000000
#define F first
#define S second
using namespace std;  
typedef long long ll;
typedef pair<int,int> P;    
const ll g=3; 
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
ll rev(ll x,ll r)  
{  
    ll ans=0;  
    for(ll i=0;i<r;i++)  
        if(x&(1<<i)) ans+=1<<(r-i-1);   
    return ans;  
}  
void ntt(ll n,ll A[],ll on)
{
    ll r=0;  
    for(;;r++) if((1<<r)==n)  break;   
    for(ll i=0;i<n;i++)  
    {  
        ll tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(ll s=1;s<=r;s++)  
    {  
        ll m=1<<s;  
        ll wn=pow_mod(g,(MOD-1)/m);  
        for(ll k=0;k<n;k+=m)  
        {  
            ll w=1;  
            for(ll j=0;j<m/2;j++)  
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
        for(ll i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);  
        ll inv=pow_mod(n,MOD-2);  
        for(ll i=0;i<n;i++)  
            A[i]=A[i]%MOD*inv%MOD;  
    }  
}
ll n,m,A[MAXN*4],B[MAXN*4],C[MAXN],D[4*MAXN],ans;  
int main()
{
    while(scanf("%lld",&n)==1)
    {
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(D,0,sizeof(D));
        for(ll i=0;i<n;i++)
        {
            ll x;
            scanf("%lld",&x);
            A[x]++;
            B[x]++;
            D[x]++;
        }
        scanf("%lld",&m);
        for(ll i=0;i<m;i++)
            scanf("%lld",&C[i]);
        ll len=1;
        while(len<400000) len*=2;
        ntt(len,A,1);
        ntt(len,B,1);
        for(ll i=0;i<len;i++)
            A[i]=A[i]*B[i]%MOD;
        ntt(len,A,-1);
        for(ll i=0;i<len;i++)
            A[i]+=D[i];
        ans=0;
        for(ll i=0;i<m;i++)
            if(A[C[i]]>0) ans++;
        printf("%lld\n",ans);
    }
    return 0;  
}
