#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef pair<int,int> P;
int n,k;
vector<int> G[MAXN];
vector<P> ans;
int pt[MAXN];
int main()
{
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt+=x;
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            G[i].push_back(y);
        }
    }
    cnt/=2;

    int popped=0;
    memset(pt,0,sizeof(pt));
    while(popped<cnt)
    {
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(G[i].size()==pt[i]) continue;
            int j=G[i][pt[i]];
            if(G[j].size()==pt[j]) break;
            while (G[j][pt[j]]==i)
            {
                ans.push_back(P(i,G[i][pt[i]]));
                flag=true;
                pt[i]++;
                pt[j]++;
                popped++;
                if(pt[i]!=G[i].size()) j=G[i][pt[i]]; else break;
            }
        }
        if(!flag)
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}

