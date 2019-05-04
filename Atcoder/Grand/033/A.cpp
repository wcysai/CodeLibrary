#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
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
int n,m;
char mp[MAXN][MAXN];
int d[MAXN][MAXN];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=INF;
    queue<P> que;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='#')
            {
                d[i][j]=0;
                que.push(P(i,j));
            }
    int ans=0;
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||d[nx][ny]!=INF) continue;
            d[nx][ny]=d[x][y]+1; que.push(P(nx,ny));
            ans=max(ans,d[nx][ny]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

