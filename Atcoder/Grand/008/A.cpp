#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y;
int main()
{
    scanf("%d%d",&x,&y);
    int ans=INF;
    if(x<=y) ans=min(ans,y-x);
    for(int i=1;i<=2;i++)
    {
        int res=i;
        int dx=(i==1?-x:x);
        if(y>=dx) ans=min(ans,res+y-dx);
        else ans=min(ans,res+dx-y);
    }
    printf("%d\n",ans);
    return 0;
}