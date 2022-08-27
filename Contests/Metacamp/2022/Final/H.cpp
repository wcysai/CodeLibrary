#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][4][4];
int nxtpos[MAXN][4];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int cur,int pre,int suf)
{
    if(a[cur]==pre) return solve(cur,0,suf);
    if(dp[cur][pre][suf]!=-1) return dp[cur][pre][suf];
    vector<int> v;
    if(pre) v.push_back(pre);
    v.push_back(a[cur]);
    if(suf) v.push_back(suf);
    if(cur==n)
    {
        if(v.size()<=2) return 1;
        if(v[0]==v[2]) return 2; else return 1;
    }
    int player=(pre?pre:a[cur]);
    int res=0;
    if(player==suf)
    {
        //must happen pre=suf
        //dont move
        add(res,solve(cur,0,suf));
        //move
        add(res,solve(cur,pre,0));
        return dp[cur][pre][suf]=res;
    }
    int pos=nxtpos[cur+1][player];
    if(pos==n+1)
    {
        if(pre) add(res,solve(cur,0,suf));
        else if(suf) add(res,solve(cur+1,suf,0));
        else add(res,solve(cur+1,0,0));
        return dp[cur][pre][suf]=res;
    }
    int cnt=0,nxt=-1;
    for(int i=1;i<=3;i++)
    {
        if(i==player) continue;
        bool f=false;
        for(int j=1;j<(int)v.size();j++) if(v[j]==i) f=true;
        if(nxtpos[cur][i]<pos) f=true;
        if(f) {cnt++; nxt=i;}
    }
    if(cnt==0)
    {
        if(pre) add(res,solve(cur,0,suf));
        else if(suf) add(res,solve(cur+1,suf,0));
        else add(res,solve(cur+1,0,0));
        return dp[cur][pre][suf]=res;
    }
    else if(cnt==1)
    {
        //dont move
        if(pre) add(res,solve(cur,0,suf));
        else if(suf) add(res,solve(cur+1,suf,0));
        else add(res,solve(cur+1,0,0));
        //move
        add(res,solve(pos,0,nxt));
        return dp[cur][pre][suf]=res;
    }
    else
    {
        add(res,solve(pos,nxt,6-player-nxt));
        add(res,solve(pos,6-player-nxt,nxt));
        return dp[cur][pre][suf]=res;
    }
}
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=1;i<=n;i++)
        a[i]=(str[i-1]=='M'?1:(str[i-1]=='E'?2:3));
    nxtpos[n+1][1]=nxtpos[n+1][2]=nxtpos[n+1][3]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=3;j++) nxtpos[i][j]=nxtpos[i+1][j];
        nxtpos[i][a[i]]=i;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,0,0));
    return 0;
}

