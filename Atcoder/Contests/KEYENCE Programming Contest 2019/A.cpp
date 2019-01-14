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
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    sort(a,a+4);
    if(a[0]==1&&a[1]==4&&a[2]==7&&a[3]==9) puts("YES"); else puts("NO");
    return 0;
}
