#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,M;
int a[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        if(N==1&&M==1) printf("1\n1\n"); 
        else if(N==2&&M==1)
        {
            puts("1");
            printf("1\n1\n");
        }
        else if(N==1&&M==2)
        {
            puts("1");
            printf("1 1\n");
        }
        else if(N==1)
        {
            puts("2");
            for(int i=1;i<=M;i++) printf("%d%c",((i/2)&1)+1,i==M?'\n':' ');
        }
        else if(M==1)
        {
            puts("2");
            for(int i=1;i<=N;i++) printf("%d\n",((i/2)&1)+1);
        }
        else if(N==2&&M==2)
        {
            puts("2");
            printf("1 2\n1 2\n");
        }
        else if(N==2)
        {
            puts("3");
            for(int j=1;j<=2;j++)
                for(int i=1;i<=M;i++)
                    printf("%d%c",i%3+1,i==M?'\n':' ');
        }
        else if(M==2)
        {
            puts("3");
            for(int i=1;i<=N;i++)
                printf("%d %d\n",i%3+1,i%3+1);
        }
        else
        {
            bool flag=false;
            puts("4");
            if(N>M) {flag=true; swap(N,M);}
            N*=2;M*=2;
            for(int i=1;i<=M;i+=4)
            {
                int x=1,y=i,sgn=1;
                while(x<=N&&y<=M)
                {
                    if(sgn) a[x][y]=1; else a[x][y]=2;
                    x++;y++; sgn^=1;
                }
            }
            for(int i=1;i<=N;i+=4)
            {
                int x=i,y=1,sgn=1;
                while(x<=N&&y<=M)
                {
                    if(sgn) a[x][y]=1; else a[x][y]=2;
                    x++;y++; sgn^=1;
                }
            }
            for(int i=3;i<=M;i+=4)
            {
                int x=1,y=i,sgn=1;
                while(x<=N&&y<=M)
                {
                    if(sgn) a[x][y]=3; else a[x][y]=4;
                    x++;y++; sgn^=1;
                }
            }
            for(int i=3;i<=N;i+=4)
            {
                int x=i,y=1,sgn=1;
                while(x<=N&&y<=M)
                {
                    if(sgn) a[x][y]=3; else a[x][y]=4;
                    x++;y++; sgn^=1;
                }
            }
            for(int i=2;i<=M;i+=4)
            {
                int x=1,y=i,sgn=1;
                while(x<=N&&y>=1)
                {
                    if(sgn) a[x][y]=3; else a[x][y]=4;
                    x++;y--; sgn^=1;
                }
            }
            for(int i=4;i<=M;i+=4)
            {
                int x=1,y=i,sgn=1;
                while(x<=N&&y>=1)
                {
                    if(sgn) a[x][y]=1; else a[x][y]=2;
                    x++;y--; sgn^=1;
                }
            }
            N/=2;M/=2;
            if(flag)
            {
                for(int i=1;i<=M;i++)
                    for(int j=1;j<=N;j++)
                        printf("%d%c",a[j][i],j==N?'\n':' ');
            }
            else
            {
                for(int i=1;i<=N;i++)
                    for(int j=1;j<=M;j++)
                        printf("%d%c",a[i][j],j==M?'\n':' ');
            }
        }
    }
    return 0;
}

