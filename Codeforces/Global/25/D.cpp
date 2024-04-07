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
ll n,k,a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        if(k>n) {puts("NO"); continue;}
        if(n==k) {puts("YES"); puts("1"); puts("1"); continue;}
        if(n>2*k-2){puts("YES");puts("2"); printf("%lld %d\n",n-k+1,1); continue;}
        puts("NO");
    }
    return 0;
}

