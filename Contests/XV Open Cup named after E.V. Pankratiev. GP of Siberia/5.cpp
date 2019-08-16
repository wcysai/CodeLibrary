#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<500> bs;
int n,a,b,c;
int w[MAXN],h[MAXN];
bs G[MAXN];
bs tmp;
bool valid[305][305];
bs used;
int ans,x,y,z;
void dfs(int v)
{
    if(used[v]) return;
    used.set(v);
    bs vis=(~used)&G[v];
    while(vis.any())
    {
        int i=vis._Find_first();
        dfs(i);
        vis=(~used)&G[v];
    }
}
bool check(int x,int y)
{
    if(w[0]<x||h[0]<y||w[n-1]<x||h[n-1]<y) return false;
    used.reset();
    for(int i=0;i<n;i++) if(w[i]>=x&&h[i]>=y) used[i]=0; else used[i]=1;
    dfs(0);
    if(used[n-1]) return true; else return false;
}
void update_answer(int i,int j,int k)
{
    int tmpi=i,tmpj=j,tmpk=k;
    if(i>j) swap(i,j); if(i>k) swap(i,k); if(j>k) swap(j,k);
    if(i>a||j>b||k>c) return;
    if(i*j*k>ans)
    {
        ans=i*j*k;
        x=tmpi; y=tmpj; z=tmpk;
    }
}
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a>b) swap(a,b); if(a>c) swap(a,c); if(b>c) swap(b,c);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&w[i],&h[i]);
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int to;
            scanf("%d",&to);
            G[i].set(to-1);
        }
    }
    memset(valid,false,sizeof(valid));
    for(int i=1;i<=300;i++)
    {
        int l=0,r=301;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(i,mid)) l=mid; else r=mid;
        }
        for(int j=1;j<=l;j++) valid[i][j]=true;
    }
    ans=0; x=y=z=-1;
    for(int i=1;i<=300;i++)
        for(int j=1;j<=300;j++)
        {
            if(valid[i][j])
            {
                update_answer(a,i,j);
                update_answer(b,i,j);
                update_answer(c,i,j);
            }
        }
    printf("%d %d %d\n",x,y,z);
    return 0;
}
