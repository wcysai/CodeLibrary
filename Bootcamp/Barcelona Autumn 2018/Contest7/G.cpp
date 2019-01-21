/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 20:36:06
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 100005
#define MAXP 1000005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node {int st,ed,cost; }a[MAXN];
bool cmp(node x,node y)
{
    return x.st<y.st;
}
struct plan
{
    int st,cost,dur,id;
}b[MAXP];
bool cmp2(plan x,plan y)
{
    return x.st<y.st;
}
int n,p,maxk;
int dp[100005],ans[MAXP];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) {scanf("%d%d%d",&a[i].cost,&a[i].st,&a[i].ed); a[i].ed--; v.push_back(a[i].st);}
    sort(a,a+n,cmp);
    scanf("%d",&p);
    for(int i=0;i<p;i++) 
    {
        scanf("%d%d%d",&b[i].st,&b[i].cost,&b[i].dur);
        v.push_back(b[i].st);
        b[i].id=i;maxk=max(b[i].cost,maxk);
    }
    sort(b,b+p,cmp2);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    dp[0]=INF;
    int cur1=0,cur2=0;
    for(int i=0;i<(int)v.size();i++)
    {
        while(cur1<n&&a[cur1].st==v[i])
        {
            //printf("add %d-%d %d\n",a[cur1].st,a[cur1].ed,a[cur1].cost);
            for(int j=maxk;j>=0;j--)
                if(j>=a[cur1].cost) dp[j]=max(dp[j],min(dp[j-a[cur1].cost],a[cur1].ed));
            cur1++;
            //for(int i=0;i<=maxk;i++) printf("%d ",dp[i]);
            //puts("");
        }
        while(cur2<p&&b[cur2].st==v[i])
        {
            if(b[cur2].st+b[cur2].dur<=dp[b[cur2].cost]) ans[b[cur2].id]=1; else ans[b[cur2].id]=0;
            //printf("grab %d-%d %d:%d\n",b[cur2].st,b[cur2].st+b[cur2].dur,b[cur2].cost,ans[b[cur2].id]);
            cur2++;
        }
    }
    for(int i=0;i<p;i++) if(ans[i]) puts("TAK"); else puts("NIE");
    return 0;
}

