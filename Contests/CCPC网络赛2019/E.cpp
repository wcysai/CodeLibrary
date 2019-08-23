#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define INV2 500000004
#define INV6 166666668
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a,b;
bool is_prime[MAXN];
int f[MAXN],prime[MAXN],g[MAXN];
map<int,int> mp;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int get_sum(int x)
{
	return 1LL*x*(x+1)%MOD*(2*x+1)%MOD*INV6%MOD;
}
int get_sum(int l,int r)
{
    int ret=1LL*r*(r+1)%MOD*INV2%MOD;
    dec(ret,1LL*(l-1)*l%MOD*INV2%MOD);
    return ret;
}
void genphi(ll n)
{
    ll p=0;
    memset(f,0,sizeof(f));
    f[1]=1;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; f[i]=1LL*i*(i-1)%MOD;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            f[i*prime[j]]=1LL*f[i]*prime[j]%MOD*(i%prime[j]?prime[j]-1:prime[j])%MOD;
            if(i%prime[j]==0) break;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        g[i]=g[i-1];
        add(g[i],f[i]);
    }
}
int calc(int x)
{
	if(x<=1000000) return g[x];
	if(mp.find(x)!=mp.end()) return mp[x];
	int ans=get_sum(x);
	for(int i=2,r;i<=x;i=r+1)
	{
		r=x/(x/i);
		dec(ans,1LL*calc(x/i)*get_sum(i,r)%MOD);
	}
	return mp[x]=ans;
}
int main()
{
    genphi(1000000);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a,&b);
        int ans=calc(n); dec(ans,1);
        ans=1LL*ans*INV2%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
