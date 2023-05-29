#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,fa[MAXN],fact[MAXN],invf[MAXN];
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int sz[MAXN];
void dfs(int v,int p){
    sz[v]=1; fa[v]=p;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    int x=k/2+1,ans=1LL*n*comb(n,k)%MOD;
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(auto to:G[i]){
            if(to==fa[i]) v.push_back(n-sz[i]);
            else v.push_back(sz[to]);
        }
        for(int j=0;j<(int)v.size();j++){
            if(v[j]>=x){
                int all=comb(n,k);
                for(int num=0;num<x;num++) dec(all,1LL*comb(v[j],num)*comb(n-v[j],k-num)%MOD); 
                dec(ans,all);
            }
        }
    }
    ans=1LL*ans*pow_mod(comb(n,k),MOD-2)%MOD;
    printf("%d\n",ans);
    return 0;
}

