#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
vector<ll> v;
ll cnt[MAXN],ans[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    v.push_back(n);
    for(int i=1;i<=q;i++)
    {
        ll x;
        scanf("%lld",&x);
        while(v.size()&&v.back()>=x) v.pop_back();
        v.push_back(x);
    }
    int sz=(int)v.size();
    cnt[sz-1]=1;
    for(int i=sz-1;i>=1;i--)
    {
        if(cnt[i]==0) continue;
        ll len=v[i];
        while(len>=v[0])
        {
            int id=upper_bound(v.begin(),v.begin()+i,len)-v.begin()-1;
            cnt[id]+=len/v[id]*cnt[i]; len-=v[id]*(len/v[id]);
        }
        ans[len]+=cnt[i];
    }
    for(int i=n;i>=1;i--) ans[i]+=ans[i+1];
    for(int i=1;i<=n;i++) if(i<=v[0]) ans[i]+=cnt[0];
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}