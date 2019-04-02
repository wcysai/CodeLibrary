#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define MAXM 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
char str[MAXN];
unordered_map<char,int> mp;
int w[MAXN][MAXN];
int dp[MAXM][MAXM];
int last[MAXM][MAXM];
char ch[MAXM][MAXM];
char a[MAXM],b[MAXM];
pair<int,char> minva[MAXN],minvb[MAXN];
vector<char> s,t;
int main()
{
    freopen("dissim.in","r",stdin);
    freopen("dissim.out","w",stdout);
    scanf("%s",str+1);
    n=strlen(str+1);
    for(ll i=1;i<=n;i++) mp[str[i]]=i;
    scanf("%s",a+1);
    scanf("%s",b+1);
    m=strlen(a+1);
    k=strlen(b+1);
    for(ll i=1;i<=n;i++) minva[i]=minvb[i]=make_pair(INF,'a');
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        {
            scanf("%d",&w[i][j]);
            minva[i]=min(minva[i],make_pair(w[i][j],str[j]));
            minvb[j]=min(minvb[j],make_pair(w[i][j],str[i]));
        }
    for(ll i=0;i<=m;i++)
        for(ll j=0;j<=k;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(ll i=0;i<=m;i++)
        for(ll j=0;j<=k;j++)
        {
            if(i<m&&j<k) 
            {
                if(dp[i+1][j+1]>dp[i][j]+w[mp[a[i+1]]][mp[b[j+1]]])
                {
                    dp[i+1][j+1]=dp[i][j]+w[mp[a[i+1]]][mp[b[j+1]]];
                    last[i+1][j+1]=1;
                }
            }
            if(i<m) 
            {
                if(dp[i+1][j]>dp[i][j]+minva[mp[a[i+1]]].F)
                {
                    dp[i+1][j]=dp[i][j]+minva[mp[a[i+1]]].F;
                    last[i+1][j]=2;
                    ch[i+1][j]=minva[mp[a[i+1]]].S;
                }
            }
            if(j<k) 
            {
                if(dp[i][j+1]>dp[i][j]+minvb[mp[b[j+1]]].F)
                {
                    dp[i][j+1]=dp[i][j]+minvb[mp[b[j+1]]].F;
                    last[i][j+1]=3;
                    ch[i][j+1]=minvb[mp[b[j+1]]].S;
                }
            }
        }
    printf("%d\n",dp[m][k]);
    ll i=m,j=k;
    while(i>0||j>0)
    {
        ll x=last[i][j];
        if(x==1)
        {
            s.push_back(a[i]);
            t.push_back(b[j]);
            i--;j--;
        }
        else if(x==2)
        {
            s.push_back(a[i]);
            t.push_back(ch[i][j]);
            i--;
        }
        else
        {
            s.push_back(ch[i][j]);
            t.push_back(b[j]);
            j--;
        }
    }
    reverse(s.begin(),s.end()); reverse(t.begin(),t.end());
    for(auto x:s) printf("%c",x);
    puts("");
    for(auto x:t) printf("%c",x);
    return 0;
}
