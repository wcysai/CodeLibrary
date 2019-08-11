#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000009
#define BASE 1926817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n;
char str[MAXN];
int p[MAXN],pre[MAXN],suf[MAXN],cnt[MAXN];
db ans[22];
int main()
{
    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=1LL*BASE*p[i-1]%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        cnt[i]=cnt[i-1];
        if(str[i]=='?') cnt[i]++;
        pre[i]=(1LL*BASE*pre[i-1]+(str[i]=='?'?'z'-'a'+1:str[i]-'a'))%MOD;
    }
    for(int i=n;i>=1;i--) suf[i]=(1LL*BASE*suf[i+1]+(str[i]=='?'?'z'-'a'+1:str[i]-'a'))%MOD;
    for(int i=1;i<=n;i++)
    {
        db cur=1.0;int now=1,c=0;
        while(true)
        {
            int l=now,r=min(i,n-i+1)+1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                int lh=(pre[i-now]-1LL*pre[i-mid]*p[mid-now])%MOD;
                if(lh<0) lh+=MOD;
                int rh=(suf[i+now]-1LL*suf[i+mid]*p[mid-now])%MOD;
                if(rh<0) rh+=MOD;
                if(cnt[i-mid]==cnt[i-now]&&lh==rh) l=mid; else r=mid;
            }
            if(i==l||i+l-1==n||(str[i-l]!='?'&&str[i+l]!='?')) {ans[c]+=2*l-1; break;}
            ans[c+1]+=25*(2*l-1);
            cur=cur/26;
            c++;
            if(c>=20) break;
            now=l+1;
        }
    }
    db fans=0,cur=1.0;
    for(int i=0;i<=20;i++)
    {
        fans+=cur*ans[i];
        cur/=26;
    }
    printf("%.10Lf\n",fans/n);
    return 0;
}

