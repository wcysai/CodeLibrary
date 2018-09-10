/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 08:43:32
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
ll n,k,f[MAXN],g[MAXN];
char str[100];
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    f[n]=1;
    for(ll i=n-1;i>=1;i--)
        f[i]=2*f[i+1]+1;
    g[n]=(str[n]=='0')?0:1;
    ll last;
    if(str[n]=='1') last=n; else last=n+1;
    for(ll i=n-1;i>=1;i--)
    {
        if(str[i]=='0') g[i]=g[i+1];
        else
        {
            if(last==n+1) g[i]=f[i];
            else
            {
                ll res=g[last+1];
                for(ll j=i+1;j<=last;j++)
                    res+=f[j]+1;
                g[i]=res;
            }
            last=i;
        }
    }
    printf("%lld\n",g[1]);
    return 0;
}
