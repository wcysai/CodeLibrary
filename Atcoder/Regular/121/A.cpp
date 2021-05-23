#include<bits/stdc++.h>
#define MAXN 200005
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
    ll maxi=0,sum=0,s=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        s+=sum;
        maxi=max(maxi,1LL*a[i]);
        printf("%lld\n",s+1LL*i*maxi);
    }
    return 0;
}