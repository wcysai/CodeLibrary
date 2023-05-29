#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXM 505
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN];
bitset<5000> bs[MAXN];
P a[MAXN];
vector<int> order;
int color[MAXN];
ll dp[MAXN];
void dfs_visit(int v){
    color[v]=1;
    for(int to=bs[v]._Find_first();to<n;to=bs[v]._Find_next(to)){
        if(!color[to]) dfs_visit(to);
    }
    color[v]=2;
    order.push_back(v);
}
void topo(){
    for(int i=0;i<n;i++) if(!color[i]) dfs_visit(i);
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j) bs[i].set(j);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[j].S=j; scanf("%d",&a[j].F);
        }
        sort(a+1,a+n+1);
        vector<int> tmp;
        bitset<5000> b;
        for(int j=1;j<=n;j++){
            tmp.push_back(a[j].S);
            if(j==n||a[j].F!=a[j+1].F){
                for(auto x:tmp) bs[x-1]&=b;
                for(auto x:tmp) b.set(x-1);
                tmp.clear();
            }
        }
    }
   /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(bs[i].test(j)) printf("1"); else printf("0");
        puts("");
    }*/
    topo();
    //reverse(order.begin(),order.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        int v=order[i];
        //printf("v=%d\n",v);
        dp[v]=max(dp[v],1LL*p[v+1]);
        for(int to=bs[v]._Find_first();to<n;to=bs[v]._Find_next(to))
            dp[v]=max(dp[v],p[v+1]+dp[to]);
        ans=max(ans,dp[v]);
    }
    printf("%lld\n",ans);
    return 0;
}

