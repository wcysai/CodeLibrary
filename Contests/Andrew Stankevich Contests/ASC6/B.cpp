#include<bits/stdc++.h>
#define MAXN 50
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
set<P> s;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
queue<P> que;
bool hanging(P p)
{
    if(!s.count(P(p.F-1,p.S))&&!s.count(P(p.F,p.S-1))&&!s.count(P(p.F-1,p.S-1))) return false;
    if(!s.count(P(p.F+1,p.S))&&!s.count(P(p.F,p.S+1))&&!s.count(P(p.F+1,p.S+1))) return false; 
    if(!s.count(P(p.F-1,p.S))&&!s.count(P(p.F,p.S+1))&&!s.count(P(p.F-1,p.S+1))) return false; 
    if(!s.count(P(p.F+1,p.S))&&!s.count(P(p.F,p.S-1))&&!s.count(P(p.F+1,p.S-1))) return false;
    return true;
}
int main()
{
    freopen("control.in","r",stdin);
    freopen("control.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,z; 
        scanf("%d%d%d",&x,&y,&z); z++;
        for(int j=y-z;j<=y+z;j++) s.insert(P(x,j));
        for(int j=x-1;j>=x-z;j--)
            for(int k=y-z+((x-1)-j);k<=y+z-((x-1)-j);k++)
                s.insert(P(j,k));
        for(int j=x+1;j<=x+z;j++)
            for(int k=y-z+(j-(x+1));k<=y+z-(j-(x+1));k++)
                s.insert(P(j,k));
    }
    for(auto x:s) que.push(x);
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.F+dx[i],ny=p.S+dy[i];
            if(s.count(P(nx,ny))) continue;
            if(!hanging(P(nx,ny))) continue;
            s.insert(P(nx,ny));
            que.push(P(nx,ny));
        }
    }
    printf("%d\n",(int)s.size());
    return 0;
}
