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
    printf("%d\n",500000);
    for(int i=1;i<=500000;i++){
        printf("%d%c",wcy()%5+1,i==500000?'\n':' ');
    }
    return 0;
}

