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
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    k+=n/2;
    int s=0;
    for(int i=1;i<=n;i++) s+=a[i];
    if(s<=k) puts("Yes"); else puts("No");
    return 0;
}