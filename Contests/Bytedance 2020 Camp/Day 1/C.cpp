
int n,p[MAXN],r[MAXN],cnt[MAXN];
int maxi,cur;
ll ans;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        cnt[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) 
    {
        p[x]=y;
        cnt[y]+=cnt[x]+1;
        maxi=max(maxi,cnt[y]);
    }
    else
    {
        p[y]=x;
        cnt[x]+=cnt[y]+1;
        maxi=max(maxi,cnt[x]);
        if(r[x]==r[y]) r[x]++;
    }
    ans=max(ans,1LL*maxi*cur);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
struct edge
{
    int u,v,cost;
};
bool cmp(edge x,edge y)
{
    return x.cost>y.cost;
}
vector<edge> vv;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        vv.push_back((edge){u,v,c});
    }
    init(n);
    sort(vv.begin(),vv.end(),cmp);
    for(auto e:vv)
    {
        cur=e.cost;
        unite(e.u,e.v);
    }
    printf("%lld\n",ans);
    return 0;
}