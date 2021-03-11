#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
vector<int> v;
int n;
void mult_by_nine()
{
    int carry=0;
    for(int i=0;i<(int)v.size();i++)
    {
        int res=9*v[i]+carry;
        v[i]=res%10;
        carry=res/10;
    }
    if(carry) v.push_back(carry);
}
void add_one()
{
    v[0]++;
    int now=0;
    while(v[now]>=10)
    {
        v[now]-=10;
        if(now+1==(int)v.size()) v.push_back(1); else v[now+1]++;
        now++;
    }
}
int dp[52][2][2];
int dp2[52][2];
void upd(int &x,int y) {x=min(x,y);}
/*dp[i][0/1][0/1]: minimum number of operations used to make first i positions zero 
with/without a carry
using even/odd operations*/
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<n;i++) v.push_back(str[i]-'0');
    reverse(v.begin(),v.end());
    mult_by_nine();
    int ans=INF;
    for(int i=1;i<=10000;i++)
    {
        add_one();
        if(v[0]!=0) continue;
        for(int j=0;j<=50;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    dp[j][k][l]=INF;
        dp[0][0][v[0]&1]=v[0];
        dp[0][1][(10-v[0]&1)]=10-v[0];
        for(int j=0;j<50;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    if(dp[j][k][l]==INF) continue;
                    //printf("i=%d j=%d k=%d l=%d dp=%d\n",i,j,k,l,dp[j][k][l]);
                    int cur=(j+1<(int)v.size()?v[j+1]:0)+(k==0?0:1);
                    upd(dp[j+1][0][l^(cur&1)],dp[j][k][l]+cur);
                    upd(dp[j+1][1][l^((10-cur)&1)],dp[j][k][l]+(10-cur));
                }
            }
        }
        if(dp[50][0][i&1]<=i) 
        {
            for(int j=0;j<=50;j++)
                for(int k=0;k<2;k++)
                    dp2[j][k]=INF;
            dp2[0][0]=0;
            dp2[0][1]=0;
            for(int j=0;j<50;j++)
                for(int k=0;k<2;k++)
                {
                    if(dp2[j][k]==INF) continue;
                    int cur=(j+1<(int)v.size()?v[j+1]:0)+(k==0?0:1);
                    upd(dp2[j+1][0],dp2[j][k]+(j+1)*cur);
                    upd(dp2[j+1][1],dp2[j][k]+(j+1)*(10-cur));
                }
            ans=min(ans,max(i,dp2[50][0]));
        }
    }
    printf("%d\n",ans);
}