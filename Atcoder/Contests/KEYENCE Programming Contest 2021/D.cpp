#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N;
int main()
{
    scanf("%d",&N);
    printf("%d\n",(1<<N)-1);
    for(int i=1;i<(1<<N);i++)
    {
        for(int j=0;j<(1<<N);j++)
            if(__builtin_popcount(i&j)&1) printf("A"); else printf("B");
        puts("");
    }
    return 0;
}