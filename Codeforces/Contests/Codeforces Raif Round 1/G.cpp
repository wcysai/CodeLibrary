#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int k,q,f[6];
int dp[MAXN],ndp[MAXN],tmp1[MAXN],tmp2[MAXN];
void solve(int n,int v)
{
    memset(ndp,0,sizeof(ndp));
    for(int i=0;i<=n;i++)
    {
        tmp1[i]=dp[i]-10*i*(v/3);
        tmp2[i]=
    }
    for(int i=1;i<=10*n;i++)
    {
        int r=i/10,l=max(0,(i-9*k+9)/10);
        for(int j=0;j<2;j++)
        {
            if((i-10*j)%3==0)
            {

            }
        }
    }
}
int main()
{
    scanf("%d",&k);
    for(int i=0;i<6;i++) scanf("%d",&f[i]);
    scanf("%d",&q);
}