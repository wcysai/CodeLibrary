#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,tot,deg[MAXN],a[MAXN],r[MAXN],cnt[MAXN];
int save[MAXM];
vector<int> G[MAXN],gr[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
bool cmp(int x,int y)
{
    return deg[x]<deg[y];
}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&T);
    int inv24=pow_mod(24,MOD-2);
    while(T--)
    {
        tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) deg[i]=cnt[i]=0;
        for(int i=1;i<=m;i++) save[i]=0;
        for(int i=1;i<=n;i++) G[i].clear(),gr[i].clear();
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) r[a[i]]=i;
        for(int i=1;i<=n;i++)
            for(auto to:G[i])
                if(r[to]>r[i]) gr[i].push_back(to);
        int ans=1LL*m*(n+m-3)%MOD;
        for(int i=1;i<=n;i++) add(ans,(1LL*deg[i]*(deg[i]-1)/2)%MOD);
        int x=0;
        for(int i=1;i<=n;i++)
        {
            for(auto u:gr[i]) cnt[u]=1;
            for(auto u:gr[i])
                for(auto to:gr[u]) 
                    if(cnt[to]) 
                        add(ans,3);
            for(auto u:gr[i]) cnt[u]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(auto u:G[i]) 
            {
                for(auto to:gr[u])
                {
                    if(r[to]>r[i])
                    {
                        add(ans,cnt[to]);
                        cnt[to]++;
                    }
                }
            }
            for(auto u:G[i])
                for(auto to:gr[u])
                    if(r[to]>r[i]) cnt[to]--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
