#include<bits/stdc++.h>
#define MAXN 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int N,K,Q;
vector<edge> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],deep[MAXN],d[MAXN],ans[MAXN];
int query[MAXN];
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p)//enumerate path
{
    deep[++deep[0]]=d[v];
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        d[to]=d[v]+G[v][i].cost;
        getdeep(to,v);
    }
}
void cal(int v,int cost,int sgn)
{
    d[v]=cost;deep[0]=0;
    getdeep(v,0);
    sort(deep+1,deep+deep[0]+1);
    for(int i=0;i<Q;i++)
    {
        for(int l=1;l<=deep[0];l++)
        {
            if(deep[l]*2>query[i]) break;
            int id1=lower_bound(deep+l+1,deep+deep[0]+1,query[i]-deep[l])-deep;
            int id2=upper_bound(deep+l+1,deep+deep[0]+1,query[i]-deep[l])-deep;
            //if(i==0&&id2!=id1) printf("add%d %d\n",v,deep[l]);
            ans[i]+=(id2-id1)*sgn;
        }
    }
}
void solve(int v)
{
    //printf("%d\n",v);
    cal(v,0,1);
    centroid[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(centroid[to]) continue;
        cal(to,cost,-1);
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void ac()
{
    int rt=getroot(1,0,N).S;
    solve(rt);
    for(int i=0;i<Q;i++)
    {
        printf("%d ",ans[i]);
        if(ans[i]) puts("Yes"); else puts("No");
    }
}
int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N-1;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back((edge){y,z});
        G[y].push_back((edge){x,z});
    }
    memset(centroid,false,sizeof(centroid));
    for(int i=0;i<Q;i++)
        scanf("%d",&query[i]);
    ac();
    return 0;
}


