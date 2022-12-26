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
int n,x,y,z,a[MAXN],b[MAXN],c[MAXN];
set<P> A,B,C,AB,BA,AC,CA,BC,CB;
//simulating min-cost flow
int main()
{
    scanf("%d%d%d",&x,&y,&z);
    for(int i=1;i<=x+y+z;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    return 0;
}

