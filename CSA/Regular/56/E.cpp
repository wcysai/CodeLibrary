#include<bits/stdc++.h>
#define MAXN 100030
#define INF 1000000000
#define INF2 100000000
using namespace std;
int t,n,a,b;
vector<int> G[MAXN];
int disa[MAXN],disb[MAXN];
int dist;
bool used[MAXN];
void dfsb(int x,int dis)
{
    disb[x]=dis;
    if(x==a)
    {
        dist=dis;
        return;
    }
    used[x]=true;
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfsb(G[x][i],dis+1);
}
void dfsa(int x,int dis)
{
    disa[x]=dis;
    if(x==b) return;
    used[x]=true;
    if(disb[x]!=INF&&disa[x]<=disb[x]) disb[x]=INF2;
    else if(disb[x]!=INF) disa[x]=INF2;
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfsa(G[x][i],dis+1);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++)
            G[i].clear();
        fill(disa+1,disa+1+n,INF);
        fill(disb+1,disb+1+n,INF);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        dfsb(b,0);
        memset(used,false,sizeof(used));
        dfsa(a,0);
        int maxa,maxb;
        maxa=maxb=0;
        int dista,distb;
        dista=distb=0;
        for(int i=1;i<=n;i++)
        {
            if(disa[i]==INF2) distb=max(distb,disb[i]);
            if(disb[i]==INF2) dista=max(dista,disa[i]);
            if(disa[i]==INF&&disb[i]<INF2) maxb=max(maxb,disb[i]);
            if(disb[i]==INF&&disa[i]<INF2) maxa=max(maxa,disa[i]);
        }
        if(dista>distb)
        {
            if(maxa>max(distb,maxb)||dista>maxb) printf("A\n"); else printf("B\n");
        }
        else if(maxa>max(distb,maxb)) printf("A\n"); else printf("B\n");
    }
    return 0;
}
