#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v[16];
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int mask=0;
        if(i%2==0) mask|=1;
        if(i%3==0) mask|=2;
        if(i%5==0) mask|=4;
        if(i%7==0) mask|=8;
        v[mask].push_back(i);
    }
    ans[1]=210;
    ans[2]=2;
    int curmask=1,cur=3;
    while(cur<=n)
    {
        int res=0;
        for(int mask=14;mask>=1;mask--)
            if((!(mask&curmask))&&(v[mask].size())&&__builtin_popcount(mask)>__builtin_popcount(res))
                res=mask;
        ans[cur]=v[res].back();
        v[res].pop_back();
        cur++; curmask=res;
    }
    for(int i=15;i>=0;i--)
        for(auto x:v[i]) ans[cur++]=x;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}