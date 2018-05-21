#include<bits/stdc++.h>
#define MAXN 100005
#define MAXX 11
using namespace std;
vector<int> G[MAXN];
int n,m,k,x;
int dp[MAXX][2][MAXN];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
