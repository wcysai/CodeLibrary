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
int n,m,x,t,d;
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&x,&t,&d);
    if(m<=x) printf("%d\n",t-(x-m)*d); else printf("%d\n",t);
    return 0;
}

