#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],cnt,cur,rmin,rmax,cmin,cmax;
char str[MAXN][MAXN],tmp[MAXN][MAXN],ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
int maxi[2][4];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool check(){
    int x=-1,y=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            vis[i][j]=false;
            if(str[i][j]=='#') {x=i; y=j;}
        }
    if(x==-1){
        str[1][1]='#'; return true;
    }
    queue<P> que; que.push(P(x,y)); vis[x][y]=true;
    while(que.size()){
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&str[nx][ny]=='#'){
                vis[nx][ny]=true;
                que.push(P(nx,ny));
            }
        }
    }
    for(int i=0;i<2;i++){
        maxi[i][0]=maxi[i][1]=-INF;
        maxi[i][2]=maxi[i][3]=INF;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='#'){
                if(vis[i][j]){
                    maxi[0][0]=max(maxi[0][0],i); maxi[0][1]=max(maxi[0][1],j);
                    maxi[0][2]=min(maxi[0][2],i); maxi[0][3]=min(maxi[0][3],j);
                }
                else{
                    maxi[1][0]=max(maxi[1][0],i); maxi[1][1]=max(maxi[1][1],j);
                    maxi[1][2]=min(maxi[1][2],i); maxi[1][3]=min(maxi[1][3],j);
                }
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='#'&&!vis[i][j]) return false;
    return true;
}
void go(){
    bool upd=false;
    for(int i=1;i<=n;i++){
        int mini=INF,maxi=-INF;
        for(int j=1;j<=m;j++){
            if(str[i][j]=='#') {
                mini=min(mini,j);
                maxi=max(maxi,j);
            }
        }
        if(mini==INF) continue;
        for(int j=mini+1;j<maxi;j++) {
            if(str[i][j]!='#') upd=true;
            str[i][j]='#';
        }
    }
    for(int i=1;i<=m;i++){
        int mini=INF,maxi=-INF;
        for(int j=1;j<=n;j++){
            if(str[j][i]=='#') {
                mini=min(mini,j);
                maxi=max(maxi,j);
            }
        }
        if(mini==INF) continue;
        for(int j=mini+1;j<maxi;j++)
        {
            if(str[j][i]!='#') upd=true;
            str[j][i]='#';
        }
    }
    if(upd) go();
}
void answer(){
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) printf("%c",ans[i][j]);
        printf("\n");
    }
}
void upd(){
   // for(int i=1;i<=n;i++) printf("%s\n",str[i]+1);
    int cnt=0;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            if(str[i][j]=='#') cnt++;
    if(cnt<cur){
        cur=cnt;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++)
                ans[i][j]=str[i][j];
    }
}
void rollback(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            str[i][j]=tmp[i][j];
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        go();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                {tmp[i][j]=str[i][j]; ans[i][j]='#';}
        cur=n*m;
        if(check()) {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    ans[i][j]=str[i][j];
            answer();
        }
        else{
            int xl=min(maxi[0][0],maxi[1][0]),xr=max(maxi[0][2],maxi[1][2]);
            int yl=min(maxi[0][1],maxi[1][1]),yr=max(maxi[0][3],maxi[1][3]);
            for(int i=xl;i<=xr;i++) str[i][yl]='#';
            for(int i=yl;i<=yr;i++) str[xr][i]='#';
            go();
            if(check()) upd(); rollback();
            for(int i=yl;i<=yr;i++) str[xl][i]='#';
            for(int i=xl;i<=xr;i++) str[i][yl]='#';
            go();
            if(check()) upd(); rollback();
            for(int i=xl;i<=xr;i++) str[i][yr]='#';
            for(int i=yl;i<=yr;i++) str[xr][i]='#';
            go();
            if(check()) upd(); rollback();
            for(int i=yl;i<=yr;i++) str[xl][i]='#';
            for(int i=xl;i<=xr;i++) str[i][yr]='#';
            go();
            if(check()) upd(); rollback();
            answer();
        }
    }
    return 0;
}

