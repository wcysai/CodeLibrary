#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
char mp[MAXN][MAXN];
int med[MAXN][MAXN];
int d[MAXN][MAXN];
int sx,sy,tx,ty;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='S') {sx=i; sy=j;}
            else if(mp[i][j]=='T') {tx=i; ty=j;}
        }
    memset(med,-1,sizeof(med));
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        med[x][y]=z;
    }
    memset(d,-1,sizeof(d));
    d[sx][sy]=max(0,med[sx][sy]);
    queue<P> que;que.push(P(sx,sy));
    while(que.size()){
        P p=que.front(); que.pop();
        if(p.F==tx&&p.S==ty) {puts("Yes"); return 0;}
        for(int k=0;k<4;k++){
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!='#'&&d[nx][ny]<d[p.F][p.S]-1){
                d[nx][ny]=max(d[p.F][p.S]-1,med[nx][ny]);
                que.push(P(nx,ny));
            }
        }
    }
    puts("No");
    return 0;
}

