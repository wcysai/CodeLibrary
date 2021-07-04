#include<bits/stdc++.h>
#define MAXN 8005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dp[MAXN][MAXN];
char str[MAXN];
int f[4][MAXN][MAXN];
int cnt[3][MAXN];
vector<P> nlp;
vector<int> v[4];
//0: ) 1: o 2:x
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='(') v[0].push_back(i);
        else if(str[i]==')') {v[1].push_back(i); nlp.push_back(P(0,i));}
        else if(str[i]=='o') {v[2].push_back(i); nlp.push_back(P(1,i));}
        else {v[3].push_back(i); nlp.push_back(P(2,i));}
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<(int)nlp.size();i++)
    {
        for(int j=0;j<3;j++) cnt[j][i+1]=cnt[j][i];
        cnt[nlp[i].F][i+1]++;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<(int)v[i].size();j++)
        {
            for(int k=1;k<=n;k++) f[i][j+1][k]=f[i][j][k];
            for(int k=1;k<v[i][j];k++) f[i][j+1][k]++;
        }
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=i;j++)
        {
            //j left parentheses, i-j not
            if(dp[i][j]==INF) continue;
            int x=j,y=i-j;
            int rp=cnt[0][y],co=cnt[1][y],cx=cnt[2][y];
            printf("i=%d j=%d dp=%d lp=%d rp=%d co=%d cx=%d\n",i,j,dp[i][j],x,rp,co,cx);
            int pre=i-rp;
            assert(pre>=0);
            //trying to fill with a left parenthese 
            if(x<(int)v[0].size()) 
            {
                int pos=v[0][x];
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+f[0][x][pos]+f[1][rp][pos]+f[2][co][pos]+f[3][cx][pos]);
            }
            //trying to fill with a non-left parenthes
            if(y<(int)nlp.size())
            {
                if(nlp[y].F!=2&&pre==0) continue;
                int pos=v[nlp[y].F+1][cnt[y][nlp[y].F]];
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+f[0][x][pos]+f[1][rp][pos]+f[2][co][pos]+f[3][cx][pos]);
            }
        }
    printf("%d\n",dp[n][(int)v[0].size()]);
    return 0;
}