#include<bits/stdc++.h>
#define MAXN 1005
#define MAXD 205
#define MAXT 30
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int d,k,t,n;
string str[MAXD];
map<string,int> mp;
int go[MAXD][MAXT];
db pr[MAXN][MAXT];
db dp[MAXN][MAXD];
int last[MAXN][MAXD];
int main()
{
    freopen("decoding.in","r",stdin);
    freopen("decoding.out","w",stdout);
    scanf("%d%d%d",&d,&k,&t);
    for(int i=0;i<d;i++) 
    {
        cin>>str[i];
        mp[str[i]]=i;
    }
    memset(go,-1,sizeof(go));
    for(int i=0;i<d;i++)
    {
        string tmp=str[i].substr(1);
        for(int j=0;j<t;j++)
        {
            tmp+=(char)('a'+j);
            if(mp.find(tmp)!=mp.end()) go[i][j]=mp[tmp];
            tmp.pop_back();
        }
    }
   /* for(int i=0;i<d;i++)
    {
        for(int j=0;j<t;j++)
            printf("%d ",go[i][j]);
        puts("");
    }
    */
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<t;j++)
            scanf("%Lf",&pr[i][j]);
    for(int i=0;i<d;i++)
    {
        dp[k-1][i]=1.0;
        for(int j=0;j<k;j++) dp[k-1][i]*=pr[j][str[i][j]-'a'];
    }
    for(int i=k-1;i<n-1;i++)
    {
        for(int j=0;j<d;j++)
        {
            for(int ii=0;ii<t;ii++)
            {
                if(go[j][ii]==-1) continue;
                int to=go[j][ii];
                if(dp[i+1][to]<dp[i][j]*pr[i+1][ii])
                {
                    dp[i+1][to]=dp[i][j]*pr[i+1][ii];
                    last[i+1][to]=j;
                }
            }
        }
    }
    db ans=0.0;
    int id=-1;
    for(int i=0;i<d;i++)
    {
        if(dp[n-1][i]>ans)
        {
            ans=dp[n-1][i];
            id=i;
        }
    }
    if(ans<=0) {puts("---"); return 0;}
    int cur=n-1;
    string res;
    while(cur>k-1)
    {
        res=str[id].back()+res;
        id=last[cur][id];
        cur--;
    }
    res=str[id]+res;
    cout<<res<<endl;
    return 0;
}
