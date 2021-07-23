#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 31607
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int main()
{
    freopen("F.in","w",stdout);
    printf("%d\n",18);
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=18;j++)
        {
            printf("%d ",wcy()%10001);
        }
        puts("");
    }
}