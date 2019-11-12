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
int T,n,tot;
string str[MAXN];
bool used[MAXN];
set<string> ss;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n); ss.clear();
        for(int i=1;i<=n;i++) cin>>str[i];
        int ans=0; 
        int maxi=0;
        for(int i=1;i<=n;i++) maxi=max(maxi,(int)str[i].size());
        memset(used,false,sizeof(used));
        for(int i=maxi;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>(int)str[j].size()) continue;
                if(used[j]) continue;
                string s=str[j].substr((int)str[j].size()-i);
                if(ss.count(s)) continue;
                int id=-1;
                for(int k=j+1;k<=n;k++)
                {
                    if(used[k]) continue;
                    if(i>(int)str[k].size()) continue;
                    string ss=str[k].substr((int)str[k].size()-i);
                    if(s==ss) id=k;
                }
                if(id!=-1) {ans+=2; used[j]=used[id]=true; ss.insert(s);}
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

