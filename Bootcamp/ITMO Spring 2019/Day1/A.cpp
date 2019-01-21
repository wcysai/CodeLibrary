#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,b,o;
char str[MAXN];
int fact[300005];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
vector<int> v;
int main()
{
    fact[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*(2*i-1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str+1);v.clear();
        n=strlen(str+1);
        int cnt=0,last=-1;
        for(int i=1;i<=n;i++)
        {
            int now=str[i]=='O'?0:1;
            if(last==-1) {last=now; cnt=1; continue;}
            if(last==now) cnt++; 
            else
            {
                v.push_back(cnt);
                cnt=1;last=now;
            }
        }
        v.push_back(cnt);
        int sz=(int)v.size();
        if(sz&1)
        {
            int id=(sz-1)/2;
            printf("%d\n",fact[id]);
            continue;
        }
        int ans=0,id=sz/2;
        for(int i=0;i<sz/2;i++) add(ans,1LL*(v[i*2]+1)*fact[id-i]%MOD*fact[i]%MOD);
        for(int i=0;i<sz/2;i++) add(ans,1LL*(v[i*2+1]+1)*fact[id-i]%MOD*fact[i]%MOD);
        printf("%d\n",ans);
    }
    return 0;
}

