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
int n,a[MAXN];
int ideg[MAXN];
int vis[MAXN];
int color[MAXN];
//i->a[i]
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        ideg[a[i]]++;
    }
    memset(color,-1,sizeof(color));
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!ideg[i]){
            que.push(i);
        }
    }
    bool f=true;
    while(que.size()){
        int v=que.front(); que.pop();
        if(color[v]!=-1) continue;
        color[v]=0;
        if(color[a[v]]==0) {f=false; break;}  
        if(color[a[v]]==-1){
            color[a[v]]=1;
            if(color[a[a[v]]]==-1){
                ideg[a[a[v]]]--;
                if(ideg[a[a[v]]]==0) que.push(a[a[v]]);
            }
        }
    }
    if(!f) {puts("-1"); return 0;}
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            int tot=0,now=i;
            do{
                tot++;
                now=a[now]; color[now]=(tot&1);
            }while(now!=i);
            if(tot&1) {f=false; break;}
        }
    }
    if(!f) {puts("-1"); return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++) if(!color[i]) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++) if(!color[i]) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

