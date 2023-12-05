#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int x[MAXN],y[MAXN];
set<int> s[2];
int par,state;
bool can_even(int x,int y){
    if(x>=y) return true; else return false;
}
bool can_odd(int x,int y){
    if(x==0&&y==0) return false;
    if(x<=y) return true; else return false;
}
void update(int id){
    int val=(x[id+1]+y[id+1])&1;
    state^=(val^par);
    par=val;
    //assert(s[val].count(id)); 
    s[val].erase(id);
}
void read(){
    int z;
    scanf("%d",&z);
    update(z);
}
void choose(int par){
    int nxt=*s[par].begin();
    printf("%d\n",nxt);
    fflush(stdout);
    update(nxt);
}
void solve(int goal){
    if(state==goal){
        int a=s[par].size(),b=s[par^1].size();
        if(a&&!can_odd(a-1,b)) choose(par); else choose(par^1);
    }
    else{
        int a=s[par].size(),b=s[par^1].size();
        if(a&&!can_even(a-1,b)) choose(par); else choose(par^1);
   }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++) scanf("%d%d",&x[i],&y[i]);
        s[0].clear(); s[1].clear();
        for(int i=2;i<=n+1;i++) if((x[i]+y[i])&1) s[1].insert(i-1); else s[0].insert(i-1);
        par=(x[1]+y[1])&1;
        if(can_even((int)s[par].size(),(int)s[par^1].size())){
           printf("First\n"); fflush(stdout);
           state=0;
           for(int i=1;i<=n;i++){
               if(i&1) solve(0); else read();
           }
        }
        else{
           printf("Second\n"); fflush(stdout);
           state=0;
           for(int i=1;i<=n;i++){
               if(i&1) read(); else solve(1);
           }
        }
    }
    return 0;
}

