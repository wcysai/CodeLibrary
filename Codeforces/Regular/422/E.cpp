#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x;
string s,t;
int dp[MAXN][31];
void upd(int &a,int b) {a=max(a,b);}
int r[MAXM+1];
int sa[MAXM],lcp[MAXM];
int c[MAXM],t1[MAXM],t2[MAXM];
int st[MAXM][19],pre[MAXM];
string S;
void construct_sa(string S,int *sa) 
{
    int n=S.length()+1;
    int m=130;
    int i,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=S[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(i=n-k;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for(i=1;i<n;i++) 
            x[sa[i]]=y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void construct_lcp(string S,int *sa,int *lcp)
{
    int n=S.length();
    for(int i=0;i<=n;i++) r[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++)
    {
        int j=sa[r[i]-1];
        if(h>0) h--;
        for(;j+h<n&&i+h<n;h++)
        {
            if(S[j+h]!=S[i+h]) break;
        }
        lcp[r[i]-1]=h;
    }
}
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<n;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int calc_lcp(int i,int j)
{
    j=n+1+j;
    int x=r[i],y=r[j];
    if(x>y) swap(x,y);
    return query(x,y-1);
}
int main()
{
    scanf("%d",&n);
    cin>>s;
    scanf("%d",&m);
    cin>>t;
    scanf("%d",&x);
    S=s; S+='#'; S+=t;
    construct_sa(S,sa);
    construct_lcp(S,sa,lcp);
    init(n+m+1,lcp);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(dp[i][j]==-1) continue;
            upd(dp[i+1][j],dp[i][j]);
            if(j!=x)
            {
                int len=calc_lcp(i,dp[i][j]);
                if(len>0) upd(dp[i+len][j+1],dp[i][j]+len);
            }
        }
    }
    for(int i=0;i<=x;i++) if(dp[n][i]==m) f=true;
    if(f) puts("YES"); else puts("NO");
    return 0;
}

