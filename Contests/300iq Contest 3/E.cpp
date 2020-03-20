#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int sum[MAXN];
int ssum[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]^=1;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int len=1;
    for(int t=1;t<=20;t++)
    {
        memset(ssum,0,sizeof(ssum));
        for(int i=1;i+len-1<=n;i++) ssum[i]=sum[i+len-1]-sum[i-1];
        len*=2;
        for(int i=1;i<=n;i++) if(i>=len) ssum[i]+=ssum[i-len];
        for(int rem=2;rem<=n+1;rem++)
        {
            for(int st=0;st<=n;st+=rem)
            {
                int ed=min(n,st+rem-1);
                if(ed-st+1>=len)
                {
                    int l=st+len/2;
                    int r=ed-(ed-st+1)%len-len/2+1;
                    if((ssum[r]-(l<len?0:ssum[l-len]))&1) ans[rem]^=(1<<(t-1));
                }
                if((ed-st+1)%len>len/2)
                {
                    int l=ed-(ed-st+1)%len+len/2+1;
                    if((sum[ed]-sum[l-1])&1) ans[rem]^=(1<<(t-1));
                }
            }
        }
    }
    for(int i=2;i<=n+1;i++) if(!ans[i]) printf("Bob "); else printf("Alice ");
    puts("");
    return 0;
}