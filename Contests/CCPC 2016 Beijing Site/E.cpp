#include<bits/stdc++.h>
#define MAXN 125
#define INF 100000000
using namespace std;
int perm[120][5],a[5],dis[MAXN],num[4],res,in[5];
char str[5];
int cal(int x)
{
    int ans=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<i;j++)
            if(perm[x][j]>perm[x][i]) ans++;
    return ans;
}
int convert(int *a)
{
    int ans=0;
    bool used[6];
    memset(used,false,sizeof(used));
    for(int i=0;i<5;i++)
    {
        if(a[i]<=0||a[i]>5) return -1;
        if(used[a[i]]) return -1;
        used[a[i]]=true;
    }
    for(int i=0;i<5;i++)
    {
        int cnt=0;
        for(int j=i+1;j<5;j++)
            if(a[j]<a[i]) cnt++;
        ans+=cnt*num[i];
    }
    return ans;
}
void dfs(int *p,int k,int a,int b)
{
    if(k==5)
    {
        int x=convert(p);
        if(x==-1) return;
        res=min(res,dis[x]+5-a-b);
    }
    if(p[k]>=1&&p[k]<=5) dfs(p,k+1,a,b);
    if(a>0)
    {
        int t=p[k];
        p[k]=t-1;
        if(p[k]<0) p[k]+=10;
        dfs(p,k,a-1,b);
        p[k]=t;
    }
    if(b>0)
    {
        int t=p[k];
        if(p[k]&1) return;
        else
        {
            p[k]/=2;
            dfs(p,k,a,b-1);
            p[k]=t;
             p[k]=(p[k]+10)/2;
            dfs(p,k,a,b-1);
            p[k]=t;
        }
    }
}
int main()
{
    for(int i=0;i<5;i++)
        perm[0][i]=a[i]=i+1;
    num[0]=24;
    num[1]=6;
    num[2]=2;
    num[3]=1;
    num[4]=0;
    int cnt=1;
    while(next_permutation(a,a+5))
    {
        for(int i=0;i<5;i++)
            perm[cnt][i]=a[i];
        cnt++;
    }
    for(int i=0;i<120;i++)
        dis[i]=cal(i);
    while(cin>>str)
    {
        for(int i=0;i<5;i++)
            in[i]=str[i]-'0';
        res=INF;
        dfs(in,0,3,2);
        if(res==INF) printf("-1\n"); else printf("%d\n",res);
    }
    return 0;
}
