#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v[2*MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        v[100000+l].push_back(0);
        v[100000+r].push_back(1);
    }
    v[100000].push_back(0); v[100000].push_back(1);
    ll ans=0;
    int l=0,r=n+1;
    for(int i=0;i<=200000;i++)
    {
        for(auto x:v[i]) if(x==1) l++; else r--;
        ans+=min(l,r);
    }
    printf("%lld\n",2*ans);
    return 0;
}

