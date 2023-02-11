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
int t,n,m,d,p[MAXN],pos[MAXN],a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            pos[p[i]]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            a[i]=pos[a[i]];
        }
        int ans=INF;
        for(int i=1;i<=m-1;i++){
            if(a[i]>=a[i+1]||a[i]<a[i+1]-d) {ans=0; break;}
            ans=min(ans,a[i+1]-a[i]);
            if(d<n-1) ans=min(ans,d+1-(a[i+1]-a[i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}

