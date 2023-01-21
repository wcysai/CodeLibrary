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
int n,k,a[MAXN],p,q,r,s;
int main()
{
    scanf("%d%d%d%d%d",&n,&p,&q,&r,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=p;i<=q;i++) swap(a[i],a[r-p+i]);
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}

