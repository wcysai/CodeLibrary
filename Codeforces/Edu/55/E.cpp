/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 23:24:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c,a[MAXN];
vector<int> occ[MAXN];
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        occ[a[i]].push_back(i);
    }
    int ans=(int)occ[c].size(),cnt=(int)occ[c].size();
    for(int i=1;i<=500000;i++)
    {
        if(i==c) continue;
        if(!occ[i].size()) continue;
        int now=1;
        ans=max(ans,cnt+1);
        for(int j=1;j<(int)occ[i].size();j++)
        {
            int num=lower_bound(occ[c].begin(),occ[c].end(),occ[i][j])-lower_bound(occ[c].begin(),occ[c].end(),occ[i][j-1]);
            now+=(1-num);
            if(now<1) now=1;
            ans=max(ans,cnt+now);
        }
    }
    printf("%d\n",ans);
    return 0;
}

