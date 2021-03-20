#include<bits/stdc++.h>
#define MAXN 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN];
int a[MAXN],b[MAXN];
int adda[MAXN],addb[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n;i++) b[i]=n+1-i;
    for(int i=1;i<=n;i++)
    {
        int res=i;
        adda[p[i]]+=res;
        addb[1]+=res; addb[p[i]+1]-=res;
    }
    for(int i=1;i<=n;i++)
    {
        adda[i]+=adda[i-1];
        a[i]+=adda[i];
    }
    for(int i=1;i<=n;i++)
    {
        addb[i]+=addb[i-1];
        b[i]+=addb[i];
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    puts("");
    return 0;
}