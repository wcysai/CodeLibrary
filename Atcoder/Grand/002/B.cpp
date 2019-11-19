#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,cnt[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d%d",&N,&M);
    memset(has,false,sizeof(has));
    for(int i=1;i<=N;i++) cnt[i]=1;
    has[1]=true;
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(has[x]) has[y]=true;
        cnt[x]--; cnt[y]++;
        if(!cnt[x]) has[x]=false;
    }
    int ans=0;
    for(int i=1;i<=N;i++) if(has[i]) ans++;
    printf("%d\n",ans);
    return 0;
}
