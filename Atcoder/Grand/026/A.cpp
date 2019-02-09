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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=1,ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            ans+=cnt/2;
            cnt=1;
        }
    }
    ans+=cnt/2;
    printf("%d\n",ans);
    return 0;
}

