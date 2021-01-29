#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN],dp[MAXN],s[MAXN];
int st[MAXN][20];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
bool check(int now,int pre)
{
    int to=query(pre,now);
    if(to>=n) return true;
    if(to==now)
    {
        
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) s[i]=i+p[i];
        init(n,s);
        for(int i=n-1;i>=1;i--)
        {
            if(i+p[i]>=n) 
            {
                dp[n-1]=i;
                break;
            }
        }
        for(int i=n-2;i>=1;i--)
        {
            int l=1,r=i-2
        }
    }
}