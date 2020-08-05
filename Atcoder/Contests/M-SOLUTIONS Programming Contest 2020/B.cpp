#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,k;
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&k);
    int cnt=0;
    while(b<=a) b*=2,cnt++;
    while(c<=b) c*=2,cnt++;
    if(cnt>k) puts("No"); else puts("Yes");
    return 0;
 }