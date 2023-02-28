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
int n,k,a[MAXN];
void go(int l,int r){
    if(l==r-1) swap(a[l],a[r]);
    else {
        go(l,r-1); go(l+1,r);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i]=i;
    go(1,n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}

