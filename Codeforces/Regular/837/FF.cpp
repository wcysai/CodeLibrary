#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> P;
int n,q,sz,tot,a[MAXN],root[MAXN],cnt,id[MAXN];
uint save[MAXM][MAXN];
uint s[MAXN];
vector<int> pos[MAXN];
vector<int> dis;
uint mi[MAXN];
mt19937 rice(time(NULL)); 
const int blocks=1000;
int solve(int l,int r)
{
    int last=-1;
    for(int i=1;i<=cnt;i++)
    {
        if(save[i][r]!=save[i][l-1])
        {
            last=id[i-1]+1;
            break;
        }
    }
    if(last==-1) return 0;
    for(int i=last;i<=sz;i++)
    {
        int len=lower_bound(pos[i].begin(),pos[i].end(),r+1)-lower_bound(pos[i].begin(),pos[i].end(),l);
        if(len&1) return dis[i-1];
    }
    assert(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); dis.push_back(a[i]);
    }
    scanf("%d",&q);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        pos[id].push_back(i);
    }
    sz=(int)dis.size();
    for(int i=1;i<=sz;i++) mi[i]=rice();
    int last=0;
    for(int i=1;i<=sz;i++)
    {
        for(auto x:pos[i]) s[x]^=mi[i];
        if(i%blocks==0||i==sz) 
        {
            cnt++; id[cnt]=i;
            for(int j=1;j<=n;j++) save[cnt][j]=s[j];
            for(int j=2;j<=n;j++) save[cnt][j]^=save[cnt][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l^=ans; r^=ans;
        ans=solve(l,r);
        printf("%d\n",ans);
    }
    return 0;
}




