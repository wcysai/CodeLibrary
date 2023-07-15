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
    for(int i=1;i<=7*n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=7*i-6;j<=7*i;j++) sum+=a[j];
        printf("%d ",sum);
    }
    return 0;
}

