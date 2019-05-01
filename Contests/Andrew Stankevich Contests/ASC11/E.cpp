#include<bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s;
int p[MAXN],r[MAXN],sz[MAXN];
bool vis[MAXN];
int dx[6]={-1,-1,0,1,1,0};
int dy[6]={1,0,-1,0,1,1};
int dz[6]={0,-1,-1,-1,0,1};
struct op
{
    int x,y,szx,isadd,dummy;
};
vector<op> vec;
vector<int> ans;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return find(p[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    op res; res.dummy=0;
    if(x==y)
    {
        res.dummy=1;
        vec.push_back(res);
        return;
    }
    res.x=x; res.y=y;
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x]; res.szx=sz[x]; res.isadd=0;}
    else
    {
        swap(res.x,res.y);
        p[y]=x; sz[x]+=sz[y]; res.szx=sz[y];
        if(r[x]==r[y]) {r[x]++; res.isadd=1;} else res.isadd=0;
    }
    vec.push_back(res);
}
void rollback()
{
    op res=vec.back();
    if(res.dummy) {vec.pop_back(); return;}
    int x=res.x,y=res.y;
    p[x]=x; sz[y]-=res.szx; sz[x]=res.szx;
    if(res.isadd) r[y]--;
    vec.pop_back();
}
int find_id(int x,int y)
{
    return (x+500)*1001+(y+500)+1;
}
int main()
{
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    scanf("%d%d",&n,&s);
    init(1200000);
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(vis[find_id(x,y)]) continue;
        vis[find_id(x,y)]=true; sz[find_id(x,y)]=1;
        for(int j=0;j<6;j++)
        {
            int nx=x+dx[j],ny=y+(x&1?dy[j]:dz[j]);
            if(nx>500||nx<-500||ny>500||ny<-500||!vis[find_id(nx,ny)]) continue;
            unite(find_id(x,y),find_id(nx,ny));
        }
        if(sz[find(find_id(x,y))]>s)
        {
            for(int j=5;j>=0;j--)
            {
                int nx=x+dx[j],ny=y+(x&1?dy[j]:dz[j]);
                if(nx>500||nx<-500||ny>500||ny<-500||!vis[find_id(nx,ny)]) continue;
                rollback();
            }
            vis[find_id(x,y)]=false;
            sz[find_id(x,y)]=0;
        }
    }
    for(int i=1;i<=1200000;i++)
        if(vis[i]&&find(i)==i) ans.push_back(sz[i]);
    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}
