#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(a==0||b==0||(a<0&&b>0)) puts("Zero");
    else if(a>0) puts("Positive");
    else if((b-a)&1) puts("Positive");
    else puts("Negative");
    return 0;
}
