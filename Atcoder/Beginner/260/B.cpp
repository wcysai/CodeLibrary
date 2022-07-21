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
int n,x,y,z,a[MAXN],b[MAXN],c[MAXN];
bool cmp1(int x,int y)
{
    if(a[x]==a[y]) return x<y;
    return a[x]>a[y];
}
bool cmp2(int x,int y)
{
    if(b[x]==b[y]) return x<y;
    return b[x]>b[y];
}
bool cmp3(int x,int y)
{
    if(a[x]+b[x]==a[y]+b[y]) return x<y;
    return a[x]+b[x]>a[y]+b[y];
}
int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for(int i=1;i<=n;i++) c[i]=i;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(c+1,c+n+1,cmp1);
    sort(c+x+1,c+n+1,cmp2);
    sort(c+x+y+1,c+n+1,cmp3);
    vector<int> v;
    for(int i=1;i<=x+y+z;i++) v.push_back(c[i]);
    sort(v.begin(),v.end());
    for(auto q:v) printf("%d\n",q);
    return 0;
}

