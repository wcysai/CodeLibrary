#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,d,k;
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    printf("%d\n",(c-a)*60+(d-b)-k);
    return 0;
}