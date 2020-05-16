#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
mt19937 wcy(time(NULL));
int n,k;
int main()
{
    freopen("K.in","w",stdout);
    n=50; k=50;
    printf("%d %d\n",n,k);
    for(int i=1;i<=k;i++)
    {
        if(i==k) printf("%d %d liar\n",i,1);
        else printf("%d %d knight\n",i,i+1);
    }
    puts("");
}