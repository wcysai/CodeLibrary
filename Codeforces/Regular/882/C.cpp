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
int t,n,a[MAXN];
bool has[(1<<8)];
int main()
{
    scanf("%d",&t);
    while(t--){
        memset(has,0,sizeof(has));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
        int ans=0,now=0;
        has[0]=true;
        for(int i=1;i<=n;i++){
            now^=a[i];
            for(int j=0;j<(1<<8);j++) if(has[j]) ans=max(ans,now^j);
            has[now]=true;
        }
        printf("%d\n",ans);
    }
    return 0;
}

