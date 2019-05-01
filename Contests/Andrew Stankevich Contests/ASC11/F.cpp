#include<bits/stdc++.h>
#define MAXN 45
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dokdasdo
#define y1 okadso
#define x2 doakdos
#define y2 dksapds
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n1,m1,n2,m2;
char a[MAXN][MAXN],b[MAXN][MAXN];
int area;
int c[MAXN][MAXN],h[MAXN],L[MAXN],R[MAXN],st[MAXN];
int x1,y1,x2,y2,t,height,width;
void solve(int n,int m,int sx1,int sy1,int sx2,int sy2)
{
    memset(h,0,sizeof(h));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) if(!c[i][j]) h[j]=0; else h[j]++;
        int t=0;
        for(int j=1;j<=m;j++)
        {
            while(t>0&&h[st[t-1]]>=h[j]) t--;
            L[j]=t==0?0:st[t-1];
            st[t++]=j;
        }
        t=0;
        for(int j=m;j>=1;j--)
        {
            while(t>0&&h[st[t-1]]>=h[j]) t--;
            R[j]=t==0?m+1:st[t-1];
            st[t++]=j;
        }
        for(int j=1;j<=m;j++)
        {
            if(h[j]*(R[j]-L[j]-1)>area)
            {
                height=h[j]; width=R[j]-L[j]-1;
                area=height*width; 
                int x=i-h[j]+1,y=L[j]+1;
                x1=x+(sx1-1); y1=y+(sy1-1); x2=x+(sx2-1); y2=y+(sy2-1);
            }
        }
    }
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d%d",&n1,&m1);
    for(int i=1;i<=n1;i++) scanf("%s",a[i]+1);
    scanf("%d%d",&n2,&m2);
    for(int i=1;i<=n2;i++) scanf("%s",b[i]+1);
    for(int i=1-n1;i<=n2-1;i++)
        for(int j=1-m1;j<=m2-1;j++)
        {
            int n=0,m=0,stn=-1,stm=-1;
            for(int k=1;k<=n1;k++) if(k+i>=1&&k+i<=n2) {n++; if(stn==-1) stn=k;}
            for(int k=1;k<=m1;k++) if(k+j>=1&&k+j<=m2) {m++; if(stm==-1) stm=k;}
            if(stn==-1||stm==-1) continue;
            for(int k=stn;k<=stn+n-1;k++)
                for(int l=stm;l<=stm+m-1;l++)
                    c[k-stn+1][l-stm+1]=(a[k][l]==b[k+i][l+j]?1:0);
            solve(n,m,stn,stm,stn+i,stm+j);
        }
    if(area==0) {puts("0 0"); return 0;}
    printf("%d %d\n%d %d\n%d %d\n",height,width,x1,y1,x2,y2);
    return 0;
}
