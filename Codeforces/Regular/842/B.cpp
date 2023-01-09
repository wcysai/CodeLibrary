#pragma GCC optimize(3)
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
int r[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            r[a[i]]=i;
        }
        int cnt=1;
        for(int i=2;i<=n;i++) if(r[i]>r[i-1]) cnt++; else break;
        printf("%d\n",(n-cnt+k-1)/k);
    }
    return 0;
}

