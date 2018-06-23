#include<bits/stdc++.h>
#define maxn 777
 
using namespace std;
bool f[maxn][maxn],g[maxn][maxn*2],vis[maxn],flag,h[maxn];
int n,m,a[maxn],b[maxn],p,q,r,o;
 
void dfs(int u,bool d){
    h[u]=d; vis[u]=true; if (d) p++; else q++;
    for (int i=1;i<=n;i++) if (f[u][i]){
        if (!vis[i]) dfs(i,d^1);
        else if (d==h[i]) flag=true;
    }
}
 
int main(){
    cin >> n >> m;
    memset(f,true,sizeof(f));
    for (int i=1;i<=n;i++) f[i][i]=0;
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        f[u][v]=f[v][u]=0;
    }
    for (int i=1;i<=n;i++) if (!vis[i]) {
        dfs(i,0); r++;
        a[r]=p; b[r]=q;
        p=0; q=0;
    }
    if (flag) {cout << -1 << endl; return 0;}
    g[0][n]=true;
    for (int i=1;i<=r;i++)
        for (int j=0;j<=n*2;j++)
            if (g[i-1][j]) g[i][j+b[i]-a[i]]=true,g[i][j-b[i]+a[i]]=true;
    o=n;
    for (int i=0;i<=n*2;i++) if (g[r][i]) o=min(o,abs(n-i));
    p=(n+o)/2; q=(n-o)/2;
    printf("%d\n",p*(p-1)/2+q*(q-1)/2);
    return 0;
}
