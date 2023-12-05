#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> st[MAXN];
int vis[MAXN],ans[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x;scanf("%d",&x);
            st[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int v=i;
        vis[v]=i;
        vector<int> tmp; tmp.push_back(v);
        while(st[v].size()){
            int nxt=st[v].back();
            st[v].pop_back();
            if(vis[nxt]){
                if(vis[nxt]==i){
                    while(tmp.back()!=nxt){
                        vis[tmp.back()]=0;
                        tmp.pop_back();
                    }
                    tmp.pop_back();
                }
                else{
                    for(auto x:tmp) ans[x]=ans[nxt];
                    tmp.clear();
                    break;
                }
            }
            v=nxt; vis[v]=i; tmp.push_back(v);
        }
        for(auto x:tmp) ans[x]=v;
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}

