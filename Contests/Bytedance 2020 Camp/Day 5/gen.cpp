#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int a[MAXN],n,q,k,s;
int main()
{
    freopen("J.in","w",stdout);
    n=200000; q=10000000;
    k=1000000000; s=888;
    for(int i=0;i<n;i++) a[i]=i;
    random_shuffle(a,a+n);
    printf("%d %d %d %d\n",n,q,k,s);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    puts("");
}