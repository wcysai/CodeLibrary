#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str[MAXN];
vector<int> ans[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) ans[i].clear();
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) 
                if(str[j][i]=='1') cnt[i]++;
        for(int i=0;i<n;i++)
        {
            int id=-1;
            for(int j=0;j<n;j++)
                if(cnt[j]==0) {id=j; break;}
            assert(id!=-1);
            cnt[id]=-1;
            ans[id].push_back(i+1);
            for(int j=0;j<n;j++) 
                if(str[id][j]=='1')
                {
                    cnt[j]--;
                    ans[j].push_back(i+1);
                }
        }
        for(int i=0;i<n;i++) 
        {
            printf("%d",(int)ans[i].size());
            for(auto x:ans[i]) printf(" %d",x);
            printf("\n");
        }
    }
    return 0;
}

