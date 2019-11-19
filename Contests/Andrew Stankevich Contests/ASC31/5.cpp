#include<bits/stdc++.h>
#define MAXN 205
#define MAXK 55
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
bool lose[MAXM];
string str[MAXN];
int sid[MAXN][MAXK][MAXK];
map<string,int> id;
string save[MAXM];
set<string> v;
vector<char> ans;
vector<int> G[MAXM];
int get_id(string str)
{
    if(id.find(str)==id.end())
    {
        id[str]=++tot;
        save[tot]=str;
    }
    return id[str];
}
int find_id(string str)
{
    if(id.find(str)==id.end()) return -1;
    return id[str];
}
int dp[MAXM];
int solve(int id)
{
    if(lose[id]) return 1;
    if(dp[id]!=-1) return dp[id];
    dp[id]=0;
    for(auto to:G[id]) if(!solve(to)) return dp[id]=1;

    return dp[id];
}
int main()
{
    //freopen("game.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    memset(lose,false,sizeof(lose));
    for(int len=1;len<=50;len++)
    {
        for(int i=0;i<n;i++)
        {
            int sz=(int)str[i].size();
            for(int st=0;st+len<=sz;st++)
            {
                string t=str[i].substr(st,len);
                int id=get_id(t);
                if(len==sz) lose[id]=true;
                if(len==1) v.insert(t);
                sid[i][st][st+len-1]=id;
                if(len>1)
                {
                    int to=sid[i][st+1][st+len-1];
                    G[to].push_back(id);
                    to=sid[i][st][st+len-2];
                    G[to].push_back(id);
                }
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    for(auto t:v)
        if(!solve(find_id(t))) ans.push_back(t[0]);
    if(ans.size())
    {
        puts("First");
        for(auto ch:ans) printf("%c",ch);
        puts("");
    }
    else puts("Second");
    return 0;
}
