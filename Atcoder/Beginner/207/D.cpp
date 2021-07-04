#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
    bool f=false;
    for(int i=1;i<=n;i++)
    {
        int dx=c[i]-a[1],dy=d[i]-b[1];
    }
    return 0;
}