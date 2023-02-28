#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n,k;
ll solve(ll n,ll k){
    if(n==2) return 3-k;
    ll maxi=1;
    while(maxi*2<n) maxi*=2;
    if(n==maxi+1){
        if(k==n-1) return n;
        else if(k==1) return 2;
        if(k&1) return solve(n-1,k-1); else return solve(n-1,k+1);
    } 
    if(k<=n-maxi) return solve(n-maxi,k);
    else if(k>maxi) return maxi+solve(n-maxi,k-maxi);
    else return k;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",solve(n,k));
    }
    return 0;
}

