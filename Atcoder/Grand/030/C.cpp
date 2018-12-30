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
int n,k;
int ans[505][505];
int main()
{
    scanf("%d",&k);
    if(k==1)
    {
        printf("1\n1\n");
        return 0;
    }
    n=(k+3)/4*2;
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ans[i][j]=(i+j-1)%n+1;
            if(i&1) ans[i][j]+=n;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(ans[i][j]>k) ans[i][j]-=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}

