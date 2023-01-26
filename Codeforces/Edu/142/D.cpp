#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,tot,n,m;
int trie[MAXM][11],cnt[MAXM];
int p[MAXN][11],rev[MAXN][11];
bool ed[MAXN];
void ins(int id)
{
    int rt=0;
    cnt[rt]++;
    for(int i=1;i<=m;i++)
    {
        int x=rev[id][i];
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
        cnt[rt]++;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%d",&p[i][j]);
            for(int j=1;j<=m;j++) rev[i][p[i][j]]=j;
            ins(i);
        }
        for(int i=1;i<=n;i++){
            int ans=0,rt=0;
            for(int j=1;j<=m;j++){
                int x=p[i][j];
                if(trie[rt][x]){
                    ans++;
                    rt=trie[rt][x];
                }
                else break;
            }
            printf("%d%c",ans,i==n?'\n':' ');
        }
        for(int i=0;i<=tot;i++) {
            cnt[i]=0;
            for(int j=1;j<=m;j++) trie[i][j]=0;
        }
    }
    return 0;
}


