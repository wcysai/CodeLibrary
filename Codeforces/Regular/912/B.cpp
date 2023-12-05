#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN][MAXN];
int res[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++){
            res[i]=(1<<30)-1;
            for(int j=1;j<=n;j++) if(i!=j) res[i]&=a[i][j];
        }
        bool f=true;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if((res[i]|res[j])!=a[i][j]) f=false;
        if(f) {puts("YES"); for(int i=1;i<=n;i++) printf("%d%c",res[i],i==n?'\n':' ');} else puts("NO");
    }
    return 0;
}

