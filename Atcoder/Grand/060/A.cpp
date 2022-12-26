#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dp[26][26],ndp[26][26];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    cin>>n;
    cin>>str;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            if(i==j) continue;
            bool f=true;
            if(str[0]!='?'&&str[0]!='a'+i) f=false;
            if(str[1]!='?'&&str[1]!='a'+j) f=false;
            if(!f) dp[i][j]=0; else dp[i][j]=1;
        }
    for(int i=2;i<n;i++){
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++){
                if(!dp[j][k]) continue;
                for(int l=0;l<26;l++){
                    if(l==j||l==k) continue;
                    if(str[i]!='?'&&str[i]!='a'+l) continue;
                    add(ndp[k][l],dp[j][k]);
                }
            }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            add(ans,dp[i][j]);
    cout<<ans<<endl;
    return 0;
}

