/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 22:55:42
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
int n,m;
priority_queue<int> s[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        s[x].push(y);
    }
    for(int i=1;i<=m;i++)
    {
        int tot=0,sum=0;
        while(s[i].size())
        {
            sum+=s[i].top();s[i].pop();
            if(sum>0) ans[++tot]+=sum; else break;
        }
    }
    int ANS=0;
    for(int i=1;i<=n;i++) ANS=max(ANS,ans[i]);
    printf("%d\n",ANS);
    return 0;
}

