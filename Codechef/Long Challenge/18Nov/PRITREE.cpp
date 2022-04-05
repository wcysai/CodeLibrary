/*************************************************************************
    > File Name: PRITREE.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-11 01:01:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,V[MAXN],cur,s;
mt19937 wcy(time(NULL));
int a[MAXN],b[MAXN],sum[MAXN];
vector<int> G[MAXN];
int pow_mod(int a,int i,int n)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%n;
        a=1LL*a*a%n;
        i>>=1;
    }
    return s;
}
bool test(int n,int a,int d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    int t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(long long)t*t%n;
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(int n)
{
    if(n<2) return false;
    int a[]={2,3,61};
    for(int i=0;i<=2;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
void dfs(int v,int p)
{
    sum[v]=V[v];
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sum[v]+=sum[to];
    }
    if(p)
    {
        if(isPrime(sum[v])) cur++;
        if(isPrime(s-sum[v])) cur++;
    }
}
int main()
{
    scanf("%d",&N);
    int ans=-1;s=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&V[i]);s+=V[i];
    }
    memset(a,-1,sizeof(a));
    for(int i=0;i<3000;i++)
    {
        for(int j=1;j<=N;j++) G[j].clear();
        for(int j=2;j<=N;j++) 
        {
            b[j]=wcy()%(j-1)+1;
            G[j].push_back(b[j]);
            G[b[j]].push_back(j);
        }
        cur=0;dfs(1,0);
        if(cur>ans)
        {
            ans=cur;
            for(int j=2;j<=N;j++) a[j]=b[j];
        }
    }
    for(int i=2;i<=N;i++) printf("%d %d\n",a[i],i);
    return 0;
}

