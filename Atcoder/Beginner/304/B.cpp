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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    int now=1000;
    for(int i=3;i<=9;i++){
        if(n<=now-1){
            int x=now/1000;
            printf("%d\n",(n/x)*x);
            break;
        }
        now*=10;
    }
    return 0;
}

