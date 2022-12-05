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
int n,m,a[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    if(n==2) 
    {
        for(int j=1;j<=m-1;j++) printf("0 ");
        printf("1\n");
        for(int j=1;j<=m-1;j++) printf("0 ");
        printf("1\n");
        return 0;
    }
    if(n==3)
    {
        for(int j=1;j<=m-1;j++) printf("0 ");
        printf("1\n");
        for(int j=1;j<=m-1;j++) printf("0 ");
        printf("1\n");
        for(int j=1;j<=m-2;j++) printf("0 ");
        printf("1 0\n");
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n/2;i++) printf("0 1\n");
        for(int i=n/2+1;i<=n;i++) printf("1 0\n");
        return 0;
    }
    if(m==3)
    {
        if(n==4)
        {
            printf("0 0 1\n");
            printf("0 0 1\n");
            printf("0 1 0\n");
            printf("0 1 0\n");
        }
        else if(n==5)
        {
            printf("0 0 1\n");
            printf("0 0 1\n");
            printf("0 1 0\n");
            printf("0 1 0\n");
            printf("1 0 0\n");
        }
        else 
        {
            for(int i=1;i<=n/3;i++) printf("0 0 1\n");
            for(int i=n/3+1;i<=2*n/3;i++) printf("0 1 0\n");
            for(int i=2*n/3+1;i<=n;i++) printf("1 0 0\n");
        }
    }
    else
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=m-i-1;j++) printf("0 ");
            printf("1");
            for(int j=1;j<=i;j++) printf(" 0");
            printf("\n");
        }
        for(int i=1;i<=n-3;i++) 
        {
            for(int j=1;j<=m-1;j++) printf("0 ");
            printf("1\n");
        }
    }
    return 0;
}

