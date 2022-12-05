#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN][MAXN];
int main()
{
    printf("%d\n",1);
    printf("%d\n",4000);
    for(int i=1;i<=1000;i++)
        for(int j=4*(i-1)+1;j<=4*(i-1)+4;j++)
            for(int k=4*(i-1)+1;k<=4*(i-1)+4;k++)
                if(j!=k) a[j-1][k-1]=1;
    for(int i=0;i<4000;i++)
    {
        for(int j=0;j<4000;j++) printf("%d",a[i][j]);
        puts("");
    }
    return 0;
}

