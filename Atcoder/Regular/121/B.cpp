#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<ll> r,g,b;
string str;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        ll x;
        scanf("%lld",&x);
        cin>>str;
        if(str=="R") r.push_back(x);
        else if(str=="G") g.push_back(x);
        else b.push_back(x);
    }
    if(r.size()%2==0&&g.size()%2==0&&b.size()%2==0) {puts("0"); return 0;}
    if(r.size()%2==0) swap(r,b);
    if(g.size()%2==0) swap(g,b);
    ll ans=INF;
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    ll mini1=INF,mini2=INF;
    for(auto x:r)
    {
        if(g.back()<x) ans=min(ans,x-g.back());
        else
        {
            int id=lower_bound(g.begin(),g.end(),x)-g.begin();
            ans=min(ans,g[id]-x);
            if(id!=0)
            {
                id--;
                ans=min(ans,x-g[id]);
            }
        }
        if(b.size())
        {
            if(b.back()<x) mini1=min(mini1,x-b.back());
            else
            {
                int id=lower_bound(b.begin(),b.end(),x)-b.begin();
                mini1=min(mini1,b[id]-x);
                if(id!=0)
                {
                    id--;
                    mini1=min(mini1,x-b[id]);
                }
            }
        }
    }
    for(auto x:g)
    {
        if(b.size())
        {
            if(b.back()<x) mini2=min(mini2,x-b.back());
            else
            {
                int id=lower_bound(b.begin(),b.end(),x)-b.begin();
                mini2=min(mini2,b[id]-x);
                if(id!=0)
                {
                    id--;
                    mini2=min(mini2,x-b[id]);
                }
            }
        }
    }
    printf("%lld\n",min(ans,mini1+mini2));
    return 0;
}