/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 16:52:21
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,A,B;
vector<int> G[MAXN];
int dp1[MAXN],dp2[MAXN],ans[MAXN],fa[MAXN];
void dfs1(int v,int p)
{
    dp1[v]=1;fa[v]=p;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v);dp1[v]=max(dp1[v],dp1[to]+1);
    }
}
void dfs2(int v,int p)
{
    int mx1=0,mx2=0,id=-1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dp2[to]=dp2[v]+1;
        if(dp1[to]>mx1) {mx2=mx1; mx1=dp1[to]; id=to;}
        else if(dp1[to]>mx2) {mx2=dp1[to];}
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        if(to==id) dp2[to]=max(dp2[to],mx2+2);
        else dp2[to]=max(dp2[to],mx1+2);
    }
    for(int i=0;i<(int)G[v].size();i++) 
    {
        int to=G[v][i];if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d%d%d",&N,&A,&B);
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs1(1,0);dp2[1]=1;dfs2(1,0);
    /*for(int i=1;i<=N;i++) printf("%d ",dp1[i]);
    puts("");
    for(int i=1;i<=N;i++) printf("%d ",dp2[i]);
    puts("");*/
    for(int i=1;i<=N;i++)
    {
        vector<int> v;v.clear();
        for(int j=0;j<(int)G[i].size();j++)
        {
            int to=G[i][j];if(to==fa[i]) continue;
            v.push_back(dp1[to]);
        }
        if(fa[i]!=0) v.push_back(dp2[i]-1);
        sort(v.begin(),v.end());
        int cnt=0;
        for(int j=(int)v.size()-1;j>=0;j--)
        {
            cnt++;
            ans[cnt]=max(ans[cnt],v[j]);
        }
    }
    for(int i=A;i<=B;i++)
    {
        int l=0,r=N;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(ans[mid]>=i) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}

