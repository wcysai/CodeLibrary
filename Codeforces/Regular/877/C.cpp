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
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int x=2,y=1;
        for(int i=1;i<=n;i++){
            if(x<=n){
                for(int j=1;j<=m;j++) printf("%d%c",(x-1)*m+j,j==m?'\n':' ');
                x+=2;
            }
            else{
                for(int j=1;j<=m;j++) printf("%d%c",(y-1)*m+j,j==m?'\n':' ');
                y+=2;
            }
        }
    }
    return 0;
}

