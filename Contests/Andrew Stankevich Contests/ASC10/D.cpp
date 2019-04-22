#include<bits/stdc++.h>
#define MAXN 100005
#define INF 10000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
int prime[MAXN];
bool is_prime[MAXN];
vector<P> ans,tmp;
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    int p=sieve(100);
    ans.push_back(P(1,1));
    for(int i=0;i<p;i++)
    {
        int sz=(int)ans.size();
        for(int j=0;j<sz;j++)
        {
            ll cur=ans[j].F;
            for(int k=1;;k++)
            {
                cur=cur*prime[i];
                if(cur>INF) break;
                ans.push_back(make_pair(cur,ans[j].S*(k+1)));
            }
        }
        //for(auto x:ans) printf("%lld ",x.F);
        //puts("");
        sort(ans.begin(),ans.end());
        tmp.clear();
        for(int i=0;i<(int)ans.size();i++)
        {
            if(tmp.size()==0||tmp.back().S<ans[i].S) tmp.push_back(ans[i]);
        }
        ans=tmp;
        assert(ans[0].F==1);
    }
    scanf("%lld",&n);
    int id=upper_bound(ans.begin(),ans.end(),make_pair(n,INF))-ans.begin();
    printf("%lld\n",ans[id-1].F);
    return 0;
}
