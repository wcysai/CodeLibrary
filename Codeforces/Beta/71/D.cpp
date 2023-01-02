#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define MAXL 105
#define MAXK 25
#define INF 100000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l;
int c[MAXN];
int a[MAXL];
int d[MAXN];
int dis[MAXK][MAXK];
int dp[(1<<20)];
vector<int> v;
void bfs(int s){
    for(int i=1;i<=n+1;i++) d[i]=INF;
    d[s]=0;
    queue<int> que; que.push(s);
    while(que.size()){
        int u=que.front(); que.pop();
        for(int j=1;j<=l;j++){
            if(u+a[j]<=n+1&&d[u+a[j]]==INF){
                d[u+a[j]]=d[u]+1;
                que.push(u+a[j]);
            }
            if(u-a[j]>=1&&d[u-a[j]]==INF){
                d[u-a[j]]=d[u]+1;
                que.push(u-a[j]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&k,&l);
    for(int i=0;i<k;i++){
        int x; scanf("%d",&x);
        c[x]=1;
    }
    for(int i=1;i<=n+1;i++){
        if(c[i]!=c[i-1]) v.push_back(i);
    }
    int sz=(int)v.size();
    for(int i=1;i<=l;i++) scanf("%d",&a[i]);
    for(int i=0;i<sz;i++){
        bfs(v[i]); 
        for(int j=0;j<sz;j++) dis[i][j]=d[v[j]];
    }
    for(int mask=0;mask<(1<<sz);mask++) dp[mask]=INF;
    dp[(1<<sz)-1]=0;
    for(int mask=(1<<sz)-2;mask>=0;mask--){
        if(__builtin_popcount(mask)&1) continue;
        int id=-1;
        for(int j=0;j<sz;j++) if(!(mask&(1<<j))) {id=j; break;}
        for(int j=id+1;j<sz;j++) if(!(mask&(1<<j))) dp[mask]=min(dp[mask],dp[mask^(1<<j)^(1<<id)]+dis[id][j]); 
    }
    if(dp[0]>=INF) puts("-1"); else printf("%d\n",dp[0]);
    return 0;
}

