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
int n,ans;
string str;
vector<int> occ[26];
void solve(int x,int y)
{
    int sz1=(int)occ[x].size(),sz2=(int)occ[y].size();
    if(sz1==0||sz2==0) return;
    vector<int> v; v.clear();
    int l=0,r=0;
    while(l<sz1||r<sz2)
    {
        if(r==sz2||(l<sz1&&occ[x][l]<occ[y][r]))
        {
            v.push_back(1);
            l++;
        }
        else
        {
            v.push_back(-1);
            r++;
        }
    }
    int sz=(int)v.size();
    vector<int> sum(sz+1),pre(sz+1);
    for(int i=1;i<=sz;i++) sum[i]=sum[i-1]+v[i-1];
    for(int i=1;i<=sz;i++) pre[i]=min(pre[i-1],sum[i]);
    int last=-1;
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]==-1) last=i;
        if(last!=-1) ans=max(ans,sum[i+1]-pre[last]);
    }
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
    {
        occ[str[i]-'a'].push_back(i);
    }
    ans=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            if(i==j) continue;
            solve(i,j);
        }
    printf("%d\n",ans);
    return 0;
}

