#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
char str[MAXN];
int n;
int nxt[MAXN];
int main()
{
    freopen("bad.in","r",stdin);
    freopen("bad.out","w",stdout);
    scanf("%s",str+1);
    n=strlen(str+1);
    int last=-1,cnt=0;
    for(int i=n;i>=1;i--)
    {
        nxt[i]=last;
        if(str[i]=='1') {last=i; cnt++;}
    }
    int ans=INF;
    if(last!=-1) ans=min(ans,n-last+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='1')
        {
            if(nxt[i]==-1) ans=min(ans,i-1);
            else
            {
                int l=i-1,r=n-nxt[i]+1;
                int res=2*min(l,r)+max(l,r);
                ans=min(ans,res);
            }
        }
    }
    if(ans==INF) ans=0;
    printf("%d\n",ans*7+4*cnt);
    return 0;
}
