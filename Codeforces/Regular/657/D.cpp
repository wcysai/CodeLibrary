#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h,m,k;
vector<P> v;
void add_interval(int l,int r)
{
    if(l<0) l+=m/2;
    if(r<0) r+=m/2;
    if(l<=r) 
    {
        v.push_back(P(l-1,0));
        v.push_back(P(l,1));
        v.push_back(P(r+1,-1));
    }
    else
    {
        v.push_back(P(-INF,1));
        v.push_back(P(r+1,-1));
        v.push_back(P(l-1,0));
        v.push_back(P(l,1));
    }
}
int l[MAXN],r[MAXN];
int main()
{
    scanf("%d%d%d%d",&n,&h,&m,&k);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y>m/2) y-=m/2;
        l[i]=y-k+1; r[i]=y-1;
        if(l[i]<0) l[i]+=m/2;
        if(r[i]<0) r[i]+=m/2;
        add_interval(y-k+1,y-1);
    }
    sort(v.begin(),v.end());
    int now=0;
    int curt=-1,ans=INF,s=0;
    while(now<(int)v.size())
    {
        int val=v[now].F;
        s+=v[now].S; now++;
        while(now<(int)v.size()&&v[now].F==val)
        {
            s+=v[now].S;
            now++;
        }
        if(s<ans&&v[now-1].F>=0&&v[now-1].F<m/2)
        {
            ans=s;
            curt=v[now-1].F;
        }
    }
    printf("%d %d\n",ans,curt);
    for(int i=0;i<n;i++)
    {
        if(l[i]<=r[i])
        {
            if(curt>=l[i]&&curt<=r[i]) printf("%d ",i+1);
        }
        else
        {
            if(curt>=l[i]||curt<=r[i]) printf("%d ",i+1);
        }
        
    }
}