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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int r=n,l=1;
        for(int i=1;i<=n;i++){
            if(i&1) {printf("%d ",r); r--;}
            else {printf("%d ",l); l++;}
        }
        puts("");
    }
    return 0;
}

