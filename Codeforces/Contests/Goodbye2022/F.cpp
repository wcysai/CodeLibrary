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
int y;
ll n,x;
int main()
{
    scanf("%lld%lld%d",&n,&x,&y);
    if(n%2==0) {puts("0"); return 0;}
    int ans=0;
    for(int i=0;i<20;i++){
        int res=0;
        for(int mask=0;mask<(1<<20);mask++){
            if(!(mask&(1<<i))) continue;
            if((mask&y)!=mask) continue;
            ll m1=n*mask-(1<<i),m2=x-(1<<i);
            if(m2<0||m1<0) continue;
            if((m2&m1)==m2) res^=(1<<i);
        }
        ans^=res;
    }
    printf("%d\n",ans);
    return 0;
}

