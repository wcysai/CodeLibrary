#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
bool is_square(int x)
{
    int r=(int)sqrt(x);
    for(int i=max(1,r-5);i<=r+5;i++) if(1LL*r*r==x) return true;
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==0&&is_square(n/2)) {puts("YES"); continue;}
        if(n%4==0&&is_square(n/4)) {puts("YES"); continue;}
        puts("NO");
    }
    return 0;
}