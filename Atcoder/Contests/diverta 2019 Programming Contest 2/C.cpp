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
int n,k,a[MAXN];
bool rev[MAXN];
vector<int> pos,neg;
vector<P> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[1]>=0) 
    {
        neg.push_back(a[1]);
        for(int i=2;i<=n;i++) pos.push_back(a[i]);
    }
    else if(a[n]<=0)
    {
        pos.push_back(a[n]);
        for(int i=1;i<=n-1;i++) neg.push_back(a[i]);
    }
    else
    {
        for(int i=1;i<=n;i++) if(a[i]<=0) neg.push_back(a[i]); else pos.push_back(a[i]);
    }
    while(neg.size()>1)
    {
        int x=pos.back(),y=neg.back();
        ans.push_back(P(x,y));
        pos.pop_back(); neg.pop_back();
        pos.push_back(x-y);
    }
    while(pos.size()>1)
    {
        int x=pos.back(),y=neg.back();
        ans.push_back(P(y,x));
        pos.pop_back(); neg.pop_back();
        neg.push_back(y-x);
    }
    printf("%d\n",pos.back()-neg.back());
    ans.push_back(P(pos.back(),neg.back()));
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}

