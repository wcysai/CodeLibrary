#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN],d[MAXN];
ll H;
ll f[2*MAXN][2*MAXN];
ll g[4*MAXN*MAXN],ng[4*MAXN*MAXN];
ll val[2*MAXN];
void upd(ll &a,ll b) {a=max(a,b);}
int main()
{
    scanf("%d%lld",&n,&H);
    for(int i=1;i<=n;i++) {scanf("%d%d",&c[i],&d[i]); c[i]=-c[i];}
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for(int i=0;i<=600;i++){
        for(int j=0;j<=600;j++){
            if(f[i][j]==-1) continue;
            val[i]=max(val[i],f[i][j]);
            for(int k=1;k<=n;k++)
                if(j+c[k]>=0&&j+c[k]<=600) upd(f[i+1][j+c[k]],f[i][j]+d[k]);
        }
    }
    int id=0; 
    for(int i=1;i<=600;i++) if(id==0||(val[id]*i<val[i]*id)) id=i;
    memset(g,-1,sizeof(g));
    g[0]=0;
    for(int i=1;i<=600;i++)
        for(int j=0;j<=600*i;j++)
            if(j>=i&&g[j-i]!=-1) g[j]=max(g[j],g[j-i]+val[i]);
    ll ans=INF;
    for(int i=0;i<=600*600;i++){
        if(g[i]>=H) ans=min(ans,1LL*i);
        else ans=min(ans,i+((H-g[i]+val[id]-1)/(val[id]))*id);
    }
    printf("%lld\n",ans);
    return 0;
}

