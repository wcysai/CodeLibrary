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
int t,n,a,b;
int x[MAXN],y[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        if(a==n&&b==n) puts("Yes");         
        else if(a+b<n-1) puts("Yes");
        else puts("No");
    }
    return 0;
}
