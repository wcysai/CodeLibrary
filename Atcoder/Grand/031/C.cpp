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
int n,a,b,dummy;
vector<int> ans;
void solve(int n,int to,int cur)
{
    if(n==1)
    {
        ans.push_back(cur);
        ans.push_back(to^cur);
        return;
    }
    if(to&(1<<(n-1)))
    {
        solve(n-1,1,cur);
        solve(n-1,(to^(1<<(n-1)))^1,cur^(1<<(n-1))^1);
        return;
    }
    int swapped=-1;
    for(int i=0;i<n;i++)
    {
        if(to&(1<<i))
        {
            swapped=i;
            to^=(1<<(n-1));
            to^=(1<<i);
            solve(n-1,1,cur);
            solve(n-1,(to^(1<<(n-1)))+1,cur^(1<<(n-1))^1);
            break;
        }
    }
    assert(swapped!=-1);
    int sz=(int)ans.size();
    vector<int> dif;
    dif.clear();
    for(int i=sz-1;i>sz-(1<<n);i--) 
    {
        int d=ans[i]^(ans[i-1]);
        dif.push_back(d);
    }
    reverse(dif.begin(),dif.end());
    for(int i=sz-(1<<n)+1;i<sz;i++)
    {
        int id=i-(sz-(1<<n)+1);
        if(dif[id]==(1<<swapped)) ans[i]=ans[i-1]^(1<<(n-1));
        else if(dif[id]==(1<<(n-1))) ans[i]=ans[i-1]^(1<<(swapped));
        else ans[i]=ans[i-1]^dif[id];
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    dummy=a;b^=a;a=0;
    if(__builtin_popcount(b)%2==0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    solve(n,b,dummy);
    for(auto v:ans) printf("%d ",v);
    return 0;
}

