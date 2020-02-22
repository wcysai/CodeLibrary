#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int n,m,a[MAXN];
int main()
{
    freopen("E.in","w",stdout);
    n=m=5000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++) a[i]=i;
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=n;i++) printf("%d\n",a[i]);
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=n;i++) printf("%d %d\n",a[i],1);
}