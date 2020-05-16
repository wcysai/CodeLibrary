#include<bits/stdc++.h>
#define MAXN 41
#define MAXM 100005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,c;
int MOD[2]={1000000007,998244353};
int BASE[2]={19260817,324893242};
int p[MAXN][MAXM];
int tmp[MAXM];
int hsh[2][MAXN];
map<P,int> mp;
int main()
{
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&p[i][j]);
    for(int i=0;i<n/2;i++)
    {
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<m;j++) tmp[p[i][j]]++;
        for(int j=0;j<2;j++)
            for(int k=2;k<=c;k++) 
            {
                hsh[j][i]=(1LL*hsh[j][i]*BASE[j]+(tmp[k]-tmp[1]))%MOD[j];
                if(hsh[j][i]<0) hsh[j][i]+=MOD[j];
            }
    }
    for(int i=n/2;i<n;i++)
    {
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<m;j++) tmp[p[i][j]]++;
        for(int j=0;j<2;j++)
            for(int k=2;k<=c;k++) 
            {
                hsh[j][i]=(1LL*hsh[j][i]*BASE[j]+(tmp[1]-tmp[k]))%MOD[j];
                if(hsh[j][i]<0) hsh[j][i]+=MOD[j];
            }
    }
    int ans=0;
    for(int i=0;i<(1<<(n/2));i++)
    {
        int h1=0,h2=0;
        for(int j=0;j<n/2;j++)
        {
            if(i&(1<<j))
            {
                h1=(h1+hsh[0][j])%MOD[0];
                h2=(h2+hsh[1][j])%MOD[1];
            }
        }
        mp[P(h1,h2)]=max(mp[P(h1,h2)],__builtin_popcount(i));
    }
    for(int i=0;i<(1<<(n-n/2));i++)
    {
        int h1=0,h2=0;
        for(int j=n/2;j<n;j++)
        {
            if(i&(1<<(j-n/2)))
            {
                h1=(h1+hsh[0][j])%MOD[0];
                h2=(h2+hsh[1][j])%MOD[1];
            }
        }
        if(mp.find(P(h1,h2))!=mp.end()) ans=max(ans,mp[P(h1,h2)]+__builtin_popcount(i));
    }
    printf("%d\n",ans);
    return 0;
}