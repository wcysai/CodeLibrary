#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],suf[MAXN],dp[MAXN];
string str;
vector<int> pos[MAXN];
int st[MAXN][20];
int pre[MAXN];
int last[MAXN];
int tmp[MAXN];
int dppre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n+1;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=0;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d",&t);
    a[0]=0;
    while(t--)
    {
        scanf("%d",&n);
        n*=2;
        cin>>str;
        for(int i=0;i<n;i++) suf[i+1]=a[i+1]=((str[i]=='(')?1:-1);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1) tmp[i]=i;
            else tmp[i]=tmp[i-1];
        }
        for(int i=1;i<=n;i++) a[i]+=a[i-1];
        for(int i=n-1;i>=0;i--) suf[i]+=suf[i+1];
        for(int i=0;i<=n;i++) pos[i].clear();
        for(int i=0;i<=n;i++) if(a[i]>=0) pos[a[i]].push_back(i); 
        init(n,suf);
        dp[0]=0; 
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
                continue;
            }
            else
            {
                if(pos[a[i]][0]==i)
                {
                    dp[i]=dp[i-1]; dppre[i]=i-1;
                }
                else 
                {
                    dp[i]=INF;
                    if(a[i-1]>=0) {dp[i]=dp[i-1]; dppre[i]=i-1;}
                    int len=i-tmp[i]+a[i];
                    int id=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),i)-pos[a[i]].begin();
                    int l=-1,r=id;
                    while(r-l>1)
                    {
                        int mid=(l+r)/2;
                        if(suf[i]-query(pos[a[i]][mid]+1,i)<=len) r=mid; else l=mid;
                    }
                    //printf("r=%d\n",r);
                    if(r!=id) {int p=pos[a[i]][r]; if(dp[p]+1<dp[i]) {dp[i]=dp[p]+1; dppre[i]=p;} }
                }
            }
            //printf("i=%d len=%d dp=%d pre=%d\n",i,i-tmp[i],dp[i],dppre[i]);
        }
        int now=n;
        vector<P> ans;
        while(now!=0)
        {
            int p=dppre[now];
            if(dp[p]==dp[now]) now=p;
            else {ans.push_back(P(p+1,now)); now=p;}
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

