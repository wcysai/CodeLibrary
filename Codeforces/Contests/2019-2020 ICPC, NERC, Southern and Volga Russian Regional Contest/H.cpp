#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
int c[10];
void solve()
{
    bool f=true;
    for(int i=1;i<=9;i++) if(c[i]<=c[0]) f=false;
    if(f)
    {
        printf("%d",1);
        for(int j=0;j<=c[0];j++) printf("0");
        puts("");
        return;
    }
    int id=9;
    for(int i=9;i>=1;i--)
        if(c[i]<=c[id]) id=i;
    for(int i=0;i<=c[id];i++) printf("%d",id);
    puts("");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=9;i++) scanf("%d",&c[i]);
        solve();
    }
    return 0;
}
