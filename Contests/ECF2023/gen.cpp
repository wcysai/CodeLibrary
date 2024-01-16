#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,a[MAXN];
mt19937 wcy(time(NULL));
int main(){
    scanf("%d%d%d",&T,&n,&m);
    printf("%d\n",T);
    while(T--){
        printf("%d %d\n",n,m);
        for(int i=1;i<=n-1;i++) printf("%d %d\n",i,i+1);
        for(int i=0;i<m-(n-1);i++){
            int u=wcy()%n+1,v=wcy()%n+1;
            while(u==v){
                u=wcy()%n+1; v=wcy()%n+1;
            }
            printf("%d %d\n",u,v);
        }
        for(int i=1;i<=n;i++) a[i]=wcy()%3+1;
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}

