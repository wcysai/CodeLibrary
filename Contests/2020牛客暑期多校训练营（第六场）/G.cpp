#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n==1||k==1||2*n*(n+1)%k) puts("-1");
        else
        {
            if(n%k==0)
            {
                int st=1;
                for(int i=1;i<=n+1;i++) 
                {
                    int cur=st;
                    for(int j=1;j<=n;j++)
                    {
                        printf("%d ",cur);
                        cur++; if(cur>k) cur=1;
                    }
                    st++; if(st>k) st=1;
                    puts("");
                }
                for(int i=1;i<=n+1;i++) 
                {
                    int cur=st;
                    for(int j=1;j<=n;j++)
                    {
                        printf("%d ",cur);
                        cur++; if(cur>k) cur=1;
                    }
                    st++; if(st>k) st=1;
                    puts("");
                }
            }
            else
            {
                int cur=1;
                for(int i=1;i<=n+1;i++) 
                {
                    for(int j=1;j<=n;j++)
                    {
                        printf("%d ",cur);
                        cur++; if(cur>k) cur=1;
                    }
                    puts("");
                }
                for(int i=1;i<=n+1;i++) 
                {
                    for(int j=1;j<=n;j++)
                    {
                        printf("%d ",cur);
                        cur++; if(cur>k) cur=1;
                    }
                    puts("");
                }
            }
        }
    }
}