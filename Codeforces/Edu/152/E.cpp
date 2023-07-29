#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int st[MAXN],L[MAXN],R[MAXN];
int fa[MAXN],ls[MAXN],rs[MAXN],root;
ll ans=0;
void dfs(int v,int l,int r){
   // printf("v=%d l=%d r=%d\n",v,l,r);
    if(l>=r) return;
    if(v-l<=r-v){
        int pos=n+1,mini=INF;
        for(int i=v;i>=l;i--){
            if(a[i]<mini){
                pos=R[i];
                mini=a[i];
            }
            ans+=min(pos-1,r)-v+1;
            if(i==v) ans--;
           // printf("i=%d pos=%d\n",i,pos);
           // printf("ans=%lld\n",ans);
        }
    }
    else{
        int pos=0,mini=INF;
        for(int i=v;i<=r;i++){
            if(a[i]<mini){
                pos=L[i];
                mini=a[i];
            }
            ans+=max(0,pos-l+1);
          //  printf("i=%d pos=%d\n",i,pos);
          //  printf("ans=%lld\n",ans);
        }
    }
    dfs(ls[v],l,v-1); dfs(rs[v],v+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int t=0;
	for(int i=1;i<=n;i++){
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--){
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    t=0;
	for(int i=1;i<=n;i++){
        while(t&&a[st[t-1]]<a[i]) ls[i]=st[--t];
        if(t) rs[st[t-1]]=i;
        st[t++]=i;
    }
    for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
    for(int i=1;i<=n;i++) if(!fa[i]) root=i;
    dfs(root,1,n);
    printf("%lld\n",ans);
    return 0;
}

