#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l,r,c[MAXN];
int lcnt[MAXN],rcnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&l,&r);
        for(int i=1;i<=n;i++) lcnt[i]=rcnt[i]=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&c[i]);
            if(i<=l) lcnt[c[i]]++; else rcnt[c[i]]++;
        }
        int need=(l-r)/2,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(need>0&&lcnt[i]>rcnt[i])
            {
                int x=(lcnt[i]-rcnt[i])/2;
                int val=min(need,x);
                need-=val; lcnt[i]-=val; rcnt[i]+=val;
            }
            else if(need<0&&lcnt[i]<rcnt[i])
            {
                int x=(rcnt[i]-lcnt[i])/2;
                int val=min(-need,x);
                need+=val; lcnt[i]+=val; rcnt[i]-=val;
            }
            ans+=max(lcnt[i]-rcnt[i],rcnt[i]-lcnt[i]);
        }
        printf("%d\n",ans/2+max((l-r)/2,(r-l)/2));
    }
}