#include<bits/stdc++.h>
#define MAXN 8000005
using namespace std;
int t,n,m,k,p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        init(2*(n+m-2));
        for(int i=1;i<=k;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int x=max(a,c),y=max(b,d);
            x--; y--; y+=(n-1);
            if(d==b+1)
            {
                unite(x,n+m-2+y);
                unite(n+m-2+x,y);
            }
            else{
                unite(x,y);
                unite(n+m-2+x,n+m-2+y);
            }
        }
        bool f=true;
        for(int i=1;i<=n+m-2;i++){
            if(same(i,n+m-2+i)) {f=false; break;}
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

