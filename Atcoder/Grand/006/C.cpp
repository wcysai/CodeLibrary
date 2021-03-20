#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],d[MAXN];
ll x[MAXN];
vector<int> perm;
ll k;
vector<int> mul(vector<int> a,vector<int> b)
{
    vector<int> c(n-1,0);
    for(int i=0;i<n-1;i++) c[i]=a[b[i]];
    return c;
}
vector<int> get_pow(vector<int> v,ll k)
{
    vector<int> res(n-1);
    for(int i=0;i<n-1;i++) res[i]=i;
    while(k)
    {
        if(k&1) res=mul(res,v);
        v=mul(v,v);
        k>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=n-1;i++) d[i-1]=x[i+1]-x[i];
    scanf("%d%lld",&m,&k);
    perm.resize(n-1);
    for(int i=0;i<n-1;i++) perm[i]=i;
    for(int i=1;i<=m;i++) 
    {
        int y;
        scanf("%d",&y);
        swap(perm[y-2],perm[y-1]);
    }
    vector<int> res=get_pow(perm,k);
    for(int i=2;i<=n;i++)
        x[i]=x[i-1]+d[res[i-2]];
    for(int i=1;i<=n;i++) printf("%lld\n",x[i]);
    return 0;
}