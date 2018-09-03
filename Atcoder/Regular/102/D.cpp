/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 12:20:11
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
int n,m,L;
struct edge{int u,v,cost;};
vector<edge> ans;
int main()
{
    scanf("%d",&L);
    int t=1;n=1;
    while(t*2<=L) t*=2,n++;
    for(int i=1;i<n;i++)
    {
        ans.push_back((edge){i,i+1,1<<(i-1)});
        ans.push_back((edge){i,i+1,0});
    }
    int cur=t;
    for(int i=n-1;i>=1;i--)
    {
        if((cur+(1<<(i-1)))<=L)
        {
            ans.push_back((edge){i,n,cur});
            cur+=(1<<(i-1));
        }
    }
    printf("%d %d\n",n,(int)ans.size());
    for(int i=0;i<(int)ans.size();i++)
        printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].cost);
    return 0;
}

