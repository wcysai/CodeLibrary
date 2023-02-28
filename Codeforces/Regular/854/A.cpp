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
int t,n,m,ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) ans[i]=-1;
        int now=n;
        set<int> s;
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(s.count(x)) continue;
            if(now==0) continue;
            s.insert(x);
            ans[now]=i; now--;
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}

