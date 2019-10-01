#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[5];
int main()
{
    int maxi=0;
    ll sum=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        maxi=max(maxi,a[i]);
    }
    if(maxi*2<=sum) printf("%lld\n",sum/2);
    else printf("%lld\n",sum-maxi);
    return 0;
}

