#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    for(int i=a;i<=b;i++)
    {
        if(i%c==0) {printf("%d\n",i); return 0;}
    }
    puts("-1");
    return 0;
}