#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<P> s;
int n,r,deg[MAXN];
vector<int> groups[MAXN];
int main()
{
    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);
    scanf("%d%d",&n,&r);
    int mod=n%(r-1),sz=n/(r-1);
    int now=1,tot=0;
    for(int i=0;i<mod;i++)
    {
        tot++;
        for(int j=now;j<=now+sz;j++)
            groups[tot].push_back(j);
        now+=sz+1;
    }
    for(int i=0;i<r-1-mod;i++)
    {
        tot++;
        for(int j=now;j<=now+sz-1;j++)
            groups[tot].push_back(j);
        now+=sz;
    }
    int ans=0;
    for(int i=1;i<=tot;i++)
        for(int j=i+1;j<=tot;j++)
            ans+=groups[i].size()*groups[j].size();
    printf("%d\n",ans);
    for(int i=1;i<=tot;i++)
        for(int j=i+1;j<=tot;j++)
        {
            for(int id1=0;id1<(int)groups[i].size();id1++)
                for(int id2=0;id2<(int)groups[j].size();id2++)
                    printf("%d %d\n",groups[i][id1],groups[j][id2]);
        }
    return 0;
}
