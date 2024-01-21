#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,z,a[MAXN];
int sx,sy,tx,ty;
string str;
vector<string> mp;
vector<vector<P> > dist;
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
deque<P> que,nque;
int main(){
    scanf("%d%d%d",&n,&m,&z);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    sx--; sy--; tx--; ty--;
    for(int i=0;i<n;i++){
        cin>>str; 
        mp.push_back(str);
    }
    dist.resize(n);
    for(int i=0;i<n;i++){
        dist[i].resize(m);
        for(int j=0;j<m;j++) dist[i][j]=P(INF,0);
    }
    dist[sx][sy]=P(0,0); que.push_back(P(sx,sy));
    //printf("k=%d\n",k);
    while(que.size()||nque.size()){
        if(!que.size()) swap(que,nque);
        P p=que.front(); que.pop_front();
        int x=p.F,y=p.S;
        if(x==tx&&y==ty){
            printf("%d\n",dist[x][y].F); return 0;
        }
        int d=dist[x][y].F,pw=dist[x][y].S;
        if(pw==0){
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(mp[nx][ny]=='.'&&dist[nx][ny]>P(d,pw)){
                        dist[nx][ny]=P(d,pw);
                        que.push_front(P(nx,ny));
                    }
                    else if(mp[nx][ny]=='#'&&dist[nx][ny]>P(d+1,1-z)){
                        //puts("here");
                        dist[nx][ny]=P(d+1,1-z);
                        nque.push_back(P(nx,ny));
                    }
                }
            }
        }
        else{
            for(int k=0;k<8;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]>P(d,pw+1)){
                    dist[nx][ny]=P(d,pw+1);
                    que.push_back(P(nx,ny));
                }
            }
        }
    }
    return 0;
}

