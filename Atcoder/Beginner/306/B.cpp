#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    ll ans=0;
    for(int i=0;i<64;i++){
        int x; cin>>x;
        if(x) ans+=(((ll)1)<<i);
    }
    cout<<ans<<endl;
    return 0;
}

