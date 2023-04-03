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
int n,k,a[MAXN],dep[MAXN],faid[MAXN];
vector<int> u,v;
vector<int> G[MAXN];
vector<int> bydep[MAXN];
vector<int> dir;
int to(int x,int id){
    return (u[id]==x?v[id]:u[id]);
}
void dfs(int v,int id,int d){
    dep[v]=d; faid[v]=id; bydep[d].push_back(v);
    for(auto e:G[v]){
        if(e==id) continue;
        //if(dir[e]!=-1) continue;
        dfs(to(v,e),e,d+1);
    }
}
int calc(){
    int now=-1,cnt=-1;
    for(int c=0;c<3;c++){
        int cc=0;
        for(int j=c;j<n;j+=3){
            for(auto x:bydep[j]){
                bool f=false;
                for(auto e:G[x]){
                    if(dir[e]==-1) f=true;
                }
                if(f) cc++;
            }
        }
        if(cc>cnt) {now=c; cnt=cc;}
    }
    assert(cnt);
    return now;
}
void Solve(int N,vector<int> A,vector<int> B){
    n=N;
    u=A; v=B;
    for(int i=0;i<n-1;i++){
        G[u[i]].push_back(i); G[v[i]].push_back(i);
    }
    dir.resize(n-1); for(int i=0;i<n-1;i++) dir[i]=-1;
    dfs(1,-1,0);
    for(int i=0;i<30;i++){
        int c=calc();
        vector<int> rev(n-1,0),choice(n,0);
        for(int j=c;j<n;j+=3){
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
        auto ret=Query(rev,choice);
        for(int j=c;j<n;j+=3){
            for(auto x:bydep[j]){
                bool un=false;
                for(auto e:G[x]) if(dir[e]==-1) un=true;
                if(!un) continue;
                if(ret[x]){
                    for(auto e:G[x]) if(dir[e]==-1) dir[e]=(u[e]==x?1:0);
                }
                else{
                    bool f=false;
                    for(auto e:G[x]){
                        if(e==faid[x]) continue;
                        int z=to(x,e);
                        if(ret[z]){
                            f=true;
                            assert(dir[e]==-1);
                            dir[e]=(u[e]==x?0:1);
                        }
                    }
                    if(!f){
                        int e=faid[x]; assert(e!=-1); assert(dir[e]==-1);
                        int z=to(x,e);
                        dir[e]=(u[e]==x?0:1);
                    }
                }
            }
        }
        bool f=true;
        for(int j=0;j<n-1;j++) if(dir[j]==-1) {f=false; break;}
        if(f) {Answer(dir); return;}
        //}
    }
    assert(0);
    return;
}

