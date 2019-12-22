#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
vector<int> v,vv;
ll d[MAXN],s[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=k) 
        {
            v.push_back(a[i]);
            vv.push_back(i);
        }
    }
    ll inv=0;
    for(int i=0;i<k;i++)
    {
        inv+=(k-1-i-sum(v[i]));
        add(v[i],1);
    }
    int mid=vv[k/2];
    int l=mid-k/2;
    for(int i=0;i<k;i++)
    {
        inv+=abs(vv[i]-(l+i));
    }
    printf("%lld\n",inv);
    return 0;
}