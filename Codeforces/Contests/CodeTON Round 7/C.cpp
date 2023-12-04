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
int t,n,x,a[MAXN],b[MAXN],c[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        vector<P> v;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); v.push_back(P(a[i],i));}
        sort(v.begin(),v.end());
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1);
        bool f=true;
        for(int i=1;i<=x;i++) if(v[n-1-x+i].F<=b[i]) f=false;
        for(int i=1;i<=n-x;i++) if(v[i-1].F>b[x+i]) f=false;
        if(!f) {puts("No"); continue;}
        puts("Yes");
        for(int i=1;i<=x;i++) c[v[n-1-x+i].S]=b[i];
        for(int i=1;i<=n-x;i++) c[v[i-1].S]=b[x+i];
        for(int i=1;i<=n;i++) printf("%d%c",c[i],i==n?'\n':' ');
    }
    return 0;
}

