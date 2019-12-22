#include<bits/stdc++.h>
#define MAXN 50005
#define INF 20000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,k;
mt19937 wcy(time(NULL));
int main()
{
    freopen("in.txt","w",stdout);
    n=20000,m=50000,k=1000;
    printf("%d %d %d\n",n,m,k);
    for(int i=0;i<n-1;i++) printf("%d %d %d\n",1,i+2,wcy()%INF+1);
    for(int i=n-1;i<m;i++)
    {
        int x=0,y=0;
        while(x==y)
        {
            x=wcy()%n+1,y=wcy()%n+1;
        }
        int w=wcy()%INF+1;
        printf("%d %d %d\n",x,y,w);
    }
    return 0;
}