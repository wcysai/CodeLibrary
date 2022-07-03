#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 35
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    a[0][0]=1;
    for(int i=0;i<n;i++)
    {
        a[i][0]=a[i][i]=1;
        for(int j=1;j<i;j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++) printf("%d%c",a[i][j],j==i?'\n':' ');
    return 0;
}

