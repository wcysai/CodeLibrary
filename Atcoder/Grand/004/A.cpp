#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a%2==0||b%2==0||c%2==0) puts("0");
    else printf("%lld\n",min(1LL*a*b,min(1LL*b*c,1LL*a*c)));
    return 0;
}