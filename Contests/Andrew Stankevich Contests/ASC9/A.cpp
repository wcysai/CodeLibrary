#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],q[MAXN];
const int steps=32;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
map<P,int> dis;
set<P> vis;
vector<P> path[MAXN];
bool done[MAXN];
void print(int x,int y)
{
    while(x%2==0&&y%2==0) x/=2,y/=2;
    printf("%d/%d ",x,y);
}
int main()
{
    freopen("chip.in","r",stdin);
    freopen("chip.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]),p[i]--;
    for(int i=0;i<n;i++) q[p[i]]=i;
    for(int i=0;i<n;i++)
    {
        path[i].push_back(P(i*steps,0));
        path[i].push_back(P(i*steps,-(i+1)));
        path[i].push_back(P(-steps-i,-(i+1)));
        path[i].push_back(P(-steps-i,(i+1)));
    }
    memset(done,false,sizeof(done));
    for(int i=0;i<n;i++)
    {
        int x=q[i];
        path[x].push_back(P(i*steps,(x+1)));
        path[x].push_back(P(i*steps,steps));
        done[x]=true;
        for(int j=0;j<x;j++)
        {
            if(done[j]) continue;
            path[j].push_back(P(i*steps,(j+1)));
        }
        int cnt=0;
        for(int j=x+1;j<n;j++)
        {
            if(done[j]) continue;
            cnt++;
            path[j].push_back(P(i*steps-cnt,(j+1)));
            path[j].push_back(P(i*steps-cnt,steps+cnt));
            path[j].push_back(P(i*steps+cnt,steps+cnt));
            path[j].push_back(P(i*steps+cnt,(j+1)));
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",(int)path[i].size()-1);
        for(int j=0;j<(int)path[i].size();j++) 
        {
            print(path[i][j].F,steps);
            print(path[i][j].S,steps);
            printf("\n");
        }
    }
    return 0;
}
