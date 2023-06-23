#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 1000005
#define INF 1000000000
using namespace std;
typedef long long ll;
int bit[2*MAXM+1],n,m;
vector<int> dis;
vector<int> a[MAXN];
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
    while(i<=n*m)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; scanf("%d",&x);
            a[i].push_back(x); dis.push_back(x);
        }
    }
    sort(dis.begin(),dis.end());
    for(int i=1;i<=n;i++)
        for(auto &x:a[i]) x=lower_bound(dis.begin(),dis.end(),x)-dis.begin()+1;
    int s=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            ans+=(s-sum(a[i][j]));
        }
        for(int j=0;j<m;j++) add(a[i][j],1);
        s+=m;
    }
    printf("%lld\n",ans+1LL*n*(n-1)/2*(1+m)*m/2);
    return 0;
}
