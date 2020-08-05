#include<bits/stdc++.h>
#define MAXN 20000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if((1LL*n*(n-1)/2)%n!=k) puts("-1");
    else if(n&1)
    {
        printf("%d",n);
        for(int i=1;i<=(n-1)/2;i++) printf(" %d %d",i,n-i);
    }
    else 
    {
        printf("%d %d",n,n/2);
        for(int i=1;i<=n/2-1;i++) printf(" %d %d",i,n-i);
    }
    return 0;
}