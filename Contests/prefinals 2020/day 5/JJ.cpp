#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n;
int ans[MAXN];
int main()
{
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=1000000;i++)
    {
        int x=(i-1)/3;
        int y=(i-2)/3;
        ans[i]=ans[x]+2+ans[y];
    }
    scanf("%d",&n);
    printf("%d\n",ans[n-3]);
    return 0;
}
