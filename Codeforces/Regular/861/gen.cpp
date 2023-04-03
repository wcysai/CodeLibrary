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
int n,k,a[MAXN];
mt19937 wcy(time(NULL));
int main()
{
    n=200000; k=100001;
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++) printf("%d%c",wcy()%n+1,i==n?'\n':' ');
    return 0;
}

