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
int n,p,q,k,a[MAXN];
int main()
{
    scanf("%d%d%d",&n,&p,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) p=min(p,q+a[i]);
    printf("%d\n",p);
    return 0;
}

