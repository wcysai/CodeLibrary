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
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n&1)
        {
            for(int i=1;i<=n;i++) printf("%d%c",1,(i==n?'\n':' '));
        }
        else if(n==2) printf("1 3\n");
        else
        {
            printf("1 2 3");
            for(int i=1;i<=n-3;i++) printf(" 2");
            printf("\n");
        }
    }
    return 0;
}

