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
int t,n,m,k,a[MAXN],b[MAXN],c[MAXN];
bool check(int x){
    for(int i=1;i<=x;i++) if(c[i]>=b[n-x+i]) return false;
    return true;
}
int get_ans(int x){
    c[1]=x;
    for(int i=2;i<=n;i++) c[i]=a[i];
    sort(c+1,c+n+1);
    int l=0,r=n+1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    return l;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=2;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1);
        int res=get_ans(1);
        int l=1,r=m+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(get_ans(mid)==res) l=mid; else r=mid;
        }
        printf("%lld\n",1LL*(n-res)*l+1LL*(n-res+1)*(m-l));
    }
    return 0;
}

