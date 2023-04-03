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
int T,n,k,a[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int tot=0;
        for(int i=1;i<=n;i+=2)
            for(int j=1;j<=n;j+=2)
                a[i][j]=++tot;
        for(int i=1;i<=n;i+=2)
            for(int j=2;j<=n;j+=2)
                a[i][j]=++tot;
        for(int i=2;i<=n;i+=2)
            for(int j=1;j<=n;j+=2)
                a[i][j]=++tot;
        for(int i=2;i<=n;i+=2)
            for(int j=2;j<=n;j+=2)
                a[i][j]=++tot;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                printf("%d%c",a[i][j],j==n?'\n':' ');
    }
    return 0;
}

