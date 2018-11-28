/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 22:45:02
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
int n,sum[MAXN],minx[MAXN],maxx[MAXN];
char str[MAXN];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1];
        if(str[i]=='S') sum[i]++; else cnt++;
    }
    for(int i=1;i<=n;i++) minx[i]=INF,maxx[i]=-INF;
    for(int i=1;i<=n;i++)
    {
        minx[sum[i]]=min(minx[sum[i]],i);
        maxx[sum[i]]=max(maxx[sum[i]],i);
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(maxx[i]==-INF) break;
        //printf("%d %d %d\n",i,minx[i],maxx[i]);
        ans=max(ans,maxx[i]-minx[i]);
        if(i>0) ans=max(ans,maxx[i]-minx[i-1]);
    }
    printf("%d\n",min(cnt,ans));
    return 0;
}

