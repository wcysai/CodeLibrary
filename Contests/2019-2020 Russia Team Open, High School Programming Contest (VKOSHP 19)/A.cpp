#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],mini;
int main()
{
    scanf("%d",&n);
    mini=INF;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=(a[i]&1?a[i]:a[i]-1);
        mini=min(mini,(a[i]&1?a[i]:a[i]-1));
    }
    if(n&1) printf("%d\n",sum); else printf("%d\n",sum-mini);
    return 0;
}