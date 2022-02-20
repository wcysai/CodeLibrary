#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],cnt[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=4*n-1;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]!=4)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}