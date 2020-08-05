#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,pool[MAXN][MAXN];
int deq[MAXN];
int x[MAXN][MAXN];
int gcd(int a,int b)
{
    if(a==0) return b;
    if(pool[a][b]!=-1) return pool[a][b];
    return pool[a][b]=gcd(b%a,a);
}
int main()
{
    memset(pool,-1,sizeof(pool));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            gcd(i,j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pool[i][j]=i*j/pool[i][j];
    for(int i=1;i<=n;i++)
    {
        int s=0,t=0;
        for(int j=1;j<=m;j++)
        {
            while(s<t&&pool[i][deq[t-1]]<=pool[i][j]) t--;
            deq[t++]=j;
            if(j>=k)
            {
                x[i][j-k+1]=pool[i][deq[s]];
                if(deq[s]==j-k+1)
                {
                    s++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-k+1;j++)
            pool[i][j]=x[i][j];
    for(int i=1;i<=m-k+1;i++)
    {
        int s=0,t=0;
        for(int j=1;j<=n;j++)
        {
            while(s<t&&pool[deq[t-1]][i]<=pool[j][i]) t--;
            deq[t++]=j;
            if(j>=k)
            {
                x[j-k+1][i]=pool[deq[s]][i];
                if(deq[s]==j-k+1)
                {
                    s++;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n-k+1;i++)
        for(int j=1;j<=m-k+1;j++)
            ans+=x[i][j];
    printf("%lld\n",ans);
    return 0;
}
