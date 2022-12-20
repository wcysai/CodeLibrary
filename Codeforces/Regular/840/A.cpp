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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int x=0;
        for(int i=0;i<=10;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++) if(a[j]&(1<<i)) cnt++;
            if(cnt!=0&&cnt!=n) x+=(1<<i);
        }
        printf("%d\n",x);
    }
    return 0;
}

