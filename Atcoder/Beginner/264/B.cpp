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
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int layer=max(max(n-8,8-n),max(m-8,8-m));
    if(layer%2==0) puts("white"); else puts("black");
    return 0;
}

