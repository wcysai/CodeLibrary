#include<bits/stdc++.h>
#define MAXN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
ll ans=0;
ll pre[MAXN];
ll p10[MAXN];
int len,lim;
ll dp[MAXN][2][2][2];
ll solve(int now,int lead,int less,int cnt)
{
    if(now==lim) return (less?1:0);
    ll &res=dp[now][lead][less][cnt];
    if(res!=-1) return res;
    res=0;
    int limit=(less?9:str[now]-'0');
    for(int i=0;i<=limit;i++) 
    {
        if(!lead&&(i==0)) continue;
        res+=solve(now+1,lead||(i>0),less||(i<limit),cnt);
    }
    if(!cnt&&2*now+1!=len)
    {
        for(int i=0;i<=limit;i++) 
        {
            if(!lead&&(i==0)) continue;
            res+=9*solve(now+1,lead||(i>0),less||(i<limit),cnt+1);
        }
    }
    return res;
}
int main()
{
    freopen("almost.in","r",stdin);
    freopen("almost.out","w",stdout);
    p10[0]=1;
    for(int i=1;i<=18;i++) p10[i]=10LL*p10[i-1];
    pre[1]=9;
    pre[2]=90;
    for(int i=3;i<=18;i++)
    {
        if(i&1) pre[i]=10LL*pre[i-1];
        else
        {
            ll pal=9LL*p10[i/2-2];
            pre[i]=90LL*pal+10LL*pre[i-2];
        }
    }
    while(cin>>str)
    {
        if(str=="0") break;
        ans=0;
        len=(int)str.size();
        if(len==1)
        {
            printf("%d\n",(int)str[0]-'0');
            continue;
        }
        for(int i=1;i<len;i++) ans+=pre[i];
        string s=str.substr(0,(len+1)/2);
        string t=str.substr(0,len/2);
        reverse(t.begin(),t.end());
        s+=t;
        if(s<=str) ans++;
        for(int i=(len+1)/2;i<len;i++)
        {
            char ch=s[i];
            for(int j=0;j<=9;j++)
            {
                if(ch-'0'==j) continue;
                s[i]=(char)('0'+j);
                if(s<=str) ans++;
            }
            s[i]=ch;
        }
        memset(dp,-1,sizeof(dp));
        lim=(len+1)/2;
        ans+=solve(0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
