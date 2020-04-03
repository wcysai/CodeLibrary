#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    x=n-x; y=y-1;
    if(x>y) swap(x,y);
    double r=(sqrt(5.0)+1)/2;
    double c=y-x;
    int tmp=(int)(r*c);
    if(tmp==x) puts("1"); else puts("2");
    return 0;
}