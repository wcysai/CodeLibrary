#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
string s[]=
{
    "I",
    "II",
    "III",
    "V",
    "X",
    "XX",
    "XXX",
    "L",
    "C",
    "CC",
    "CCC",
    "M",
    "MM",
    "MMM",
    "D",
    "MCM",
    "CXC",
    "XIX",
};
int dp[MAXN],pre[MAXN];
vector<string> v;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<=n;i++) dp[i]=INF;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<18;j++)
        {
            if(s[j].size()>i) continue;
            if(str.substr(i-s[j].size(),s[j].size())==s[j]&&dp[i-s[j].size()]+1<dp[i])
            {
                dp[i]=dp[i-s[j].size()]+1;
                pre[i]=j;
            }
        }
    }
    int now=n;
    while(now)
    {
        v.push_back(s[pre[now]]);
        now-=s[pre[now]].size();
    }
    reverse(v.begin(),v.end());
    printf("%d\n",(int)v.size());
    for(auto t:v) cout<<t<<endl;
    return 0;
}