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
int n,x,a[MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int ans=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]>x)
        {
            printf("%d\n",ans);
            return 0;
        }
        ans++;
        x-=a[i];
    }
    if(x) ans--;
    printf("%d\n",ans);
    return 0;
}

