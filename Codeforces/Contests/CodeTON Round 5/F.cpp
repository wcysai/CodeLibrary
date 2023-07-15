#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,ans[MAXN];
vector<int> G[MAXN];
int d[MAXN];
int cnt[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) ans[i]=INF;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++) d[j]=INF,cnt[j]=0;
        queue<int> que;
        que.push(i);
        cnt[0]++; d[i]=0;
        while(que.size()){
            int v=que.front(); que.pop();
            for(auto to:G[v]){
                if(d[to]==INF) {d[to]=d[v]+1; que.push(to); cnt[d[to]]++;}
            }
        }
        v.clear();
        for(int j=0;j<=n-1;j++)
            for(int k=0;k<cnt[j];k++)
                v.push_back(j);
        int s=0;
        for(int j=0;j<n;j++){
            s+=v[j];
            ans[j+1]=min(ans[j+1],s);
        }
    }
    for(int i=0;i<=n;i++) printf("%d%c",(i-1)*i-2*ans[i]+(n-i)*i,i==n?'\n':' ');
    return 0;
}

