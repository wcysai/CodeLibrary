/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-14 23:57:30
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
char str[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) 
    {
        a[i]=a[i-1];
        if(str[i]=='1') a[i]++;
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int len=r-l+1,cnt=a[r]-a[l-1];
        int ans=1LL*(pow_mod(2,cnt)-1)%MOD;
        ans=1LL*ans*pow_mod(2,len-cnt)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

