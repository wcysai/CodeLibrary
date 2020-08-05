#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],type[MAXN],ans;
char str[3];
vector<P> h[MAXN],v[MAXN],rt[2*MAXN];
void check(vector<P> &vv,int mult)
{
    if(!vv.size()) return;
    sort(vv.begin(),vv.end());
    int last=-1;
    for(int j=0;j<(int)vv.size();j++)
    {
        if(vv[j].S==0) last=vv[j].F;
        else if(last!=-1) ans=min(ans,mult*(vv[j].F-last));
    }
    vv.clear();
}
int main()
{
    scanf("%d",&n);
    ans=INF;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%s",&x[i],&y[i],str);
        if(str[0]=='U') type[i]=1;
        else if(str[0]=='D') type[i]=2;
        else if(str[0]=='L') type[i]=3;
        else if(str[0]=='R') type[i]=4;
        if(type[i]==1) v[x[i]].push_back(P(y[i],0));
        else if(type[i]==2) v[x[i]].push_back(P(y[i],1));
        else if(type[i]==3) h[y[i]].push_back(P(x[i],1));
        else h[y[i]].push_back(P(x[i],0));
    }
    for(int i=0;i<=200000;i++) check(h[i],5);
    for(int i=0;i<=200000;i++) check(v[i],5);
    for(int i=1;i<=n;i++)
    {
        if(type[i]==4) rt[y[i]-x[i]+200000].push_back(P(x[i],0));
        else if(type[i]==2) rt[y[i]-x[i]+200000].push_back(P(x[i],1));
    }
    for(int i=0;i<=400000;i++) check(rt[i],10);
    for(int i=1;i<=n;i++)
    {
        if(type[i]==4) rt[x[i]+y[i]].push_back(P(x[i],0));
        else if(type[i]==1) rt[x[i]+y[i]].push_back(P(x[i],1));
    }
    for(int i=0;i<=400000;i++) check(rt[i],10);
    for(int i=1;i<=n;i++)
    {
        if(type[i]==3) rt[y[i]-x[i]+200000].push_back(P(x[i],1));
        else if(type[i]==1) rt[y[i]-x[i]+200000].push_back(P(x[i],0));
    }
    for(int i=0;i<=400000;i++) check(rt[i],10);
    for(int i=1;i<=n;i++)
    {
        if(type[i]==3) rt[x[i]+y[i]].push_back(P(x[i],1));
        else if(type[i]==2) rt[x[i]+y[i]].push_back(P(x[i],0));
    }
    for(int i=0;i<=400000;i++) check(rt[i],10);
    if(ans==INF) puts("SAFE"); else printf("%d\n",ans);
}