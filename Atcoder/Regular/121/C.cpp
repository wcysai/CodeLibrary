#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> dis;
vector<int> posa[MAXN],posb[MAXN];
int perm[MAXN];
int bit[MAXN+1];
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
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]+i);
    }
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&b[i]);
        dis.push_back(b[i]+i);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=0;i<n;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i]+i)-dis.begin();
        posa[id].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),b[i]+i)-dis.begin();
        posb[id].push_back(i);
    }
    int sz=(int)dis.size();
    ll ans=0;
    for(int i=0;i<sz;i++)
    {
        if(posa[i].size()!=posb[i].size())
        {
            puts("-1");
            return 0;
        }
        for(int j=0;j<(int)posa[i].size();j++) perm[posa[i][j]+1]=posb[i][j]+1;
    }
    for(int i=1;i<=n;i++)
    {
        add(perm[i],1); 
		ans+=i-sum(perm[i]);
    }
    printf("%lld\n",ans);
    return 0;
}