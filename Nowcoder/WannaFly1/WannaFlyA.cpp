#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
long long cnt1,cnt2;
vector<int> G[MAXN];
int dep[MAXN],p[MAXN];
int cnt[MAXN];
bool used[MAXN];
void dfs(int x,int d)
{
    used[x]=true;
    dep[x]=d;
    if(d&1) cnt1++; else cnt2++;
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfs(G[x][i],d+1);
    return;
}
int main()
{
    scanf("%d",&n);
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(used,false,sizeof(used));
    dfs(1,0);
    printf("%I64d\n",cnt1*(cnt1-1)/2+cnt2*(cnt2-1)/2);
    return 0;
}
