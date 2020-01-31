#include<bits/stdc++.h>
#define MAXN 100005
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
    freopen("F.in","w",stdout);
    printf("%d\n",1);
    printf("%d\n",100000);
    for(int i=2;i<=100000;i++)
    {
        int x=wcy()%(i-1)+1;
        int y=wcy()%26;
        printf("%d %d %c\n",i,x,'a'+y);
    }
    return 0;
}