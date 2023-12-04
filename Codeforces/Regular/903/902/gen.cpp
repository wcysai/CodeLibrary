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
int n,k,a[MAXN];
mt19937 wcy(time(NULL));
int main()
{
    n=200000;
    for(int i=1;i<=n/2;i++){
        a[2*i-1]=a[2*i]=wcy()%500+1;
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}

