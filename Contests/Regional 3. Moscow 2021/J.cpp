#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 105
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,s;
double dp[MAXK][MAXN];
int f[MAXN][MAXN];
vector<double> p[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++) {scanf("%d",&f[i][j]); s+=f[i][j];}
        int q;
        scanf("%d",&q);
        for(int j=0;j<s;j++)
        {
            int x;
            scanf("%d",&x);
            p[i].push_back(((double)x)/q);
        }
        sort(p[i].begin(),p[i].end(),greater<double>());
    }
    for(int i=0;i<=k;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=0.0;
    dp[0][s]=1.0;
    for(int i=1;i<=k;i++)
    {
        vector<pair<double,int> > tmp;
        for(int j=1;j<=n;j++) tmp.push_back(make_pair(dp[i-1][j],j));
        sort(tmp.begin(),tmp.end(),greater<pair<double,int> >());
        for(int j=1;j<=n;j++)
        {
            int now=0;
            for(int k=0;k<n;k++)
            {
                int id=tmp[k].S;
                double prob=0.0;
                for(int l=now;l<now+f[j][id];l++) prob+=p[j][l];
                now+=f[j][id];
                dp[i][j]+=prob*dp[i-1][id];
            }
        }
    }
    printf("%.15Lf\n",dp[k][1]);
    return 0;
}