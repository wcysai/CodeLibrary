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
int D,L,N;
int a[MAXN];
int main()
{
    scanf("%d%d%d",&D,&L,&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    sort(a+1,a+N+1);a[0]=0;a[N+1]=D;
    db ans=0;
    for(int i=1;i<=N+1;i++)
    {
        if(a[i]-a[i-1]<=L) continue;
        db len=a[i]-a[i-1]-L;
        ans+=(len/2)*(len/2);
    }
    printf("%.15Lf\n",ans/D);
    return 0;
}

