#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[10][10];
int dp[6][(1<<25)];
vector<int> v;
void add(int &a,int b) {a+=b; }
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    int mask=0,mmask=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(str[i][j]!='X') mask|=(1<<(i*n+j));
            if(str[i][j]=='O') mmask|=(1<<(i*n+j));
        }
    dp[0][mask]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<=mask;j++)
        {
            if((mask&j)!=j) continue;
            if(!dp[i][j]) continue;
            for(int ii=0;ii+v[i]-1<n;ii++)
                for(int jj=0;jj<n;jj++)
                {
                    bool f=true;
                    int nmask=j;
                    for(int k=0;k<v[i];k++) if(!(j&(1<<((ii+k)*n+jj)))) {f=false; break;} else nmask^=(1<<((ii+k)*n+jj));
                    if(f) add(dp[i+1][nmask],dp[i][j]);
                }
            if(v[i]!=1)
            {
                for(int ii=0;ii<n;ii++)
                    for(int jj=0;jj+v[i]-1<n;jj++)
                    {
                        bool f=true;
                        int nmask=j;
                        for(int k=0;k<v[i];k++) if(!(j&(1<<(ii*n+(jj+k))))) {f=false; break;} else nmask^=(1<<((ii*n+(jj+k))));
                        if(f) add(dp[i+1][nmask],dp[i][j]);
                    }
            }
        } 
    int ans=0;
    for(int i=0;i<=mask;i++) 
    {
        if((mask&i)!=i) continue;
        if(i&mmask) continue;
        add(ans,dp[m][i]);
    }
    printf("%d\n",ans);
}