#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
ll ucost[MAXN],dcost[MAXN];
vector<int> v;
int need;
bool lab[MAXN];
bool cmp(int x,int y)
{
    return ucost[x]<ucost[y];
}
int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    ll s=0;
    for(int i=1;i<=k;i++)
    {
        ll res=1LL*m*a[i]/n;
        s+=res;
        dcost[i]=max(1LL*res*n-1LL*m*a[i],1LL*m*a[i]-1LL*res*n);
        ucost[i]=max(1LL*(res+1)*n-1LL*m*a[i],1LL*m*a[i]-1LL*(res+1)*n);
        assert(dcost[i]+ucost[i]==n);
    }
    assert(s<=m);
    need=m-s;
    for(int i=1;i<=k;i++) v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    memset(lab,false,sizeof(lab));
    for(int i=0;i<need;i++) lab[v[i]]=true;
    for(int i=1;i<=k;i++)
        printf("%lld%c",(1LL*m*a[i]/n)+(lab[i]?1:0),(i==k?'\n':' '));
    return 0;
}