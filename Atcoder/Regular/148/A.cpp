#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool check(int d)
{
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        s.insert(a[i]%d);
        if(s.size()==2) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[1]==a[n])
    {
        puts("1");
        return 0;
    }
    int g=0;
    for(int i=1;i<=n-1;i++)
        if(a[i]!=a[i+1])
            g=__gcd(a[i+1]-a[i],g);
    if(g==1) puts("2"); else puts("1");
    return 0;
}

