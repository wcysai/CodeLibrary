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
int t,n,k,x,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&x);
        if(k==1&&x==1){
            puts("NO"); continue;
        }
        if(x==1&&k==2){
            if(n&1) {puts("NO"); continue;}
            puts("YES");
            printf("%d\n",n/2);
            for(int i=1;i<=n/2;i++) printf("%d%c",2,i==n/2?'\n':' ');
            continue;
        }
        puts("YES");
        if(x==1){
            if(n&1){
                printf("%d\n",(n-1)/2);
                printf("%d ",3);
                for(int i=1;i<=(n-3)/2;i++) printf("%d ",2);
                printf("\n");
            }
            else{
                printf("%d\n",n/2);
                for(int i=1;i<=n/2;i++) printf("%d ",2);
                printf("\n");
            }
        }
        else{
            printf("%d\n",n);
            for(int i=1;i<=n;i++) printf("%d%c",1,i==n?'\n':' ');
        }

    }
    return 0;
}

