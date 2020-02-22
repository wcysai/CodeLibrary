#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define F first
#define S second
#define x1 daksods
#define y1 dkasodsa
#define x2 fdcskaos
#define y2 askdosa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN][MAXN],n,M;
int ask(int x,int y)
{
    if(a[x][y]!=-1) return a[x][y];
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int z;
    scanf("%d",&z);
    a[x][y]=z;
    M=max(M,a[x][y]);
    return a[x][y];
}
void answer(int x,int y)
{
    printf("! %d %d\n",x,y);
    fflush(stdout);
    exit(0);
}
P solve(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2) return P(x1,y1);
    if(x2-x1<=1&&y2-y1<=1)
    {
        int nx=0,ny=0;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
             if(ask(i,j)>a[nx][ny])
            {
                nx=i; 
                ny=j;
            }
        return P(nx,ny);
    }
    if(x2-x1>=y2-y1)
    {
        int mid=(x1+x2)/2;
        int nx=0,ny=0;
        for(int j=y1;j<=y2;j++)
        {
            if(ask(mid,j)>a[nx][ny])
            {
                nx=mid; 
                ny=j;
            }
        }
        int px=nx,py=ny;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
                if(nx+dx>=x1&&nx+dx<=x2&&ny+dy>=y1&&ny+dy<=y2)
                {
                    if(ask(nx+dx,ny+dy)>a[px][py])
                    {
                        px=nx+dx;
                        py=ny+dy;
                    }
                }
        if(px==nx&&py==ny) return P(nx,ny);
        if(px<nx) return solve(x1,y1,px+1,y2);
        else return solve(px-1,y1,x2,y2);
    }
    else
    {
        int mid=(y1+y2)/2;
        int nx=0,ny=0;
        for(int j=x1;j<=x2;j++)
        {
            if(ask(j,mid)>a[nx][ny])
            {
                nx=j; 
                ny=mid;
            }
        }
        int px=nx,py=ny;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
                if(nx+dx>=x1&&nx+dx<=x2&&ny+dy>=y1&&ny+dy<=y2)
                {
                    if(ask(nx+dx,ny+dy)>a[px][py])
                    {
                        px=nx+dx;
                        py=ny+dy;
                    }
                }
        if(px==nx&&py==ny) return P(nx,ny);
        if(py<ny) return solve(x1,y1,x2,py+1);
        else return solve(x1,py-1,x2,y2);
    }
}
int main()
{
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    P p=solve(1,1,n,n);
    answer(p.F,p.S);
    return 0;
}