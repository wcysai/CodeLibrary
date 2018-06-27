#include<bits/stdc++.h>
#define  MAXN 505
using namespace std;
int t,n,k;
int par[MAXN],id[MAXN];
vector<int> tree[MAXN];
void add(int x)
{
    if(par[x]==x) return;
    tree[par[x]][id[x]]++;
    add(par[x]);
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&k);
        for(int j=1;j<=n;j++)
            tree[j].clear();
        par[1]=1;
        for(int j=2;j<=n;j++)
        {
            scanf("%d",&par[j]);
            tree[par[j]].push_back(1);
            id[j]=tree[par[j]].size()-1;
            add(par[j]);
        }
        int f=1;
        for(int j=1;j<=n;j++)
        {
            int cnt=0,s=0;
            for(int p=0;p<tree[j].size();p++)
            {
                if(tree[j][p]%2==1) cnt++;
                s+=tree[j][p];
            }
            if((n-s-1)%2==1) cnt++;
            if(cnt!=1){ puts("Alice"); f=0; break;}
        }
        if(f) if (k>=n/2-1) puts("Bob"); else puts("Alice");
    }
    return 0;
}
