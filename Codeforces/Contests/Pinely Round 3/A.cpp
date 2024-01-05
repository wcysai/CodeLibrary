#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],x[MAXN],y[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        bool f1=false,f2=false,f3=false,f4=false;
        for(int i=1;i<=n;i++){
            if(x[i]<0) f1=true;
            if(x[i]>0) f2=true;
            if(y[i]<0) f3=true;
            if(y[i]>0) f4=true;
        }
        if(f1&&f2&&f3&&f4) puts("NO"); else puts("YES");
    }
    return 0;
}

