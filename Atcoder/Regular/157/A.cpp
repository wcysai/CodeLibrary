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
int n,a,b,c,d;
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    if(b!=c&&b!=c+1&&b!=c-1) puts("No");
    else if(a>0&&d>0&&b==0&&c==0) puts("No");
    else puts("Yes");
    return 0;
}

