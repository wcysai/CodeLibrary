#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a,b,c,d;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(b+c>a+d) printf("AB//CD\n"); else printf("AB//DC\n");
    }
}