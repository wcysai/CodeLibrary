#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> G[MAXN];
vector<int> v[MAXN];
int d[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) d[i]=INF; d[1]=1;
        for(int i=0;i<m;i++){
            int a,b; scanf("%d%d",&a,&b);
            G[b].push_back(a);
        }
        queue<int> que; que.push(1);
        while(que.size()){
            int v=que.front(); que.pop();
            for(auto to:G[v]){
                if(d[to]==INF) {d[to]=d[v]+1; que.push(to);}
            }
        }
        for(int i=1;i<=n;i++) v[i].clear();
        bool f=true;
        int s=0;
        for(int i=1;i<=n;i++) {if(d[i]==INF) f=false; else {s+=d[i]; v[d[i]].push_back(i);}}
        if(!f) puts("INFINITE");
        else{
            puts("FINITE");
            printf("%d\n",s);
            for(int i=1;i<=n;i++){
                for(int j=n;j>=i;j--){
                    for(auto x:v[j]) printf("%d ",x);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

