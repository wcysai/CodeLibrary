#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+10;
pi a[maxn];
ll sum,ans[maxn],m;
int n,b[maxn];
void add(int x,int y){
    while (x<maxn) b[x]+=y,x+=x&(-x);
}
int qry(int x){
    int ret=0;
    while (x) ret+=b[x],x-=x&(-x);
    return ret;
}
int main(){
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int u=a[i].S;
        ans[u]=1ll*(i-1)*a[i].F-sum+qry(u);
        add(u,1); sum+=a[i].F;
    }
    for (int i=1;i<=n;i++){
        if (ans[i]<=m-2) printf("%lld\n",ans[i]);
        else printf("-1\n");
    }
}