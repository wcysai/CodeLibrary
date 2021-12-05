#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<P> v,ans;
set<int> x,y;
int deg[MAXN];
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
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
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=2*n;i++) deg[i]=0;
        v.clear(); x.clear(); y.clear(); ans.clear();
        init(2*n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            deg[a]++; deg[n+b]++;
            unite(a,n+b);
        }
        printf("%d\n",2*n-m);
        for(int i=1;i<=n;i++)
        {
            while(deg[i]<2)
            {
                for(int j=1;j<=n;j++)
                {
                    if((i==n&&deg[n+j]==1)||(deg[n+j]<2&&!same(i,n+j)))
                    {
                        deg[i]++; deg[n+j]++;
                        ans.push_back(P(i,j));
                        unite(i,n+j);
                        break;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}