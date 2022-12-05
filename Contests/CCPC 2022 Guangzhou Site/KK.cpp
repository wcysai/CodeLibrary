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
vector<P> G[MAXN];
vector<P> gr[MAXN];
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
            ++tot;
            G[u].push_back(P(v,tot)); G[v].push_back(P(u,tot));
            deg[u]++; deg[v]++;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) r[a[i]]=i;
        for(int i=1;i<=n;i++)
            for(auto e:G[i])
                if(r[e.F]>r[i]) gr[i].push_back(e);

        int ans=1LL*m*(n+m-3)%MOD;
        for(int i=1;i<=n;i++) add(ans,(1LL*deg[i]*(deg[i]-1)/2)%MOD);
        int x=0;
        for(int i=1;i<=n;i++)
        {
            for(auto e:gr[i]) cnt[e.F]=e.S;
            for(auto e:gr[i])
                for(auto ee:gr[e.F]) 
                    if(cnt[ee.F]) 
                    {
                        printf("cycle %d %d %d %d %d %d\n",i,e.F,ee.F,cnt[ee.F],e.S,ee.S);
                        add(ans,3);
                        save[cnt[ee.F]]++;
                        save[e.S]++;
                        save[ee.S]++;
                    }
            for(auto e:gr[i]) cnt[e.F]=0;
        }
        for(int i=1;i<=m;i++) printf("%d %d\n",i,save[i]);
        for(int i=1;i<=m;i++) add(ans,(1LL*save[i]*(save[i]-1)/2)%MOD);
        printf("%d\n",ans);
    }
    return 0;
}
