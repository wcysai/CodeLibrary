/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 17:06:13
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
int T,n,m,k;
int cnt[1025];
char ch[15];
int a[MAXN];
int main()
{
    scanf("%d",&T);
    int tot=0;
    while(T--)
    {
        tot++;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%s",ch);
            int x=0;
            for(int j=0;j<m;j++) x=x*2+(ch[j]-'A');
            a[i]=x;
        }
        int ans=0;
        for(int i=0;i<(1<<m);i++)
        {
            int res=n*(n-1)/2;
            memset(cnt,0,sizeof(cnt));
            for(int j=0;j<n;j++) cnt[a[j]&i]++;
            for(int j=0;j<(1<<m);j++) res-=cnt[j]*(cnt[j]-1)/2;
            if(res>=k) ans++;
        }
        printf("Case #%d: %d\n",tot,ans);
    }
    return 0;
}

