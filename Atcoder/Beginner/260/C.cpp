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
int n,x,y;
ll r[11],b[11];
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    r[n]=1;
    for(int i=n;i>=2;i--)
    {
        b[i]+=x*r[i];
        r[i-1]+=r[i];
        r[i-1]+=b[i];
        b[i-1]+=y*b[i];
    }
    printf("%lld\n",b[1]);
    return 0;
}

