#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,d,a[MAXN][MAXN];
int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<2*d;i++){
        int j=(i+d)%(2*d);
        int sum=0;
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++){
                int need=((a[x][y]%(2*d))+4*d-((x+y)&1?i:j))%(2*d);
                need=min(2*d-need,need);
                sum+=need;
            }
        if(2*sum<=d*n*n){
            //printf("sum=%d\n",sum);
            for(int x=1;x<=n;x++)
                for(int y=1;y<=n;y++){
                    int need=((a[x][y]%(2*d))+4*d-((x+y)&1?i:j))%(2*d);
                    if(need<=d) a[x][y]-=need;
                    else a[x][y]+=(2*d-need);
                }
            for(int x=1;x<=n;x++)
                for(int y=1;y<=n;y++)
                    printf("%d%c",a[x][y],y==n?'\n':' ');
            return 0;
        }
    }
    return 0;
}
