#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 805
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
int H,W,K;
char str[MAXN][MAXN];
int d[MAXN][MAXN];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int get_up(int x)
{
    return (x+K-1)/K;
}
int find_ans(int x,int y)
{
    int ret=INF;
    ret=min(ret,get_up(x-1));
    ret=min(ret,get_up(H-x));
    ret=min(ret,get_up(W-y));
    ret=min(ret,get_up(y-1));
    return ret;
}
int main()
{
    scanf("%d%d%d",&H,&W,&K);
    for(int i=1;i<=H;i++) scanf("%s",str[i]+1);
    int x=0,y=0;
    for(int i=1;i<=H;i++)
        for(int j=1;j<=W;j++)
        {
            if(str[i][j]=='S')
            {
                x=i;y=j;
                break;
            }
        }
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) d[i][j]=INF;
    queue<P> que;
    que.push(P(x,y)); d[x][y]=0;
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        if(d[x][y]==K) continue;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=H&&ny>=1&&ny<=W&&d[nx][ny]>d[x][y]+1&&str[nx][ny]!='#')
            {
                d[nx][ny]=d[x][y]+1;
                que.push(P(nx,ny));
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=H;i++)
        for(int j=1;j<=W;j++)
            if(d[i][j]!=INF)
                ans=min(ans,1+find_ans(i,j));
    printf("%d\n",ans);
    return 0;
}

