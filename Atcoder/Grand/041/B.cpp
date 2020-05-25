#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,v,p;
int a[MAXN];
bool check(int id)
{
    if(id<=p) return true;
    if(a[id]+m<a[p]) return false;
    ll s=1LL*(n-id+1)*m;
    for(int i=1;i<id;i++)
    {
        if(i<=p-1) s+=m;
        else s+=(a[id]+m-a[i]);
    }
    return s>=1LL*m*v;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&v,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
}