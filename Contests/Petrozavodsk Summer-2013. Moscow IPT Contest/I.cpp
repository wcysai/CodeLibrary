#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)&1) printf("B"); else printf("A");
    return 0;
}
