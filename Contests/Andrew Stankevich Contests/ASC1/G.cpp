#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n;
struct node
{
    int b,s,id;
};
node a[MAXN];
vector<int> x,y;
bool cmp(node p,node q)
{
    if(p.b!=q.b) return p.b<q.b;
    return p.s>q.s;
}
int dp[MAXN],pos[MAXN];
vector<node> save[MAXN];
vector<int> choice;
int main()
{
    freopen("people.in","r",stdin);
    freopen("people.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&a[i].b,&a[i].s);
        a[i].id=i;;
        x.push_back(a[i].b); y.push_back(a[i].s);
    }
    sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end());
    sort(y.begin(),y.end());y.erase(unique(y.begin(),y.end()),y.end());
    for(int i=1;i<=n;i++)
    {
        a[i].b=lower_bound(x.begin(),x.end(),a[i].b)-x.begin()+1;
        a[i].s=lower_bound(y.begin(),y.end(),a[i].s)-y.begin()+1;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) save[a[i].b].push_back(a[i]);
    fill(dp,dp+n,INF);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!save[i].size()) continue;
        vector<P> tmp; tmp.clear();
        for(auto p:save[i])
        {
            pos[++cnt]=lower_bound(dp,dp+n,p.s)-dp;
            tmp.emplace_back(pos[cnt],p.s);
        }
        for(auto entry:tmp) dp[entry.F]=entry.S;
    }
    int ans=lower_bound(dp,dp+n,INF)-dp;
    printf("%d\n",ans);
    int last=INF;
    for(int i=n;i>=1;i--)
    {
        if(ans==0) break;
        if(pos[i]==ans-1&&a[i].s<last)
        {
            last=a[i].s;
            ans--;
            choice.push_back(a[i].id);
        }
    }
    sort(choice.begin(),choice.end());
    for(auto x:choice) printf("%d ",x);
    return 0;
}

