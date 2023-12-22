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
int t,n,m,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int s=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s^=a[i];}
        int ss=0,sss=0;
        for(int i=1;i<=m;i++) {scanf("%d",&b[i]); ss|=b[i];}
        for(int i=1;i<=n;i++) sss^=(a[i]|ss);
        printf("%d %d\n",min(s,sss),max(s,sss));
    }
    return 0;
}

