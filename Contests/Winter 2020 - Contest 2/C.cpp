#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define MAXM 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],c[MAXN];
vector<int> disa,disb,disc;
ll dp[MAXN][MAXN][MAXN];
vector<int> ta[MAXN],tb[MAXN],tc[MAXN];
void upd(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        disa.push_back(a[i]); disb.push_back(b[i]); disc.push_back(c[i]);
    }
    sort(disa.begin(),disa.end()); sort(disb.begin(),disb.end()); sort(disc.begin(),disc.end());
    disa.erase(unique(disa.begin(),disa.end()),disa.end());
    disb.erase(unique(disb.begin(),disb.end()),disb.end());
    disc.erase(unique(disc.begin(),disc.end()),disc.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(disa.begin(),disa.end(),a[i])-disa.begin();
        b[i]=lower_bound(disb.begin(),disb.end(),b[i])-disb.begin();
        c[i]=lower_bound(disc.begin(),disc.end(),c[i])-disc.begin();
        ta[a[i]].push_back(i); tb[b[i]].push_back(i); tc[c[i]].push_back(i);
    }
    int sza=(int)disa.size(),szb=(int)disb.size(),szc=(int)disc.size();
    for(int i=0;i<sza;i++)
        for(int j=0;j<szb;j++)
            for(int k=0;k<szc;k++)
                dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for(int i=0;i<sza;i++)
        for(int j=0;j<szb;j++)
            for(int k=0;k<szc;k++)
            {
                if(dp[i][j][k]==INF) continue;
                if(i!=sza-1)
                {
                    ll cont=0;
                    for(auto x:ta[i+1])
                    {
                        if(b[x]<=j&&c[x]<=k)
                        {
                            cont+=disb[j]-disb[b[x]];
                            cont+=disc[k]-disc[c[x]];
                        }
                    }
                    upd(dp[i+1][j][k],dp[i][j][k]+cont);
                }
                if(j!=szb-1)
                {
                    ll cont=0;
                    for(auto x:tb[j+1])
                    {
                        if(a[x]<=i&&c[x]<=k)
                        {
                            cont+=disa[i]-disa[a[x]];
                            cont+=disc[k]-disc[c[x]];
                        }
                    }
                    upd(dp[i][j+1][k],dp[i][j][k]+cont);
                }
                if(k!=szc-1)
                {
                    ll cont=0;
                    for(auto x:tc[k+1])
                    {
                        if(a[x]<=i&&b[x]<=j)
                        {
                            cont+=disa[i]-disa[a[x]];
                            cont+=disb[j]-disb[b[x]];
                        }
                    }
                    upd(dp[i][j][k+1],dp[i][j][k]+cont);
                }
            }
    printf("%lld\n",dp[sza-1][szb-1][szc-1]);
    return 0;
}