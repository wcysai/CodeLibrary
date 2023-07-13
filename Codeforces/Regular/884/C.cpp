#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,c[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&c[i]);
        }
        if(n==1) {printf("%d\n",c[1]); continue;}
        vector<int> v1,v2;
        for(int i=1;i<=n;i+=2) v1.push_back(c[i]);
        for(int i=2;i<=n;i+=2) v2.push_back(c[i]);
        ll x=0,y=0;
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end(),greater<int>());
        for(int i=0;i<(int)v1.size();i++) if(v1[i]>=0) x+=v1[i];
        for(int i=0;i<(int)v2.size();i++) if(v2[i]>=0) y+=v2[i];
        if(v1[0]<0) x=v1[0];
        if(v2[0]<0) y=v2[0];
        printf("%lld\n",max(x,y));
    }
    return 0;
}

