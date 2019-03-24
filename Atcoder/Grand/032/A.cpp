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
int n,a[MAXN];
void del(int x)
{
    for(int i=x+1;i<=n;i++) a[i-1]=a[i];
}
vector<int> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int id=-1;
        for(int j=n-i+1;j>=1;j--)
        {
            if(a[j]==j)
            {
                id=j;
                break;
            }
        }
        if(id==-1) 
        {
            puts("-1");
            return 0;
        }
        ans.push_back(a[id]);
        del(id);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) printf("%d\n",x);
    return 0;
}

