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
int t,b,c,h,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&b,&c,&h);
        int x=min(b,c+h+1);
        printf("%d\n",2*x-1);
    }
    return 0;
}

