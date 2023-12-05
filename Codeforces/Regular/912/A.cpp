#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k>1) {puts("YES"); continue;}
        bool f=true;
        for(int i=1;i<=n-1;i++) if(a[i]>a[i+1]) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

