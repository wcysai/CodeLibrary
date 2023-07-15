#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll s=0,mini=0,cur=0;
        ll last=0; 
        ll k=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s+=a[i]; cur+=a[i]; if(cur<mini) {mini=cur; k=last;} if(cur>0) {cur=0; last=s;}}
        printf("%lld\n",k);
    }
    return 0;
}

