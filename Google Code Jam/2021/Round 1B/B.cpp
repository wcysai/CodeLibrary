#include<bits/stdc++.h>
#define MAXN 6005
#define INF 120000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b;
int has[MAXN];
int need[MAXN];
bool check(int x)
{
    memset(has,0,sizeof(has));
    has[x]=1;
    for(int i=x;i>=1;i--)
    {
        if(has[i]>need[i])
        {
            int y=min(has[i]-need[i],5000);
            if(i>a) has[i-a]+=y;
            if(i>b) has[i-b]+=y;
        }
        else if(has[i]<need[i]) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    int kase=0;
    while(t--)
    {
        kase++;
        scanf("%d%d%d",&n,&a,&b);
        memset(need,0,sizeof(need));
        for(int i=1;i<=n;i++) scanf("%d",&need[i]);
        bool f=false;
        for(int i=n+1;i<=5000;i++)
        {
            if(check(i))
            {
                f=true;
                printf("Case #%d: %d\n",kase,i);
                break;
            }
        }
        if(!f)
        {
            printf("Case #%d: IMPOSSIBLE\n",kase);
        }
    }
    return 0;
}