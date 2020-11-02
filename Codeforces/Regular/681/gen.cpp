#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n=200000;
mt19937 wcy(time(NULL));
int main()
{
    freopen("C.in","w",stdout);
    printf("%d %d\n",200000,199999);
    for(int i=2;i<=200000;i++)
    {
        if(i%2==0) printf("%d %d\n",i,i-1);
        else printf("%d %d\n",i-1,i);
    }
}