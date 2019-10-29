#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c,ans;
void relax(int x,int y,int z)
{
    ans=min(ans,max(max(x,y),max(z,(x+y+z+b+2)/3)));
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=INF;
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<=a;i++) relax(a-i,i,c);
        for(int i=0;i<=c;i++) relax(a,i,c-i);
        printf("%d\n",ans);
    }
    return 0;
}
