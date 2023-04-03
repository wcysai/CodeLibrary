#pragma GCC optimize(3)
#include "conveyor.h"
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dep[MAXN];
int u[MAXN],v[MAXN];
vector<int> G[MAXN];
vector<int> bydep[MAXN];
int to(int x,int id){
    return (u[id]==x?v[id]:u[id]);
}
void dfs(int v,int id,int d){
    dep[v]=d; bydep[d].push_back(v);
    for(auto e:G[v]){
        if(e==id) continue;
        dfs(to(v,e),e,d+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(i); G[v[i]].push_back(i);
    }
    vector<int> dir(n-1,-1);
    dfs(0,-1,0);
    for(int i=0;i<30;i+){
        vector<int> rev(n-1,0),choice(n,0);
        for(int j=i;j<n;j+=3){
            for(auto x:bydep[j]){
                choice[x]=1;
                for(auto e:G[x]){
                    if(dir[e]!=-1){
                        int z=(dir[e]==1?u[e]:v[e]);
                        if(z!=x) rev[e]=1; 
                    }
                }
            }
        }
        auto ret=query(rev,choice);
        for(int j=i;j<n;j+=3){
            for(auto x:bydep[j]){
                if(ret[x]){
                    for(auto e:x) if(dir[e]==-1) dir[e]=(u[e]==x?1:0);
                }
                else{
                    for(auto e:x){
                        int z=to(x,e);
                        if(ret[z]){
                            assert(dir[e]!=-1) dir[e]=(u[e]==x?0:1);
                        }
                    }
                }
            }
        }
        bool f=true;
        for(int j=0;j<n-1;j++) if(dir[j]==-1) {f=false; break;}
        if(f) answer(dir);
    }
    return 0;
}

