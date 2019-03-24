#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 255
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
int T,R,C;
char str[MAXN][MAXN];
char valid[MAXN][MAXN];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int d[MAXN][MAXN];
bool check(int dis)
{
    queue<P> que;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            if(str[i][j]=='1')
            {
                d[i][j]=0;
                que.push(P(i,j));
            }
            else d[i][j]=INF;
        }
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=R&&ny>=1&&ny<=C&&d[nx][ny]==INF)
            {
                d[nx][ny]=d[x][y]+1;
                que.push(P(nx,ny));
            }
        }
    }
    int lx=R+C,rx=0,ly=R,ry=-C;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            if(d[i][j]>dis)
            {
                lx=min(lx,i+j); rx=max(rx,i+j);
                ly=min(ly,i-j); ry=max(ry,i-j);
            }
        }
    if(2*dis==rx-lx&&2*dis==ry-ly)
    {
        int xx=(lx+rx)/2,yy=(ly+ry)/2;
        if((xx+yy)&1) return false; else return true;
    }
    if(2*dis>=rx-lx&&2*dis>=ry-ly) return true;
    return false;
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&R,&C);
        for(int i=1;i<=R;i++) scanf("%s",str[i]+1);
        int l=-1,r=max(R,C);
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("Case #%d: %d\n",t,r);
    }
    return 0;
}

