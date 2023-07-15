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
int t,n,x,a[3][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        for(int j=0;j<3;j++)
            for(int i=1;i<=n;i++) scanf("%d",&a[j][i]);
        int cur=0;
        for(int i=0;i<3;i++){
            int now=0;
            for(int j=1;j<=n;j++) {if((x|a[i][j])==x) now|=a[i][j]; else break;}
            cur|=now;
        }
        if(cur==x) puts("Yes"); else puts("No");
    }
    return 0;
}

