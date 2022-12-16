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
int n,m,x,y,T,a[MAXN];
int main()
{
    scanf("%d%d",&n,&T);
    scanf("%d%d%d",&m,&x,&y);
    int need=(y*m+x*(n-m)+x*y-1)/(x*y);
    if(need<=T*60) puts("0"); else printf("%d\n",(need-T*60+59)/60);
    return 0;
}

