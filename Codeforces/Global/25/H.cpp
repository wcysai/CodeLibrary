#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN],sum[MAXN],lvl[MAXN],mult;
vector<int> p[MAXN];
bool cmp(int x,int y){
    return a[x]>a[y];
}
void pushup(int x){
    sum[x]=sum[x*2]+sum[x*2+1];
   // dp[x]=max((1<<(k-lvl[x]-mult))-sum[x],min(0,dp[2*x]+dp[2*x+1]+1));
   // dp[x]=max(dp[x],(1<<(k-lvl[x]-mult-1))-sum[2*x]-1);
    dp[x]=max(dp[x],(1<<(k-lvl[x]-mult-1))-sum[2*x+1]-1);
}
int main(){
    for(int i=0;i<=20;i++)
        for(int j=(1<<i);j<(1<<(i+1));j++)
            lvl[j]=i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        for(int i=1;i<=(1<<k);i++) scanf("%d",&a[i]);
        vector<int> v;
        for(int i=1;i<=(1<<k);i++) v.push_back(i);
        sort(v.begin(),v.end(),cmp);
        for(int i=1;i<=k;i++){
            mult=k-i;
            for(int j=(1<<i);j<(1<<(i+1));j++) {sum[j]=0; dp[j]=1;}
            for(int j=(1<<i)-1;j>=1;j--) pushup(j);
            for(auto x:v){
                int id=(1<<i)+((x-1)/(1<<(k-i)));
                sum[id]++; dp[id]=0;
                while(id>1) {id/=2; pushup(id);}
                if(dp[1]==0){
                    printf("%d ",a[x]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

