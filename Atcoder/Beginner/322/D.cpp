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
int n,k,a[MAXN];
char s[3][6][6];
bool grid[5][5];
bool place(int id,int dir,int dx,int dy,bool filled){
    bool fst=false;
    int shiftx=0,shifty=0;
    vector<P> v;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(s[id][i][j]=='#'){
                int nx,ny;
                if(dir==0){
                    nx=i; ny=j;
                }
                else if(dir==2){//(-i,-j)
                    nx=-i,ny=-j;
                }
                else if(dir==1){
                    nx=j; ny=-i;
                }
                else{
                    nx=-j; ny=i;
                }
                if(!fst){
                    shiftx=dx-nx; shifty=dy-ny;
                    fst=true;
                }
                nx+=shiftx; ny+=shifty;
                if(nx<1||nx>4||ny<1||ny>4||grid[nx][ny]!=filled) return false;
                v.push_back(P(nx,ny));
            }
        }
    }
    for(auto p:v) grid[p.F][p.S]=!grid[p.F][p.S];
    return true;
}
bool check(){
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            if(!grid[i][j]) return false;
    return true;
}
bool dfs(int now){
    if(now==3){
        if(check()) return true; else return false;
    }
    for(int dir=0;dir<=3;dir++)
        for(int dx=1;dx<=4;dx++)
            for(int dy=1;dy<=4;dy++){
                if(place(now,dir,dx,dy,false)){
                    //printf("now=%d dir=%d dx=%d dy=%d\n",now,dir,dx,dy);
                    if(dfs(now+1)) return true;
                    place(now,dir,dx,dy,true);
                }
            }
    return false;
}
int main()
{
    for(int i=0;i<3;i++)
        for(int j=1;j<=4;j++)
            scanf("%s",s[i][j]+1);
    if(dfs(0)) printf("Yes\n"); else printf("No\n");
    return 0;
}

