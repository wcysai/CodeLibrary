#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXN];
ull hsh[MAXN];
mt19937_64 rng(time(NULL));
map<ull,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) prime[i]=1;
    for(int i=1;i<=n;i++) hsh[i]=0;
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            ll val=rng();
            for(int j=i;j<=n;j+=i)
            {
                prime[j]=0;
                int cnt=0,tmp=j;
                while(tmp%i==0) {cnt++; tmp/=i;}
                if(cnt&1) hsh[j]^=val;
            }
        }
    }
    for(int i=1;i<=n;i++) mp[hsh[i]]++;
    ll ans=0;
    for(auto p:mp)
        ans+=1LL*p.S*p.S;
    printf("%lld\n",ans);
    return 0;
}

