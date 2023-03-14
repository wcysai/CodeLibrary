#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int mult,ans,sum[MAXN][MAXN],cntr[MAXN],cntc[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int go(int x,int y){
    if(x>n||y>m) return 0;
    vector<int> row,col;
    row.push_back(0); col.push_back(0);
    int res=1;
    int need=sum[n][m]/x;
    for(int i=1;i<=n-1;i++){
        if((int)row.size()==x) break;
        if(sum[i][m]==((int)row.size())*need) {res=1LL*res*cntr[i]%MOD; row.push_back(i);}
    }
    need=sum[n][m]/y;
    for(int i=1;i<=m-1;i++){
        if((int)col.size()==y) break;
        if(sum[n][i]==((int)col.size())*need) {res=1LL*res*cntc[i]%MOD; col.push_back(i);}
    }
    if(row.size()!=x) return 0;
    if(col.size()!=y) return 0;
    row.push_back(n); col.push_back(m);
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if(sum[row[i]][col[j]]-sum[row[i-1]][col[j]]-sum[row[i]][col[j-1]]+sum[row[i-1]][col[j-1]]!=2) return 0;
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    int s=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++) if(str[i][j]=='Y') sum[i][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    if(sum[n][m]&1) {puts("0"); return 0;}
    mult=1;
    //cntr[n+1]=cntc[m+1]=1;
    for(int i=n;i>=1;i--) if(sum[i+1][m]==sum[i][m]) cntr[i]=cntr[i+1]+1; else cntr[i]=1;
    for(int i=m;i>=1;i--) if(sum[n][i]==sum[n][i+1]) cntc[i]=cntc[i+1]+1; else cntc[i]=1;
    ans=0;
    for(int i=1;i*i<=sum[n][m]/2;i++){
        if((sum[n][m]/2)%i) continue;
        add(ans,go(i,sum[n][m]/2/i));
        if(i*i*2!=sum[n][m]) add(ans,go(sum[n][m]/2/i,i));
    }
    printf("%d\n",ans);
    return 0;
}

