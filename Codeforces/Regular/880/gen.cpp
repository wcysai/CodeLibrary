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
int t,n,k,a[MAXN];
mt19937_64 wcy(time(NULL));
int main()
{
    printf("%d\n",100);
    for(int i=0;i<100;i++){
        printf("%d\n",1);
        for(int j=0;j<(1<<2);j++) printf("%lld ",wcy()%(1LL<<2));
        printf("\n");
    }
    return 0;
}

