#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",max(0,y-x+1));
    return 0;
}