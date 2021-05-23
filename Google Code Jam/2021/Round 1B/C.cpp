#include<bits/stdc++.h>
#define MAXN 6005
#define INF 120000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,b;
ll p;
int height[MAXN];
int main()
{
    scanf("%d%d%d%lld",&t,&n,&b,&p);
    int kase=0;
    while(t--)
    {
        kase++;
        memset(height,0,sizeof(height));
        for(int i=0;i<n*b;i++)
        {
            int x;
            scanf("%d",&x);
            bool f=false;
            for(int j=1;j<=n;j++)
            {
                if(x==9&&height[j]==b-1)
                {
                    f=true;
                    printf("%d\n",j);
                    fflush(stdout);
                    height[j]++;
                    break;
                }
            }
            if(!f)
            {
                for(int j=1;j<=n;j++)
                {
                    if(x>=7&&height[j]==b-2)
                    {
                        f=true;
                        printf("%d\n",j);
                        fflush(stdout);
                        height[j]++;
                        break;
                    }
                }
            }
            if(!f)
            {
                for(int j=1;j<=n;j++)
                {
                    if(height[j]<b-2)
                    {
                        f=true;
                        printf("%d\n",j);
                        fflush(stdout);
                        height[j]++;
                        break;
                    }
                }
            }
            if(!f)
            {
                for(int j=1;j<=n;j++)
                {
                    if(height[j]==b-2)
                    {
                        f=true;
                        printf("%d\n",j);
                        fflush(stdout);
                        height[j]++;
                        break;
                    }
                }
            }
            if(!f)
            {
                for(int j=1;j<=n;j++)
                {
                    if(height[j]==b-1)
                    {
                        f=true;
                        printf("%d\n",j);
                        fflush(stdout);
                        height[j]++;
                        break;
                    }
                }
            }
        }
    }
    int x;
    scanf("%d",&x);
    return 0;
}