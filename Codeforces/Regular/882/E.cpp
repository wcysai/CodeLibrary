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
int calc(int x,int y,int z){
    int p=x+y+z;

    return p*(p-2*x)*(p-2*y)*(p-2*z);
}
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    printf("%d\n",calc(x,y,z));
    return 0;
}

