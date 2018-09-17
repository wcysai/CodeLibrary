/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-15 21:38:38
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
int n,k,a[MAXN],l[MAXN],r[MAXN];
vector<int> v,G[MAXN];
int bit[MAXN+1];
int dp[MAXN][2];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int calc(int from,int to)
{
    if(from<=to) return sum(to)-sum(from-1);
    else return sum(from)-sum(to-1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    int sz=(int)v.size();
    for(int i=1;i<=sz;i++) l[i]=INF,r[i]=-INF;
    for(int i=1;i<=n;i++) 
    {
        l[a[i]]=min(l[a[i]],i);
        r[a[i]]=max(r[a[i]],i);
        G[a[i]].push_back(i);
    }
    l[0]=r[0]=1;
    for(int i=1;i<=n;i++) add(i,1);
    for(int i=1;i<=sz;i++) dp[i][0]=dp[i][1]=INF;
    for(int i=1;i<=sz;i++)
    {
        int x=calc(l[i],r[i]);
        for(int j=0;j<(int)G[i].size();j++) printf("%d ",G[i][j]);
        puts("");
        for(int j=0;j<(int)G[i].size();j++) add(G[i][j],-1);
        dp[i][0]=min(dp[i][0],dp[i-1][0]+calc(l[i-1],r[i])+x);
        dp[i][0]=min(dp[i][0],dp[i-1][1]+calc(r[i-1],r[i])+x);
        dp[i][1]=min(dp[i][1],dp[i-1][0]+calc(l[i-1],l[i])+x);
        dp[i][1]=min(dp[i][1],dp[i-1][1]+calc(r[i-1],l[i])+x);
    }
    for(int i=0;i<=sz;i++) printf("%d %d\n",dp[i][0],dp[i][1]);
    printf("%d\n",min(dp[sz][0],dp[sz][1]));
    return 0;
}

