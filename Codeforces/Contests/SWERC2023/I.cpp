#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    ull sa=0,sb=0;
    for(int i=1;i<=m;i++) sa+=(a[i]+1);
    for(int i=1;i<=n;i++) sb+=(b[i]+1);
    if(sa>sb) puts("ALICE");
    else if(sa<sb) puts("BOB");
    else puts("TIED");
    return 0;
}

