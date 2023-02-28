#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],cnt,cur,rmin,rmax,cmin,cmax;
char str[MAXN][MAXN],tmp[MAXN][MAXN];
int dp[MAXN][2200];
pair<int,P> pre[MAXN][2200];
int p3[MAXN],maxi[MAXN],mini[MAXN];
bool swapped;
void answer(){
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) printf("%c",str[i][j]);
        printf("\n");
    }
}
void rollback(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            str[i][j]=tmp[i][j];
}
int check(int x,int l,int r){
    int z=0;
    int cnt=0;
    for(int j=1;j<=m;j++){
        int a=(x/p3[j-1])%3,b=(j>=l&&j<=r?1:0);
        if(a>0&&b==1) cnt++;
        if(a==2){
            if(b==1) return -1;
            else z+=2*p3[j-1];
        }
        else if(a==1){
            if(b==1) z+=p3[j-1];
            else z+=2*p3[j-1];
        }
        else{
            if(b==1) z+=p3[j-1];
        }
    }
    if(x!=0&&(l<=r)&&cnt==0) return -1;
    return z;
}
void rot(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[j][i]=str[i][j];
    swap(n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            str[i][j]=tmp[i][j];
}
int main()
{
    p3[0]=1;
    for(int i=1;i<=7;i++) p3[i]=3*p3[i-1];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m); swapped=false;
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        if(n<m) 
        {
            swapped=true; rot();
        }
        for(int i=1;i<=n;i++){
            maxi[i]=-INF; mini[i]=INF;
            for(int j=1;j<=m;j++) if(str[i][j]=='#') {maxi[i]=max(maxi[i],j); mini[i]=min(mini[i],j);}
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<p3[m];j++){
                dp[i][j]=INF; pre[i][j]=make_pair(-1,P(-1,-1));
            }
        dp[0][0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<p3[m];j++){
                if(dp[i][j]==INF) continue;
                if(maxi[i+1]==-INF){
                    int z=check(j,m,0);
                    if(z!=-1) {
                        if(dp[i+1][z]>dp[i][j]){
                            dp[i+1][z]=dp[i][j];
                            pre[i+1][z]=make_pair(j,P(-1,-1));
                        }
                    }
                    for(int l=1;l<=m;l++)
                        for(int r=l;r<=m;r++){
                            int z=check(j,l,r);
                            if(z!=-1) {
                                if(dp[i+1][z]>dp[i][j]+r-l+1){
                                    dp[i+1][z]=dp[i][j]+r-l+1;
                                    pre[i+1][z]=make_pair(j,P(l,r));
                                }
                            }
                        }
                }
                else{
                for(int l=1;l<=mini[i+1];l++)
                    for(int r=maxi[i+1];r<=m;r++){
                        int z=check(j,l,r);
                        if(z!=-1) {
                            if(dp[i+1][z]>dp[i][j]+r-l+1){
                                dp[i+1][z]=dp[i][j]+r-l+1;
                                pre[i+1][z]=make_pair(j,P(l,r));
                            }
                        }
                    }
                }
            }
        }
        int mask=p3[m]-1;
        for(int i=0;i<p3[m];i++){
            if(dp[n][i]<dp[n][mask]) mask=i;
        }
        printf("%d\n",dp[n][mask]);
        for(int i=n;i>=1;i--){
            if(pre[i][mask].S.F!=-1) 
            for(int j=pre[i][mask].S.F;j<=pre[i][mask].S.S;j++) str[i][j]='#';
            mask=pre[i][mask].F;
        }
        if(swapped) rot();
        answer();
    }
    return 0;
}

