#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN],b[MAXN],r[MAXN];
int s[MAXN],t[MAXN],u[MAXN];
ll ans[MAXN];
ll pos[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&s[i],&t[i],&u[i]);
    for(int i=1;i<=n;i++) pos[i+1]=pos[i]+a[i];
    return 0;
}

