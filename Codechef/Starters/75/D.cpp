#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bitset<90005> dp[MAXN];
int main()
{   
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        dp[0].reset(); dp[0].set(0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
        }
        if((s&1)||(!dp[n].test(s/2))){
            puts("-1"); continue;
        }
        vector<int> v1,v2;
        int now=s/2;
        for(int i=n;i>=1;i--){
            if(now>=a[i]&&dp[i-1].test(now-a[i])){
                v1.push_back(i);
                now-=a[i];
            }
            else v2.push_back(i);
        }
        vector<P> ans;
        while(v1.size()||v2.size()){
            int x=v1.back(),y=v2.back();
            int val=min(a[x],a[y]);
            ans.push_back(P(x,y));
            a[x]-=val; a[y]-=val;
            if(!a[x]) v1.pop_back(); 
            if(!a[y]) v2.pop_back();
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

