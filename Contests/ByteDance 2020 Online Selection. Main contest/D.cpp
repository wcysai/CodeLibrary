#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    ll even=0,odd=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(i&1)
        {
            even+=x/2;
            odd+=(x+1)/2;
        }
        else
        {
            even+=(x+1)/2;
            odd+=x/2;
        }
    }
    printf("%lld\n",min(even,odd));
    return 0;
}