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
    scanf("%d",&n);
    if(n>=400&&n<600) puts("8");
    else if(n>=600&&n<800) puts("7");
    else if(n>=800&&n<1000) puts("6");
    else if(n>=1000&&n<1200) puts("5");
    else if(n>=1200&&n<1400) puts("4");
    else if(n>=1400&&n<1600) puts("3");
    else if(n>=1600&&n<1800) puts("2");
    else if(n>=1800&&n<2000) puts("1");
    return 0;
 }