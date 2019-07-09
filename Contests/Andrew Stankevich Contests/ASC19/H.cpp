#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN][MAXN];
int cnt[MAXN];
double val[MAXN][MAXN];
int main()
{
    freopen("pebbles.in","r",stdin);
    freopen("pebbles.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str[i]+1);
        cnt[i]=strlen(str[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            double x=0;
            int now=1;
            while(now<=j&&str[i][now]==str[i][1])
            {
                if(str[i][now]=='B') x+=1.0; else x-=1.0;
                now++;
            }
            int k=2;
            while(now<=j)
            {
                if(str[i][now]=='B') x+=1.0/k; else x-=1.0/k;
                now++;
                k*=2;
            }
            val[i][j]=x;
        }
    }
    double sum=0.0;
    for(int i=1;i<=n;i++) sum+=val[i][cnt[i]];
    if(sum<=0) puts("Mike");
    else
    {
        puts("Andrew");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=cnt[i];j++)
            {
                if(str[i][j]=='R') continue;
                if(sum-val[i][cnt[i]]+val[i][j-1]>=0)
                {
                    printf("%d %d\n",i,j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
