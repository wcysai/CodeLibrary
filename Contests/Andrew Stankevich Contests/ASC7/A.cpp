#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",j==1?(i==1?99:0):100);
        }
        puts("");
    }
    return 0;
}
