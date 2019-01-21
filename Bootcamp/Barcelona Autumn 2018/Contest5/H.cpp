/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 19:34:04
 ************************************************************************/

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
int R,F,dp[MAXN];
int solve(int x)
{
    if(dp[x]!=-1) return dp[x];
    if(x<F) return dp[x]=0;
    int m=(int)sqrt(x)+1;
    set<int> s;
    for(int i=2;i<=m;i++)
    {
        int l=x/i,r=(x-1)/i+1;
        if(l==r)
        {
            int cnt=x/l;
            if(cnt&1) s.insert(solve(l));
        }
        else
        {
            int cntr=x-i*l,cntl=i-cntr;
            int cur=0;
            if(cntl&1) cur^=solve(l);
            if(cntr&1) cur^=solve(r);
            s.insert(cur);
        }
    }
    for(int i=m;i>=F;i--)
    {
        int cur=x/i,r=x%i,cur2=1;
        int need=(i-1)-r;cur-=need,cur2+=need;
        for(int j=0;j<4;j++)
        {
            if(cur<0||cur2<0) break;
            int res=0;
            if(cur&1) res^=solve(i);
            if(cur2&1) res^=solve(i-1);
            s.insert(res);
            cur-=(i-1);cur2+=i;
        }
    }
    for(int g=1;;g++) if(!s.count(g)) {return dp[x]=g;}
    assert(0);//should not reach here
}
int main()
{
    scanf("%d%d",&R,&F);
    memset(dp,-1,sizeof(dp));
    //for(int i=1;i<=100;i++) printf("%d %d\n",i,solve(i));
    for(int i=0;i<R;i++)
    {
        int cnt,s=0;
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++) 
        {
            int x;
            scanf("%d",&x);s^=solve(x);
        }
        if(s==0) printf("0"); else printf("1");
        if(i==R-1) printf("\n"); else printf(" ");
    }
    return 0;
}

