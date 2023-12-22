#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,ans,a[MAXN],b[MAXN];
vector<int> dis;
void check(int v){
    int x=upper_bound(a+1,a+n+2,v)-a-1;
    int y=m-(lower_bound(b+1,b+m+2,v)-b)+1;
    if(x>=y) ans=min(ans,v);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    a[n+1]=b[m+1]=INF;
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ans=INF;
    for(int i=1;i<=n;i++) check(a[i]);
    for(int i=1;i<=m;i++) check(b[i]+1);
    for(int i=1;i<=m;i++) check(b[i]);
    check(1);
    printf("%d\n",ans);
    return 0;
}

