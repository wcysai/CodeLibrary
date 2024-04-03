#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
bool boundary[11][MAXN][MAXN];
int wx[11],wy[11];
char mp[MAXN][MAXN];
queue<P> que;
void check(int x,int y){
    for(int id=1;id<=k;id++){
        if(boundary[id][x][y]) continue;
        int nx=x-wx[id],ny=y-wy[id];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!='#'){
            mp[nx][ny]='#';
            que.push(P(nx,ny));
        }
    }
}
bool check_empty(int x,int y){
    bool f=true;
    for(int id=1;id<=k;id++){
        int nx=x-wx[id],ny=y-wy[id];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='#'); else f=false;
        nx=x+wx[id],ny=y+wy[id];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='#') f=false;
    }
    //printf("%d %d %d\n",x,y,f?1:0);
    return f;
}
void expand(int x,int y){
    for(int id=1;id<=k;id++){
        int nx=x+wx[id],ny=y+wy[id];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'&&check_empty(nx,ny)) {mp[nx][ny]='#'; que.push(P(nx,ny)); }
    }
}
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j]='.';
    for(int i=1;i<=k;i++){
        scanf("%d%d",&wx[i],&wy[i]);
        swap(wx[i],wy[i]);
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            swap(x,y);
            boundary[i][x][y]=true;
            mp[x][y]='#';
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='#') que.push(P(i,j));
    while(que.size()){
        P p=que.front(); que.pop();
        check(p.F,p.S);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c",mp[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='.'&&check_empty(i,j)) {mp[i][j]='#'; que.push(P(i,j));}
    while(que.size()){
        P p=que.front(); que.pop();
        //printf("F=%d S=%d\n",p.F,p.S);
        expand(p.F,p.S);
    }
    //printf("sz=%d\n",(int)que.size());
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c",mp[i][j]);
        printf("\n");
    }
    return 0;
}

