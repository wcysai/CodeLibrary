#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN];
vector<int> items;
bool dp[MAXN][MAXN];
bool take[MAXN][MAXN];
vector<int> A,B;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&c[i]);
    int cnt=0,maxi=0;
    for(int i=1;i<=2*n;i++){
        if(i==1||c[i]<maxi) {cnt++; maxi=max(maxi,c[i]);}
        else{
            items.push_back(cnt);
            maxi=c[i];
            cnt=1;
        }
    }
    items.push_back(cnt);
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for(int i=1;i<=(int)items.size();i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=items[i-1]&&dp[i-1][j-items[i-1]]) {dp[i][j]=true; take[i][j]=true;}
        }
    }
    if(!dp[(int)items.size()][n]) puts("-1");
    else{
        int len=n,now=2*n;
        for(int i=(int)items.size();i>=1;i--){
            if(take[i][len]){
                for(int j=now;j>now-items[i-1];j--) A.push_back(c[j]);
                len-=items[i-1];
                now-=items[i-1];
            }
            else{
                for(int j=now;j>now-items[i-1];j--) B.push_back(c[j]);
                now-=items[i-1];
            }
        }
    }
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(auto x:A) printf("%d ",x);
    printf("\n");
    for(auto x:B) printf("%d ",x);
    printf("\n");
    return 0;
}

