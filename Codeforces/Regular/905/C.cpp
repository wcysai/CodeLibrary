#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,k,a[MAXN];
int l[MAXN],r[MAXN],x[MAXN];
ll delta[MAXN],ans[MAXN];
set<int> s;
void upd(int pos,int x){
    delta[pos]+=x;
    if(delta[pos]==0&&s.count(pos)) s.erase(pos);
    else if(delta[pos]!=0) s.insert(pos);
}
bool is_smaller(){
    if(s.size()&&delta[*s.begin()]<0) return true;
    else return false;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        s.clear();
        for(int i=1;i<=n;i++) delta[i]=0;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            scanf("%d%d%d",&l[i],&r[i],&x[i]);
        }
        int cur=0;
        for(int i=1;i<=q;i++){
            upd(l[i],x[i]); upd(r[i]+1,-x[i]);
            if(is_smaller()){
                for(int j=cur+1;j<=i;j++) {upd(l[j],-x[j]); upd(r[j]+1,x[j]);}
                cur=i;
            }
        }
        for(int i=1;i<=n;i++) ans[i]=0;
        for(int i=1;i<=cur;i++){
            ans[l[i]]+=x[i]; ans[r[i]+1]-=x[i];
        }
        for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
        for(int i=1;i<=n;i++) printf("%lld%c",ans[i]+a[i],i==n?'\n':' ');
    }
    return 0;
}

