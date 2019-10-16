#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
    scanf("%d",&n);
    if(n>=15)
    {
        puts("0");
        return 0;
    }
    int t=1;
    while(2*t-1<=n) t=t*2;
    int x=n-t+1;
    if(x==0||x>t/2) puts("0"); else puts("1");
}
