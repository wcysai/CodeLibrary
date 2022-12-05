#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int p2[MAXN],sum,cur;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
//only lastans matters
//operation 1 turns ans=(2*lastans+len*sum)
//operation 2 turns ans=(2*len+1)*sum
int main()
{
    p2[0]=1;
    for(int i=1;i<=200000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        add(sum,a[i]);
        add(cur,1LL*a[i]*(n+1-i)%MOD);
    }
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        int cursum,curlen,res;
        cursum=1LL*sum*p2[i]%MOD;
        curlen=1LL*n*p2[i]%MOD;
        if(i==0) res=cur;
        else
        {
            int lastsum=1LL*sum*p2[i-1]%MOD;
            int lastlen=1LL*n*p2[i-1]%MOD;
            res=(2LL*lastlen+1)%MOD*lastsum%MOD;
        }
        int round=m-i;
        int nxt=1LL*p2[round]*res%MOD;
        add(nxt,1LL*cursum*curlen%MOD*p2[2*round-1]%MOD);
        dec(nxt,1LL*cursum*curlen%MOD*p2[round-1]%MOD);
        ans=max(ans,nxt);
    }
    printf("%d\n",ans);
    return 0;
}

