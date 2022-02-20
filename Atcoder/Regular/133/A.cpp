#include<bits/stdc++.h>
#define MAXN 200005
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
    int now=-1,maxi=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxi=max(maxi,a[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            now=a[i];
            break;
        }
    }
    if(now==-1) now=maxi;
    for(int i=1;i<=n;i++) if(a[i]!=now) printf("%d ",a[i]);
    puts("");
    return 0;
}