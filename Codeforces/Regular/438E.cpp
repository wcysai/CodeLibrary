#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
struct edge
{
    int to,len,id;
};
int dp[MAXN][MAXN][MAXN];
int n,m,s;
vector<int> G[MAXN];
int a[MAXN];
int main()
{
    G.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        G[x].push_back((edge){y,z,2*i});
        G[y].push_back((edge){x,z,2*i+1});
    }
    scanf("%d",&s);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);

}
