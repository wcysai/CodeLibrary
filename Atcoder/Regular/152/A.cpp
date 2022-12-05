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
int n,l,a[MAXN],sum[MAXN];
int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==1) {puts("Yes"); return 0;}
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==2)
            if(s+i>=l) {puts("No"); return 0;}
        s+=a[i];
    }
    puts("Yes");
    return 0;
}

