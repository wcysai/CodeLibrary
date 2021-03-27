#include<bits/stdc++.h>
#define MAXN 250005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x[MAXN];
bool used[MAXN];
int eve[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&x[i]);
    int k=1;
    for(int i=2;i<=m;i++) if(x[i]>x[i-1]) k++; else break;
    memset(used,false,sizeof(used));
    memset(eve,0,sizeof(eve));
    for(int i=1;i<=m;i++) used[x[i]]=true;
    for(int i=1;i<=k;i++) eve[x[i]]+=(i==k?2:1);
    int cnt=0,ans=1;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            ans=1LL*ans*cnt%MOD;
            cnt++;
        }
        cnt+=eve[i];    
    }
    printf("%d\n",ans);
    return 0;
}