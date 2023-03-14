#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a[3];
signed main()
{
    scanf("%lld",&T);
    while(T--){
        for(int i=0;i<3;i++) scanf("%lld",&a[i]);
        sort(a,a+3);
        if((a[0]+a[1]+a[2])%3) {puts("-1"); continue;}
        int avg=(a[0]+a[1]+a[2])/3;
        bool f=true;
        int ans=0;
        for(int i=0;i<3;i++){
            if((a[i]+avg)&1) f=false;
            int z=(a[i]-avg)/2;
            ans+=max(-z,z);
        }
        if(!f) puts("-1"); else printf("%lld\n",ans/2);
    }
    return 0;
}

