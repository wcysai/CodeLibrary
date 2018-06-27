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
ll t,A[MAXN],B[MAXN],ans[MAXN];  
int main()
{
    int n,m;  
    string s1;  
    string s2;
    scanf("%lld",&t);  
    while(t--)  
    {  
        cin>>s1>>s2;
        n=s1.size();  
        m=s2.size();  
        memset(A,0,sizeof(A));  
        memset(B,0,sizeof(B));  
        for(int i=n-1; i>=0 ; i--)  
            A[i]=s1[n-i-1]-'0';  
        for(int i=m-1; i>=0; i--)  
            B[i]=s2[m-i-1]-'0';  
        int tmp=1;  
        while(tmp<max(n,m))  
            tmp*=2;  
        n=tmp;  
  
        ntt(2*n,A,1);  
        ntt(2*n,B,1);  
        for(int i=0; i<2*n; i++)  
            A[i]=A[i]*B[i]%MOD;  
        ntt(2*n,A,-1);  
        memset(ans,0,sizeof ans);  
        for(int i=0;i<2*n;i++)  
        {  
            ans[i]+=A[i];  
            if(ans[i]>=10)  
            {  
                ans[i+1]+=ans[i]/10;  
                ans[i]%=10;  
            }  
        }  
        int e=0;  
        for(int i=2*n-1;i>=0;i--)  
        {  
            if(ans[i])  
            {  
                e=i;  
                break;  
            }  
        }  
        for(int i=e;i>=0;i--)  
        {  
            printf("%lld",ans[i]);  
        }  
        printf("\n");  
    }
    return 0;  
}
