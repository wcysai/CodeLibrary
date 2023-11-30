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
int T,n,k,a[MAXN];
int tot,q[MAXN],ans[MAXN];
set<int> qry;
map<int,int> mp;
vector<int> save[MAXN];
int cnt[MAXN];
void dfs(int now,int sum,ll prod,int num){
    if(sum==41){
        if(qry.count(prod)){
            if(mp.find(prod)==mp.end()) mp[prod]=++tot;
            int id=mp[prod];
            if(ans[id]==-1||ans[id]>num){
                ans[id]=num;
                save[id].clear();
                for(int i=1;i<=41;i++)
                    for(int j=0;j<cnt[i];j++)
                        save[id].push_back(i);
            }
        }
        return;
    }
    if(now>41-sum) return;
    dfs(now+1,sum,prod,num);
    int x=now,y=now,z=1; 
    while(INF/prod>=x&&41-sum>=y){
        cnt[now]++;
        dfs(now+1,sum+y,prod*x,num+z);
        if(INF/x>=now){
            x*=now; y+=now; z++;
        }
        else break;
    }
    cnt[now]=0;
}
int main()
{
    memset(ans,-1,sizeof(ans));
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&q[t]);
        qry.insert(q[t]);
    }
    dfs(1,0,1,0);
    for(int t=1;t<=T;t++){
        if(mp.find(q[t])==mp.end()) mp[q[t]]=++tot;
        int id=mp[q[t]];
        printf("Case #%d: ",t);
        if(ans[id]==-1) printf("-1\n");
        else{
            printf("%d",ans[id]);
            for(auto x:save[id]) printf(" %d",x);
            printf("\n");
        }
    }
    return 0;
}

