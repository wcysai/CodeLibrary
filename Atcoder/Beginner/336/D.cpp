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
int n,k,a[MAXN];
int pre[MAXN],suf[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        pre[i]=max(pre[i],min(a[i],pre[i-1]+1));
    }
    for(int i=n;i>=1;i--){
        suf[i]=max(suf[i],min(a[i],suf[i+1]+1));
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,min(pre[i],suf[i]));
    printf("%d\n",ans);
    return 0;
}

