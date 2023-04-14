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
int t,n,m,a[MAXN];
set<int> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        s.insert(i^(n-i));
    ll sum=0;
    for(auto x:s) {printf("%d ",x); sum+=x;}
    printf("\n");
    printf("sz=%d\n",(int)s.size());
    printf("sum=%lld\n",sum);
    return 0;
}

