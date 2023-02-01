#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> divi[MAXN];
int cnt[MAXN],mult[MAXN],dp[MAXN][2],tmp[MAXN];
int main()
{
    for(int i=1;i<=200000;i++)
        for(int j=i;j<=200000;j+=i)
            divi[j].push_back(i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=200000;i++)
        for(int j=i;j<=200000;j+=i)
            mult[i]+=cnt[j];
    dp[2][0]=0; dp[2][1]=1;
    for(int i=3;i<=200000;i++){
        if(divi[i].size()==2) {dp[i][0]=0; dp[i][1]=1;}
        else
        {
            for(int j=(int)divi[i].size()-1;j>=0;j--){
                int val=divi[i][j];
                tmp[val]=mult[val];
                int z=i/val;
                for(int k=1;k<(int)divi[z].size();k++)
                    tmp[val]-=tmp[divi[z][k]*val];
                //printf("i=%d val=%d tmp=%d\n",i,val,tmp[val]);
            }
            for(auto x:divi[i]){
                if(x==1||x==i) continue;
                if(tmp[x]&&(!dp[x][(mult[x]-mult[i]+1)&1])) dp[i][0]=1;
                if(tmp[x]&&(!dp[x][(mult[x]-mult[i])&1])) dp[i][1]=1;
            }
            if(!dp[i][0]) dp[i][1]=1;
            for(auto x:divi[i]) tmp[x]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[a[i]][(mult[a[i]]+1)&1]) puts("Aoki");
        else puts("Takahashi");
    }
    return 0;
}

