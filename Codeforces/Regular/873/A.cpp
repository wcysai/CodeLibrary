#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN],b[MAXN];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1);
        vector<int> cnt;
        for(int i=1;i<=n;i++){
            int id=lower_bound(b+1,b+n+1,a[i])-b;
            int num=id-1;
            cnt.push_back(num);
        }
        sort(cnt.begin(),cnt.end());
        int res=1;
        for(int i=0;i<(int)cnt.size();i++) res=1LL*res*(cnt[i]-i)%MOD;
        printf("%d\n",res);
    }
    return 0;
}

