#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[MAXN][MAXN];
int r1[MAXN][MAXN],r2[MAXN][MAXN],bad[MAXN][MAXN];
int maxr1[MAXN],maxr2[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        r1[i][m+1]=r2[i][m+1]=bad[i][m+1]=m+1;
        for(int j=m;j>=1;j--)
        {
            if(s[i][j]=='m') r1[i][j]=j; else r1[i][j]=r1[i][j+1];
            if(s[i][j]=='#') bad[i][j]=j; else bad[i][j]=bad[i][j+1];
        }
        for(int j=1;j<=m;j++)
        {
            if(r1[i][j]==m+1) r2[i][j]=m+1; else r2[i][j]=r1[i][r1[i][j]+1];
            r1[i][j]--; r2[i][j]--;
            r1[i][j]=min(r1[i][j],bad[i][j]-1); r2[i][j]=min(r2[i][j],bad[i][j]-1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cnt[j]=0,maxr1[j]=maxr2[j]=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=m;k++) 
            {
                if(s[j][k]=='#') cnt[k]=INF; else if(s[j][k]=='m') cnt[k]++;
            }
            if(j-i>=2)
            {
                for(int k=1;k<=m;k++) 
                {
                    maxr1[k]=max(maxr1[k],r1[j-1][k]);
                    maxr2[k]=max(maxr2[k],r2[j-1][k]);
                }
            }
            if(j-i>=2)
            {
                queue<int> max0,max1,max2;
                for(int k=m;k>=1;k--)
                {
                    if(cnt[k]>1) continue;
                    while(max0.size()&&maxr2[k+1]<max0.front()-1) max0.pop();
                    while(max1.size()&&maxr1[k+1]<max1.front()-1) max1.pop();
                    while(max2.size()&&maxr1[k+1]<max2.front()-1) max2.pop();
                    if(max2.size()&&max2.front()>k+1) ans=max(ans,2*(j-i+1)+max2.front()-k-1);
                    if(!cnt[k]) 
                    {
                        if(max1.size()&&max1.front()>k+1) ans=max(ans,2*(j-i+1)+max1.front()-k-1);
                        if(max0.size()&&max0.front()>k+1) ans=max(ans,2*(j-i+1)+max0.front()-k-1);
                    }
                    max1.push(k); 
                    if(!cnt[k]) {max0.push(k); max2.push(k);}
                    //printf("i=%d j=%d k=%d maxr1=%d maxr2=%d ans=%d\n",i,j,k,maxr1[k],maxr2[k],ans);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

