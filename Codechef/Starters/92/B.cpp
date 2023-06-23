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
int T,W,L,a[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&W,&L);
        if((W&1)&&(L&1)) puts("NO"); else puts("YES");
    }
    return 0;
}

