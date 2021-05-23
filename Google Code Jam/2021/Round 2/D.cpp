#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,r,c,f,s;
string a[MAXN],b[MAXN];
int w[MAXM][MAXM];
//minimum weight bipartite matching
ll km(int n,int m)
{
    vector<int> u(n+1),v(m+1),p(m+1),way(m+1);
    for(int i=1;i<=n;i++) 
    {
        p[0]=i;
        int j0=0;
        vector<int> minv(m+1,INF);
        vector<char> used(m+1,false);
        do 
        {
            used[j0]=true;
            int i0=p[j0],delta=INF,j1;
            for(int j=1;j<=m;++j)
                if(!used[j]) 
                {
                    int cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            for(int j=0;j<=m;++j) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do 
        {
            int j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    ll res=0;
    for(int i=1;i<=m;i++) res+=w[p[i]][i];
    return res;
}
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d%d%d",&r,&c,&f,&s);
        for(int i=0;i<r;i++) cin>>a[i];
        for(int i=0;i<r;i++) cin>>b[i];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                for(int k=0;k<r;k++)
                    for(int l=0;l<c;l++)
                    {
                        int cost=(max(i-k,k-i)+max(j-l,l-j))*s+(a[i][j]==b[k][l]?0:2*f);
                        w[i*c+j+1][k*c+l+1]=cost;
                    }
        printf("Case #%d: %d\n",_,km(r*c,r*c)/2);
    }
    return 0;
}