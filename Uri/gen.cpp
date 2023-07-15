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
    n=100; m=10000; k=200;
    printf("%d %d %d\n",n,m,k);
    for(int i=0;i<m;i++)
    {
        int u=wcy()%n+1,v=wcy()%n+1,w=wcy()%k+1;
        printf("%d %d %d\n",u,v,w);
    }
}
