#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int p[5],a[26];
string str[MAXN];
int dp[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<4;i++) p[i]=i;
    p[4]=4;
    a['S'-'A']=0; a['W'-'A']=1; a['E'-'A']=2; a['R'-'A']=3; a['C'-'A']=4;
    int ans=0;
    do{
        fill(dp,dp+n,INF);
        for(int i=0;i<n;i++){
            int x=p[a[str[i][0]-'A']]*100000,y=0;
            for(int j=1;j<(int)str[i].size();j++) y=y*10+str[i][j]-'0';
            x+=y;
            *lower_bound(dp,dp+n,x)=x;
        }
        ans=max(ans,(int)(lower_bound(dp,dp+n,INF)-dp));
    }while(next_permutation(p,p+4));
    printf("%d\n",n-ans);
    return 0;
}

