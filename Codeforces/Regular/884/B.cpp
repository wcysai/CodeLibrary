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
        scanf("%d",&n);
        if(n==1) printf("1\n");
        else if(n==2) printf("1 2\n");
        else{
            for(int i=1;i<=n;i++) a[i]=0;
            a[(n+1)/2]=1;
            a[1]=2; a[n]=3;
            int tot=4;
            for(int i=1;i<=n;i++) if(!a[i]) a[i]=tot++;
            for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
        }
    }
    return 0;
}

