#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
mt19937 wcy(time(NULL));
int main()
{
    freopen("in.txt","w",stdout);
    for(int t=0;t<100;t++){
        n=100; m=4950; k=100;
        printf("%d %d %d\n",n,m,k);
        for(int i=1;i<=100;i++)
            for(int j=i+1;j<=100;j++){
                int w=wcy()%k+1;
                printf("%d %d %d\n",i,j,w);
            }
    }
}
