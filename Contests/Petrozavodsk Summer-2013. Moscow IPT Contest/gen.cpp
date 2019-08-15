#pragma GCC optimize(3)
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
    freopen("in.txt","w",stdout);
    printf("%d\n",200000);
    for(int i=2;i<=200000;i++)
    {
        int p=wcy()%(i-1)+1;
        printf("%d %d\n",i,p);
    }
    return 0;
}
