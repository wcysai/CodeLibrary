#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int sum[MAXN],dp[MAXN];
vector<int> pos[3],rep;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='a') sum[i]=(sum[i-1]+1)%3; else sum[i]=(sum[i-1]+2)%3;
        pos[sum[i]].push_back(i);
        if(i<n&&str[i]==str[i+1]) rep.push_back(i);
    }
    if(!rep.size())
    {
        puts("1");
        return 0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        add(dp[i+1],dp[i]);
        auto it=lower_bound(rep.begin(),rep.end(),i+1);
        if(it==rep.end()) continue;
        int p=*it+1;
        for(int k=1;k<=2;k++)
        {
            if(k==1&&str[i+1]=='a') continue;
            if(k==2&&str[i+1]=='b') continue;
            int s=(sum[i]+k)%3;
            it=lower_bound(pos[s].begin(),pos[s].end(),p);
            if(it==pos[s].end()) continue;
            add(dp[*it],dp[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(sum[i]==sum[n]) add(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}

