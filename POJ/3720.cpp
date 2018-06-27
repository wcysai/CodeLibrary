#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#define MAXN 105
#define MAXV 125
#define MAXC 10005
#define MAXT 10005
#define INF 1000000000
using namespace std;
int dp_pay[MAXT+MAXV*MAXV];
int dp_change[MAXT+MAXV*MAXV];
int deq[MAXT+MAXV*MAXV+1];
int deqv[MAXT+MAXV*MAXV+1];
int n,t;
int v[MAXN],c[MAXN];
int main()
{
    scanf("%d%d",&n,&t);
    int max_v=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        max_v=max(v[i],max_v);
    }
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    int max_size=t+max_v*max_v;
    fill(dp_pay,dp_pay+max_size+1,INF);
    fill(dp_change,dp_change+max_size+1,INF);
    dp_change[0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=max_size;j++)
            if(j>=v[i]) dp_change[j]=min(dp_change[j],dp_change[j-v[i]]+1);
    dp_pay[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<v[i];a++)
        {
            int s=0,t=0;
            for(int j=0;j*v[i]+a<=max_size;j++)
            {
                int val=dp_pay[j*v[i]+a]-j;
                while(s<t&&deqv[t-1]>=val) t--;
                deq[t]=j;
                deqv[t++]=val;
                dp_pay[j*v[i]+a]=deqv[s]+j;
                if(deq[s]==j-c[i]) s++;
            }
        }
    }
    int ans=INF;
    for(int i=max_size;i>=t;i--)
        ans=min(ans,dp_pay[i]+dp_change[i-t]);
    if(ans==INF) printf("-1\n"); else printf("%d\n",ans);
    return 0;
}
