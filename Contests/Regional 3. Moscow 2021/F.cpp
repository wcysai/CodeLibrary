#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
    scanf("%d",&n);
    if(n<=3) puts("-1");
    else 
    {
        printf("%d\n",n+1);
        printf("1 2\n");
        printf("2 3\n");
        printf("3 4\n");
        printf("1 4\n");
        printf("2 4\n");
        for(int i=5;i<=n;i++) printf("%d %d\n",i-1,i);
    }
    return 0;
}