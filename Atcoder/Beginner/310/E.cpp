#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[MAXN];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    int a=0,b=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int c,d;
        if(str[i]=='0'){
            c=1;
            d=a+b;
        }
        else{
            c=b;
            d=a+1;
        }
        a=c; b=d;
        ans+=b;
    }
    printf("%lld\n",ans);
    return 0;
}

