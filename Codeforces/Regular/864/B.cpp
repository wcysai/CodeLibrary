#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        int cnt=0;
        for(int i=1;i<=(n+1)/2;i++)
            for(int j=1;j<=n;j++){
                int x=(n+1-i),y=(n+1-j);
                if(x==i&&y>=j) continue;
                if(a[i][j]!=a[x][y]) cnt++;
            }
        if((k>=cnt)&&((k-cnt)%(n&1?1:2)==0)) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

