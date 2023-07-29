#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],ord[MAXN];
bool cmp(int x,int y){
    if(a[x]!=a[y]) return a[x]>a[y];
    return x<y;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(a[i]%k==0) a[i]=k; else a[i]%=k;}
        for(int i=1;i<=n;i++) ord[i]=i;
        sort(ord+1,ord+n+1,cmp);
        for(int i=1;i<=n;i++) printf("%d%c",ord[i],i==n?'\n':' ');
    }
    return 0;
}

