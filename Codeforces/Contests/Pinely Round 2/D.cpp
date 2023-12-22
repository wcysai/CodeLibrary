#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
char str[MAXN][MAXN];
char ans[MAXN][MAXN];
vector<int> row[MAXN];
vector<int> col[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        for(int i=1;i<=n;i++) row[i].clear();
        for(int i=1;i<=m;i++) col[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) ans[i][j]='.';
            ans[i][m+1]='\0';
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(str[i][j]=='L') col[j].push_back(i);
                if(str[i][j]=='U') row[i].push_back(j);
            }
        bool f=true;
        for(int i=1;i<=n;i++){
            if(row[i].size()&1){
                f=false;
                break;
            }
            for(int j=0;j<(int)row[i].size();j++){
                int x=row[i][j];
                if(j&1){
                    ans[i][x]='B'; ans[i+1][x]='W';
                }
                else{
                    ans[i][x]='W'; ans[i+1][x]='B';
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(col[i].size()&1){
                f=false;
                break;
            }
            for(int j=0;j<(int)col[i].size();j++){
                int x=col[i][j];
                if(j&1){
                    ans[x][i]='B'; ans[x][i+1]='W';
                }
                else{
                    ans[x][i]='W'; ans[x][i+1]='B';
                }
            }
        }
        if(!f) puts("-1");
        else{
            for(int i=1;i<=n;i++) printf("%s\n",ans[i]+1);
        }
    }
    return 0;
}

