#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define BASE 19260817
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,int> P;
string str;
int tot=1,n;
vector<P> cnt[MAXN];
int mp[26];
int main()
{
    cin>>str;
    n=(int)str.size();
    if(n==1)
    {
        cout<<str<<endl;
        return 0;
    }
    int ans=0,st=-1,ed=-1;
    for(int i=0;i<n;i++)
    {
        memset(mp,-1,sizeof(mp));
        int t=0;
        int rt=1;
        ull hsh=0;
        for(int j=i;j<n;j++)
        {
            int x=str[j]-'a',len=j-i+1;
            if(mp[x]==-1) mp[x]=t++;
            hsh=hsh*BASE+mp[x];
            cnt[len].push_back(P(hsh,i));
        }
    }
    for(int len=1;len<=n;len++)
    {
        sort(cnt[len].begin(),cnt[len].end());
        int res=1;
        for(int j=1;j<(int)cnt[len].size();j++)
        {
            if(cnt[len][j].F==cnt[len][j-1].F) res++; else res=1;
            if(res*len>ans)
            {
                ans=res*len;
                st=cnt[len][j].S;
                ed=st+len-1;
            }
        }
    }
    cout<<str.substr(st,ed-st+1)<<endl;
    return 0;
}
//abacabadabacaba
