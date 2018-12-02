/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 18:29:12
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int read()
{
    char ch=' ';
    int ans=0;
    while(ch<'0' || ch>'9')
        ch=getchar();
    while(ch<='9' && ch>='0')
    {
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt[MAXN];
int fst[2*MAXN],last[2*MAXN];
int main()
{
    n=read();
    for(int i=1;i<=n;i++) 
    {
        a[i]=read();
        cnt[a[i]]++;
    }
    int mx=0,id=-1;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>mx)
        {
            mx=cnt[i];
            id=i;
        }
    }
    if(mx==n)
    {
        puts("yjztxdy");
        return 0;
    }
    else if(mx*2<=n)
    {
        printf("%d\n%d\n",n,1);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=id) a[i]=1+a[i-1];
        else a[i]=-1+a[i-1];
    }
    for(int i=0;i<=2*n;i++) fst[i]=INF;
    fst[n]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(fst[n+a[i]]==INF) fst[n+a[i]]=i;
        last[n+a[i]]=i;
    }
    for(int i=1;i<=2*n;i++)
    {
        fst[i]=min(fst[i],fst[i-1]);
    }
    for(int i=0;i<=2*n;i++) if(last[i]!=0) ans=max(ans,last[i]-fst[i]);
    int cnt=0;
    for(int i=1;i+ans-1<=n;i++) if(a[i+ans-1]-a[i-1]>=0) cnt++;
    printf("%d\n%d\n",ans,cnt);
    return 0;
}

