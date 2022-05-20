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
int a,b,p;
int main()
{
    scanf("%d%d%d",&p,&a,&b);
    int ans=b;
    for(int i=0;i<p;i++)
    {
        b=1LL*b*a%p;
        ans=min(ans,b);
    }
    printf("%d\n",ans);
    return 0;
}

