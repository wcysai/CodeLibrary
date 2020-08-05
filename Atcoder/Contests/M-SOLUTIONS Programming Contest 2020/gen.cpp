#include<bits/stdc++.h>
#define MAXN 200005
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
    freopen("E.in","w",stdout);
    printf("%d\n",15);
    for(int i=0;i<15;i++)
    {
        int x=wcy()%20001-10000,y=wcy()%20001-10000,p=wcy()%1000001+1;
        printf("%d %d %d\n",x,y,p);
    }
}