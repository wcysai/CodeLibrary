#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
P p[MAXN];
vector<int> v[MAXN];
int r[MAXN],l[MAXN];
vector<int> divi[MAXN],mult[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        int tmp=a[i],cnt=0;
        while(tmp%2==0) {tmp/=2; cnt++;}
        v[tmp].push_back(cnt);
        p[i]=P(tmp,cnt);
    }
    for(int i=1;i<=2*m;i+=2)
        for(int j=3*i;j<=2*m;j+=2*i)
        {
            divi[j].push_back(i);
            mult[i].push_back(j);
        }
    bool f=true;
    for(int i=1;i<=2*m;i+=2)
    {
        sort(v[i].begin(),v[i].end());
        int mini=INF;
        for(auto x:divi[i]) mini=min(mini,r[x]);
        int now=(int)v[i].size()-1;
        while(now>=0&&v[i][now]>=mini) now--;
        if(now<0) {f=false; break;} else r[i]=v[i][now];
    }
    for(int i=2*m-1;i>=1;i-=2)
    {
        int maxi=-INF;
        for(auto x:mult[i]) maxi=max(maxi,l[x]);
        int now=0;
        while(now<(int)v[i].size()&&v[i][now]<=maxi) now++;
        if(now>=(int)v[i].size()) {f=false; break;} else l[i]=v[i][now];
    }
    if(!f) {for(int i=1;i<=n;i++) puts("No");  return 0;}
    for(int i=1;i<=n;i++)
        if(p[i].S>=l[p[i].F]&&p[i].S<=r[p[i].F]) puts("Yes"); else puts("No");
    return 0;
}

