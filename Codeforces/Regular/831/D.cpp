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
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        bool f=true;
        for(int i=1;i<=k;i++) 
            if(i-(k+1-a[i])>=n*m-3) f=false;
        if(f) puts("YA"); else puts("TIDAK");
    }
    return 0;
}

