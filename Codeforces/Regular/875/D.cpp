#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXK 245
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],wt[MAXN];
vector<int> G[MAXN];
vector<int> dp[MAXN];
const int thr=450;
void upd(int &a,int b) {a=min(a,b);}
vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> c;
    int sza=((int)a.size()-1)/2,szb=((int)b.size()-1)/2;
    int szc=min(sza+szb,thr);
    c.resize(2*szc+1);
    for(int i=0;i<(int)c.size();i++) c[i]=INF;
    for(int i=-min(sza,thr);i<=min(sza,thr);i++){
            if(i==0) continue;
            int x=a[i+sza]; if(x==INF) continue;
            for(int j=-min(szb,thr);j<=min(szb,thr);j++){
                if(j==0) continue;
                int y=b[j+szb]; if(y==INF) continue;
                if(i*j>0){
                    if(i+j<-thr||i+j>thr) continue;
                    upd(c[i+j+szc],x+y+(max(-i,i)*max(-j,j))*(i<0?1:2));
                }
                else{
                    upd(c[i+szc],x+y);
                }
            }
    }
    return c;
}
int cnt;
void dfs(int v,int p){
    dp[v].clear();
    dp[v].resize(3); dp[v][0]=2*wt[v]-1; dp[v][1]=INF; dp[v][2]=wt[v]+1;
    for(auto to:G[v]){
        if(to==p) continue;
        if(!wt[to]) continue;
        dfs(to,v);
        dp[v]=merge(dp[v],dp[to]);
    }
    for(auto to:G[v]){
        if(to==p) continue;
        if(!wt[to]) continue;
        dp[to].clear(); dp[to].shrink_to_fit();
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        cnt=0;
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        if(n==1){
            printf("%d\n",1); continue;
        }
        if(n==2){
            printf("%d\n",3); continue;
        }
        for(int i=1;i<=n;i++) wt[i]=1;
        for(int i=1;i<=n;i++){
            if((int)G[i].size()==1){
                wt[i]=0;
                for(auto to:G[i]){
                    wt[to]++;
                }
            }
        }
        int root=-1;
        for(int i=1;i<=n;i++) if(wt[i]) {root=i; break;}
        dfs(root,0);
        int ans=INF;
        for(int i=0;i<(int)dp[root].size();i++) ans=min(ans,dp[root][i]);
        printf("%lld\n",2LL*n*(n+1)/2-ans);
    }
    return 0;
}
