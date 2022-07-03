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
    int k;
    scanf("%d",&k);
    int h=21+k/60;
    int m=k%60;
    printf("%d:",h);
    if(m<10) printf("0");
    printf("%d\n",m);
    return 0;
}

