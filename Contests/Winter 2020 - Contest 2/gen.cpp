#include<bits/stdc++.h>
#define MAXN 1005
#define INF 10000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int T,n,x[MAXN],y[MAXN];
vector<int> v;
int main()
{
    freopen("A.in","w",stdout);
    puts("1");
    printf("%d\n",1000);
    for(int i=0;i<1000;i++)
    {
        int x=wcy()%2001-1000,y=wcy()%2001-1000;
        printf("%d %d\n",x,y);
    }
    return 0;
}