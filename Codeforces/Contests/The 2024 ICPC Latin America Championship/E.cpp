#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],x[MAXN];
int st[MAXN],ed[MAXN];
vector<int> v1,v2;
int ans[MAXN];
vector<int> G[MAXN];
int color[MAXN];
bool dfs(int v,int c){
    color[v]=c;
    for(auto to:G[v]){
        if(color[to]&&color[to]==color[v]) return false;
        if(!color[to]&&!dfs(to,-c)) return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%d",&x[i]);
        if(x[i]>0) st[x[i]]=i; else ed[-x[i]]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if((st[i]<st[j]&&ed[i]<ed[j]&&ed[i]>st[j])||(st[i]>st[j]&&st[i]<ed[j]&&ed[j]<ed[i])){
                G[i].push_back(j); G[j].push_back(i);
            }
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                puts("*"); return 0;
            }
        }
    }
    for(int i=1;i<=n;i++) if(color[i]==1) printf("G"); else printf("S");
    printf("\n");
    return 0;
}

