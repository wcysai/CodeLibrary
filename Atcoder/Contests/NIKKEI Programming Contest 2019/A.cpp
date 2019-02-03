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
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    int res=max(0,a+b-n);
    printf("%d %d\n",min(a,b),res);
    return 0;
}

