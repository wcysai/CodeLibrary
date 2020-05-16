#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 2000000009
#define MOD 2000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,a[MAXN],b[MAXN],ans;
bool matched[MAXN];
vector<int> G[MAXN],rG[MAXN];
int deg[MAXN];
vector<int> dis;
int get_pos(int id,int dir,int t)
{
    if(dir==0)
    {
        if(a[id]>t) return a[id]-t;
        return t-(a[id]-1);
    }
    else
    {
        if(l-a[id]>=t) return a[id]+t;
        return l-(t-1-(l-a[id]));
    }
}
P get_time(int x,int y,int dir)
{
    if(a[x]>=b[y])
    {
        if(dir==0) return P(a[x]-b[y],a[x]+b[y]-1);
        else return P(l-a[x]+1+(l-b[y]),2*(l+1)-(a[x]-b[y]));
    }
    else
    {
        if(dir==0) return P(a[x]+b[y]-1,2*(l+1)-(b[y]-a[x]));
        else return P(b[y]-a[x],l-a[x]+1+(l-b[y]));
    }  
}
int get_id(int pos)
{
    int x=lower_bound(b+1,b+n+1,pos)-b;
    if(b[x]!=pos) return -1; else return x;
}
void solve(int t)
{
    for(int i=1;i<=n;i++) G[i].clear(),rG[i].clear(),deg[i]=0,matched[i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int dir=0;dir<2;dir++)
        {
            int pos=get_pos(i,dir,t);
            int id=get_id(pos);
            if(id!=-1) {G[i].push_back(id); rG[id].push_back(i); deg[i]++;}
        }
    }
    for(int i=1;i<=n;i++) if(deg[i]==0) return;
    queue<int> que;
    for(int i=1;i<=n;i++) if(deg[i]==1) que.push(i);
    while(que.size())
    {
        int v=que.front(); que.pop();
        int u=-1;
        for(auto to:G[v]) if(!matched[to]) {u=to; break;}
        if(u==-1) return;
        matched[u]=true;
        for(auto to:rG[u])
        {
            deg[to]--;
            if(deg[to]==1) que.push(to);
        }
    }
    ans=min(ans,t);
}
int main()
{
    scanf("%d%d",&l,&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    ans=INF;
    for(int dir=0;dir<=1;dir++)
    {
        for(int i=1;i<=n;i++)
        {
            P p=get_time(1,i,dir);
            dis.push_back(p.F); dis.push_back(p.S);
        }
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(auto x:dis) solve(x);
    if(ans!=INF) printf("%d\n",ans); else puts("-1");
    return 0;
}