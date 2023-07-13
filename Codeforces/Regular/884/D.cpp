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
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==1) {printf("a\n"); continue;}
        if(n==2) {printf("ab\n"); continue;}
        int res=1;
        for(int i=2;i<=n;i++){
            if(n%i!=0){
                res=i; break;
            }
        }
        for(int i=1;i<=n;i++){
            int z=(i)%res;
            printf("%c",'a'+z);
        }
        printf("\n");
    }
    return 0;
}

