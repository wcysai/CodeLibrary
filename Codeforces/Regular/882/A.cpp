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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<int> v;
        for(int i=1;i<=n-1;i++){
            v.push_back(max(a[i+1]-a[i],a[i]-a[i+1]));
        }
        sort(v.begin(),v.end(),greater<int>());
        ll s=0;
        for(int i=k-1;i<(int)v.size();i++) s+=v[i];
        printf("%lld\n",s);
    }
    return 0;
}

