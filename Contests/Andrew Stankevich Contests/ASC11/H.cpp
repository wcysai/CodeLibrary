#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h,s,p,m;
int a[MAXN],b[MAXN],c[MAXN];
int dp[MAXN][MAXN][MAXN],choice[MAXN][MAXN][MAXN];
//dp[i][j][k]
//maximum health point if
//current killed i monsters while
//battled j of them
//with current mana k
void update(int &a,int b) {a=max(a,b);}
int main()
{
    freopen("princess.in","r",stdin);
    freopen("princess.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&h,&s,&p,&m);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    dp[0][0][m]=h;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(!dp[i][j][k]) continue;
                int strength=s+j,spell=p+(i-j);
                if(strength>=a[i+1])
                {
                    int damage=max(2*a[i+1]-strength,0);
                    if(dp[i+1][j+1][k]<dp[i][j][k]-damage)
                    {
                        dp[i+1][j+1][k]=dp[i][j][k]-damage;
                        choice[i+1][j+1][k]=0;
                    }
                }
                if(spell>=b[i+1]&&k>=c[i+1]) 
                {
                    if(dp[i+1][j][k-c[i+1]]<dp[i][j][k])
                    {
                        dp[i+1][j][k-c[i+1]]=dp[i][j][k];
                        choice[i+1][j][k-c[i+1]]=1;
                    }
                }
            }
        }
    }
    int battled=-1,mana=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(dp[n][i][j]>0)
            {
                battled=i;
                mana=j;
                break;
            }
        }
    if(battled==-1) {cout<<"UNLUCKY"<<endl; return 0;}
    string ans="";
    int cur=n;
    while(cur)
    {
        char ch=choice[cur][battled][mana]?'E':'D';
        ans=ch+ans;
        if(ch=='E') mana+=c[cur]; else battled--;
        cur--;
    }
    cout<<ans<<endl;
}
