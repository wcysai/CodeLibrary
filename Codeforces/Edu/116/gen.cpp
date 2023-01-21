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
int n,q,a[MAXN];
mt19937 wcy(time(NULL));
int main()
{
    n=q=200000;
    printf("%d\n",n);
    for(int i=2;i<=n;i++){
        int p=wcy()%(i-1)+1;
        printf("%d %d\n",p,i);
    }
    printf("%d\n",q);
    for(int i=0;i<q;i++){
        int v=wcy()%n+1,k=wcy()%200000+1;
        printf("%d %d\n",v,k);
    }
    return 0;
}

