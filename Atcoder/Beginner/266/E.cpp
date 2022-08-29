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
typedef long double db;
int n,k,a[MAXN];
db ans[MAXN];
int main()
{
    scanf("%d",&n);
    ans[1]=3.5;
    for(int i=2;i<=n;i++)
    {
        ans[i]=0.0;
        for(int j=1;j<=6;j++)
            ans[i]+=1.0/6*(max(ans[i-1],(db)1.0*j));
    }
    printf("%.15Lf\n",ans[n]);
    return 0;
}

