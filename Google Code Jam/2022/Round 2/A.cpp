#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,x,y,a[MAXN][MAXN];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int get_dist()
{
    int pt=(n+1)/2;
    return max(x-pt,pt-x)+max(y-pt,pt-y);
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&k);
        printf("Case #%d: ",t);
        x=1,y=1;
        int tot=1,dir=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=0;
        while(tot<=n*n)
        {
            a[x][y]=tot;
            tot++;
            if(tot>n*n) break;
            while(x+dx[dir]>n||x+dx[dir]<1||y+dy[dir]>n||y+dy[dir]<1||a[x+dx[dir]][y+dy[dir]]) dir=(dir+1)%4;
            x+=dx[dir]; y+=dy[dir];
        }
        x=1; y=1; dir=0;
        int nx=(n+1)/2,ny=(n+1)/2;
        if(k&1||get_dist()>k) {puts("IMPOSSIBLE"); continue;}
        while(get_dist()<k)
        {
            while(x+dx[dir]>n||x+dx[dir]<1||y+dy[dir]>n||y+dy[dir]<1||a[x+dx[dir]][y+dy[dir]]!=a[x][y]+1) dir=(dir+1)%4;
            x+=dx[dir]; y+=dy[dir]; 
            k--;
        }
        vector<P> v;
        while(x!=nx||y!=ny)
        {
            if(x<nx&&a[x+1][y]>a[x][y]) {if(a[x+1][y]!=a[x][y]+1) v.push_back(P(a[x][y],a[x+1][y])); x++;}
            if(x>nx&&a[x-1][y]>a[x][y]) {if(a[x-1][y]!=a[x][y]+1) v.push_back(P(a[x][y],a[x-1][y])); x--;}
            if(y<ny&&a[x][y+1]>a[x][y]) {if(a[x][y+1]!=a[x][y]+1) v.push_back(P(a[x][y],a[x][y+1])); y++;}
            if(y>ny&&a[x][y-1]>a[x][y]) {if(a[x][y-1]!=a[x][y]+1) v.push_back(P(a[x][y],a[x][y-1])); y--;}
        }
        printf("%d\n",(int)v.size());
        for(auto p:v) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

