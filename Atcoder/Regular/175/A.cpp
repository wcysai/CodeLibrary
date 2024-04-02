#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p[MAXN];
char str[MAXN];
bool vis[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    scanf("%s",str+1);
    int ans=0;
    for(int t=0;t<2;t++){
        char ch=(t==0?'L':'R');
        if(str[p[1]]!='?'&&str[p[1]]!=ch) continue;
        memset(vis,false,sizeof(vis));
        vis[p[1]]=true;
        int res=1;
        for(int i=2;i<=n;i++){
            int nxt=(t==0?p[i]+1:p[i]-1);
            if(nxt<=0) nxt+=n;
            if(nxt>n) nxt-=n;
            if(!vis[nxt]){
                if(str[p[i]]!='?'&&str[p[i]]!=ch) res=0;
            }
            else{
                if(str[p[i]]=='?') res=2LL*res%MOD;
            }
            vis[p[i]]=true;
            //printf("i=%d res=%d\n",i,res);
        }
        add(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}

