#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,k,a[MAXN];
db maxi,mini;
bool cmp(int x,int y){
    if(1LL*x*y<0) return x<y;
    else return x>y;
}
void upd(int x,int y,int z){
    maxi=max(maxi,(db)1.0*(x+y+z)/(1LL*x*y*z));
    mini=min(mini,(db)1.0*(x+y+z)/(1LL*x*y*z));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    maxi=-1e9,mini=1e9;
    upd(a[1],a[2],a[3]);
    upd(a[1],a[2],a[n]);
    upd(a[1],a[n-1],a[n]);
    upd(a[n-2],a[n-1],a[n]);
    printf("%.15Lf\n%.15Lf\n",mini,maxi);
    return 0;
}

