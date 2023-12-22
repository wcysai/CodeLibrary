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
        if(k>n||k>x+1) printf("-1\n");
        else{
            if(x==k) printf("%d\n",(n-k)*(x-1)+(k-1)*k/2);
            else printf("%d\n",(n-k)*x+(k-1)*k/2);
        }
    }
    return 0;
}

