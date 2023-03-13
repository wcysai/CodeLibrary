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
int T,n,k,d,w,t[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&k,&d,&w);
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        t[n+1]=INF;
        int now=1,ans=0;
        while(now<=n){
            int last=t[now]+w+d;
            int id=upper_bound(t+1,t+n+2,last)-t-1;
            id=min(id,now+k-1);
            ans++;
            now=id+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

