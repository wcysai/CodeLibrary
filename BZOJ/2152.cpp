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
int N,K;
vector<edge> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],d[MAXN],cnt[3];
int ans;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
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
    cnt[d[v]%3]++;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        d[to]=d[v]+G[v][i].cost;
        getdeep(to,v);
    }
}
int cal(int v,int cost)
{
    d[v]=cost;cnt[0]=cnt[1]=cnt[2]=0;
    getdeep(v,0);
    return 2*cnt[1]*cnt[2]+cnt[0]*cnt[0];
}
void solve(int v)
{
    ans+=cal(v,0);
    centroid[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(centroid[to]) continue;
        ans-=cal(to,cost);
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void ac()
{
    ans=0;
    int rt=getroot(1,0,N).S;
    solve(rt);
    int q=N*N,g=gcd(ans,q);
    ans/=g;q/=g;
    printf("%d/%d\n",ans,q);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N-1;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back((edge){y,z});
        G[y].push_back((edge){x,z});
    }
    ac();
    return 0;
}

