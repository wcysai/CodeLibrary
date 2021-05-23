#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long long ll;
vector<ll> v;
ll pow_mod(ll a,ll i,ll mod)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%mod;
         a=(a*a)%mod;
         i>>=1;
     }
     return s;
}
bool g_test(ll g,ll p)
{
    for(ll i=0;i<v.size();i++)
        if(pow_mod(g,(p-1)/v[i],p)==1)
            return 0;
    return 1;
}
ll primitive_root(ll p)
{
    ll tmp=p-1;
    for(ll i=2;i<=tmp/i;i++)
        if(tmp%i==0)
        {
            v.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp!=1)
    {
        v.push_back(tmp);
    }
    ll g=1;
    while(true)
    {
        if(g_test(g,p))
            return g;
        ++g;
    }
}
int p,a,b;
int pw[MAXN],id[MAXN],bb[MAXN];
int main()
{
    scanf("%d%d%d",&p,&a,&b);
    int g=primitive_root(p),ga=0,gb=0;
    pw[0]=1;
    id[1]=0;
    for(int i=1;i<=p-2;i++) 
    {
        pw[i]=1LL*pw[i-1]*g%p;
        id[pw[i]]=i;
        if(pw[i]==a) ga=i;
        if(pw[i]==b) gb=i;
    }
    if(ga>gb) {swap(a,b); swap(ga,gb);}
    if(ga==0)
    {
        if(p==2)
        {
            puts("Yes");
            printf("%d %d\n",1,1);
            return 0;
        }
        if(gb==0) {puts("No"); return 0;}
        if(__gcd(gb,p-1)!=1) {puts("No"); return 0;}
        puts("Yes");
        int now=1;
        for(int i=1;i<=p-1;i++)
        {
            printf("%d ",now);
            now=1LL*now*b%p;
        }  
        printf("%d\n",1);
        return 0;
    }
    if(__gcd(p-1,ga)==1)
    {
        puts("Yes");
        int now=1;
        for(int i=1;i<=p-1;i++)
        {
            printf("%d ",now);
            now=1LL*now*a%p;
        }  
        printf("%d\n",1);
        return 0;
    }
    if(__gcd(p-1,__gcd(ga,gb))!=1) {puts("No"); return 0;}
    puts("Yes");
    int now=1,period=(p-1)/__gcd(p-1,ga),layers=(p-1)/period;
    int inva=pow_mod(a,p-2,p),invb=pow_mod(b,p-2,p);
    printf("%d ",now);
    for(int i=1;i<=layers-1;i++) 
    {
        now=1LL*now*b%p;
        printf("%d ",now);
    }
    for(int i=layers;i>=2;i--)
    {
        int num=(i==layers?period-1:period-2);
        for(int j=1;j<=num;j++) 
        {
            if(i&1) now=1LL*now*a%p; else now=1LL*now*inva%p;
            printf("%d ",now);
        }
        now=1LL*now*invb%p;
        printf("%d ",now);
    }
    assert(1LL*now*inva%p==1);
    for(int j=1;j<=period-1;j++) 
    {
        now=1LL*now*a%p;
        printf("%d ",now);
    }
    return 0;
}