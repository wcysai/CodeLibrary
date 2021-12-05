#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN];
string str;
map<P,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    ll ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(x[i]!=x[j]) continue;
            ans+=mp[P(min(y[i],y[j]),max(y[i],y[j]))];
            mp[P(min(y[i],y[j]),max(y[i],y[j]))]++;
        }
    printf("%lld\n",ans);
    return 0;
}