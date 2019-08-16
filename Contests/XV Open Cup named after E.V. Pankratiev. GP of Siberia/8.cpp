#include <bits/stdc++.h>
#define ll long long
#define MAXN 2030
using namespace std;

inline int read()
{
    int ch=getchar(),f=0;
    int x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f?-x:x;
}
int n,m;
double a[MAXN][MAXN],tp[MAXN<<1];
int soze[MAXN<<1],ys[MAXN<<1],fy[MAXN<<1];
bool used[MAXN<<1];
#define P pair<double,int>
priority_queue<P,vector<P>,greater<P> > bob[MAXN];
char s[MAXN];
inline bool eq(double a,double b)
{
    return fabs(a-b)<(1e-10);
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=n;j++)
            a[i][j]=s[j]-'0';
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
        bob[i].push(P(a[i][j],j));
    for(int i=1;i<=n;i++)
        soze[i]=1,ys[i]=i,fy[i]=i;
    for(int T=1;T<n;T++)
    {
        int ir=1;
        for(int j=1;j<=n;j++)
            while(!bob[j].empty()&&used[bob[j].top().second])
                bob[j].pop();
        for(ir=1;ir<=n;ir++)
            if(!bob[ir].empty())
                break;
        int minx=ir,mx=ir;
        for(ir=ir+1;ir<=n;ir++)
            if(!bob[ir].empty()&&bob[ir].top().first<=bob[minx].top().first)
            minx=ir;
        //for(int j=1;j<=n;j++)
        //printf("%.10f\n",bob[j].top().first);
        //printf("%d\n",minx);
        mx=bob[minx].top().second;minx=fy[minx];used[minx]=1;
        //printf("%d %d\n",mx,minx);
        used[mx]=1;soze[n+T]=soze[mx]+soze[minx];ys[n+T]=ys[mx];fy[ys[mx]]=n+T;
        printf("%d %d %.10f\n",mx,minx,bob[ys[minx]].top().first);
        for(int i=1;i<=n;i++)
            tp[i]=0;
        while(!bob[ys[minx]].empty())
        {
            P now=bob[ys[minx]].top();
            if(!used[now.second])
                tp[ys[now.second]]+=now.first*soze[minx];//printf("%d %.10f\n",now.second,tp[ys[now.second]]);
            bob[ys[minx]].pop();
        }
        while(!bob[ys[mx]].empty())
        {
            P now=bob[ys[mx]].top();//printf("%d\n",soze[fy[mx]]);
            if(!used[now.second])
                tp[ys[now.second]]+=now.first*soze[mx];//printf("%d %.10f\n",now.second,tp[ys[now.second]]);
            bob[ys[mx]].pop();
        }
        for(int i=1;i<=n;i++)
            if(!used[fy[i]]&&fy[i]!=n+T)
            bob[ys[n+T]].push(P(tp[i]/soze[n+T],fy[i])),bob[i].push(P(tp[i]/soze[n+T],n+T));
        //for(int i=1;i<=n;i++)
            //printf("%d %d %d %.10f\n",fy[i],ys[i],bob[i].size(),tp[i]/soze[n+T]);
    }
    return 0;
}
