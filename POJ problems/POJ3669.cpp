#include<cmath>
#include<algorithm>
#include<queue>
#define INF 50005
#define MAXN 303
using namespace std;
struct meteor
{
    int x,y;
    int t;
};
bool cmp(meteor m,meteor n)
{
    return m.t<n.t;
}
int d[MAXN][MAXN],map[MAXN][MAXN];
int main()
{
queue <meteor> que;
meteor str[INF];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int m;
scanf("%d",&m);
for(int i=0;i<m;i++)
    scanf("%d %d %d",&str[i].x,&str[i].y,&str[i].t);
for(int i=0;i<MAXN;i++)
  for(int j=0;j<MAXN;j++)
    d[i][j]=INF;
for(int i=0;i<MAXN;i++)
  for(int j=0;j<MAXN;j++)
    map[i][j]=INF;
sort(str,str+m,cmp);
for(int k=m-1;k>=0;k--)
 {
     map[str[k].x][str[k].y]=str[k].t;
        map[str[k].x+1][str[k].y]=str[k].t;
        map[str[k].x][str[k].y+1]=str[k].t;
        if(str[k].x>0) map[str[k].x-1][str[k].y]=str[k].t;
        if(str[k].y>0) map[str[k].x][str[k].y-1]=str[k].t;
 }
 if(map[0][0]==0)
 {
     printf("-1");
     return 0;
 }
int maxi=str[m-1].t;
meteor l;
l.x=0;
l.y=0;
l.t=0;
que.push(l);
d[0][0]=0;
int k=0;
while(que.size())
{
    meteor p=que.front();
    que.pop();
    if(p.t>maxi) break;
    if(d[p.x][p.y]==-1) continue;
    for(int i=0;i<4;i++)
      {
         int nx=p.x+dx[i],ny=p.y+dy[i],nt=p.t+1;
         if(nx>=0&&ny>=0&&nx<MAXN&&ny<MAXN&&d[nx][ny]==INF&&nt<map[nx][ny])
         {
             {
                l.x=nx;
                l.y=ny;
                l.t=nt;
                que.push(l);
                d[nx][ny]=d[p.x][p.y]+1;
             }
         }
      }
}
int mini=INF+1;
for(int i=0;i<MAXN;i++)
  for(int j=0;j<MAXN;j++)
    if(d[i][j]>=0&&map[i][j]==INF) mini=min(mini,d[i][j]);
if(mini==INF) printf("-1"); else printf("%d",mini);
return 0;
}
