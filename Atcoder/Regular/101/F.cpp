#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int x[MAXN],y[MAXN];
vector<P> v;
vector<int> v1,v2;
int dp[MAXN];
int bit[MAXN+1];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        add(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void Add(int i,int x)
{
    while(i<=n)
    {
        add(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    for(int i=0;i<m;i++) scanf("%d",&y[i]);
    int now=0;
    for(int i=0;i<m-1;i++)
    {
        while(i==0&&now<n&&x[now]<y[i]) now++;
        while(now<n&&x[now]>y[i]&&x[now]<y[i+1])
        {
            v.push_back(P(x[now]-y[i],y[i+1]-x[now]));
            v1.push_back(x[now]-y[i]);v2.push_back(y[i+1]-x[now]);
            now++;
        }
    }
    sort(v1.begin(),v1.end());v1.erase(unique(v1.begin(),v1.end()),v1.end());
    sort(v2.begin(),v2.end());v2.erase(unique(v2.begin(),v2.end()),v2.end());
    for(int i=0;i<(int)v.size();i++)
    {
        v[i].F=lower_bound(v1.begin(),v1.end(),v[i].F)-v1.begin()+1;
        v[i].S=lower_bound(v2.begin(),v2.end(),v[i].S)-v2.begin()+1;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    now=0;
    while(now<(int)v.size())
    {
        int last=now;
        while(now<(int)v.size()&&v[now].F==v[now+1].F) now++;
        for(int i=last;i<=now;i++) dp[i]=sum(v[i].S-1)+1;
        for(int i=last;i<=now;i++) Add(v[i].S,dp[i]);
        now++;
    }
    int ans=0;
    for(int i=0;i<(int)v.size();i++) add(ans,dp[i]);
    add(ans,1);
    printf("%d\n",ans);
    return 0;
}

