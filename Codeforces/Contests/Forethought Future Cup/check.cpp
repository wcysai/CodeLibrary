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
int n,a,b;
bool vis[MAXN];
int solve(int x)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    queue<int> que;
    que.push(0);
    while(que.size())
    {
        int v=que.front(); que.pop();
        if(v-b>=0&&!vis[v-b]) {vis[v-b]=true; ans++; que.push(v-b);}
        if(v+a<=x&&!vis[v+a]) {vis[v+a]=true; ans++; que.push(v+a);}
    }
    return ans;
}
int main()
{
    scanf("%d%d",&a,&b);
    for(int i=1;i<=100;i++)
    {
        printf("%d %d\n",i,solve(i));
    }
    return 0;
}

