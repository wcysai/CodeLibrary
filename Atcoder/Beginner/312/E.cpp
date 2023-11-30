#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int x[MAXM][MAXM][MAXM];
int dx[6]={0,0,0,0,1,-1};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={-1,1,0,0,0,0};
set<P> s;
int ans[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b,c,d,e,f;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        for(int j=a+1;j<d+1;j++)
            for(int k=b+1;k<e+1;k++)
                for(int l=c+1;l<f+1;l++)
                    x[j][k][l]=i;
    }
    for(int i=1;i<=101;i++)
        for(int j=1;j<=101;j++)
            for(int k=1;k<=101;k++){
                if(!x[i][j][k]) continue;
                for(int l=0;l<6;l++){
                    int nx=i+dx[l],ny=j+dy[l],nz=k+dz[l];
                    if(x[nx][ny][nz]<=x[i][j][k]) continue;
                    s.insert(P(x[i][j][k],x[nx][ny][nz]));
                }
            }
    for(auto p:s){
        ans[p.F]++; ans[p.S]++;
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
