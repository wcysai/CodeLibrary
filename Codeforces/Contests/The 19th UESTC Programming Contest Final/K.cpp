#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d;
bool vis[MAXN];
int dist[MAXN];
vector<int> v[MAXN];
int ans[MAXN];
int ask(int u,int v)
{
    printf("? %d %d\n",u,v);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer()
{
    printf("! %d",d+1);
    for(int i=0;i<=d;i++) printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
}
int main()
{
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    vis[1]=vis[n]=true;
    d=ask(1,n);
    ans[0]=1; ans[d]=n;
    for(int i=2;i<=n-1;i++) 
    {
        dist[i]=ask(1,i);
        if(dist[i]!=-1) v[dist[i]].push_back(i);
    }
    for(int i=d-1;i>0;i--)
    {
        for(auto x:v[i])
        {
            if(ask(x,ans[i+1])==1)
            {
                ans[i]=x;
                break;
            }
        }
    }
    answer();
    return 0;
}