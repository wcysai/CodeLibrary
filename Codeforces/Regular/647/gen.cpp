#include<bits/stdc++.h>
#define MAXN (1<<20)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int main()
{
    int n=500000;
    freopen("C.in","w",stdout);
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int x=wcy()%(1<<20),y=wcy()%(1<<20);
        printf("%d %d\n",x,y);
    }
}