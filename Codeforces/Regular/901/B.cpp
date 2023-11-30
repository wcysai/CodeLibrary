#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c,d,m;
int ans;
vector<unsigned> v;
int p5[10];
int dist[MAXN];
vector<int> G[MAXN];
bool check(int x){
    for(int i=0;i<8;i++){
        int res=x%5;
        x=x/5;
        if(!res) continue;
        res--;
        if((i>>1)!=res) return false;
    }
    return true;
}
int modify(int x,int op){
    vector<int> tmp(8,0);
    for(int i=0;i<8;i++){
        int res=x%5;
        x=x/5;
        if(!res) continue;
        int to=i;
        if(op==0){
            if(!((to>>1)&1)) to&=3;
        }
        else if(op==1){
            if((to>>1)&1) to|=4;
        }
        else if(op==2){
            if((to>>2)&1) to^=2;
        }
        else{
            if(to&1) to^=2;
        }
        if(tmp[to]&&(tmp[to]!=res)) return -1;
        else tmp[to]=res;
    }
    int ret=0;
    for(int i=7;i>=0;i--) ret=ret*5+tmp[i];
    return ret;
}
int main()
{
    queue<int> que;
    p5[0]=1;
    for(int i=1;i<=8;i++) p5[i]=p5[i-1]*5;
    for(int i=0;i<p5[8];i++){
        if(check(i)) {que.push(i); dist[i]=0;}
        else dist[i]=INF;
        for(int j=0;j<4;j++){
            int to=modify(i,j);
            if(to!=-1) G[to].push_back(i);
        }
    }
    while(que.size()){
        int v=que.front(); que.pop();
        for(auto to:G[v]){
            if(dist[to]==INF){
                dist[to]=dist[v]+1; que.push(to);
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&m);
        vector<int> tmp(8,0);
        bool f=true;
        for(int i=0;i<30;i++){
            int m1=(((a>>i)&1)<<2)+(((b>>i)&1)<<1)+(((m>>i)&1));
            int m2=(((c>>i)&1)<<1)+((d>>i)&1)+1;
            if(tmp[m1]&&(tmp[m1]!=m2)) f=false;
            else tmp[m1]=m2;
        }
        if(!f) {puts("-1"); continue;}
        int mask=0;
        for(int i=7;i>=0;i--) mask=mask*5+tmp[i];
        if(dist[mask]==INF) puts("-1"); else printf("%d\n",dist[mask]);
    }
    return 0;
}

