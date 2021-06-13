#include<bits/stdc++.h>
#define MAXN 100005
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
    if(n==4) puts("0 2 0 2");
    else if(n==5) puts("0 0 2 1 2");
    else if(n>=7)
    {
        a[n-1-0]=n-4;
        a[n-1-(n-4)]=1;
        a[n-1-1]=2;
        a[n-1-2]=1;
        for(int i=0;i<=n-1;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
    }
    else puts("-1");
    return 0;
}