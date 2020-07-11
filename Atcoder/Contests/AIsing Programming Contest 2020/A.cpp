#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,r,d,a[MAXN];
int main()
{
    scanf("%d%d%d",&l,&r,&d);
    printf("%d\n",r/d-(l-1)/d);
}