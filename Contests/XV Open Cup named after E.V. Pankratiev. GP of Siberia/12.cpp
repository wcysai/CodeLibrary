#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef __int128_t ll;
typedef pair<int,int> P;
int n;
long long m;
int main()
{
    cin>>n>>m;
    ll ans=1;
    for(ll i=1;i<=n;i++) ans*=(2*i);
    if(ans>=m) puts("Harshat Mata"); else puts("Nope");
    return 0;
}
