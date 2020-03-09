#include<bits/stdc++.h>
#define MAXN 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
string str;
map<string,int> mp;
int dp[MAXN],pre[MAXN];
int l[MAXN];
int get_id(string str)
{
    if(!str.size()) return -1;
    if(str[0]!='@') return -1;
    if(mp.find(str)==mp.end()) mp[str]=++tot;
    return mp[str];
}
int main()
{
    freopen("join.in","r",stdin);
    freopen("join.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        str+=' ';
        int sz=(int)str.size();
        int id;
        int last=0;
        dp[i]=1;
        bool f=false;
        for(int j=0;j<sz;j++)
        {
            if(!f&&str[j]==':')
            {
                f=true;
                id=get_id(str.substr(0,j));
                last=j;
                continue;
            }
            if(f&&str[j]==' ')
            {
                string s=str.substr(last+1,j-last-1);
                int fid=get_id(s);
                if(fid!=-1&&fid!=id&&l[fid])
                {
                    if(dp[l[fid]]+1>dp[i])
                    {
                        dp[i]=dp[l[fid]]+1;
                        pre[i]=l[fid];
                    }
                }
                last=j;
            }
        }
        if(dp[i]>dp[l[id]]) l[id]=i;
    }
    int ans=-1,id=-1;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>ans)
        {
            ans=dp[i];
            id=i;
        }
    } 
    vector<int> v;
    while(id)
    {
        v.push_back(id);
        id=pre[id];
    }
    reverse(v.begin(),v.end());
    printf("%d\n",ans);
    for(auto x:v) printf("%d ",x);
    puts("");
    return 0;
}