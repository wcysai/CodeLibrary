#include<bits/stdc++.h>
#define maxn 300005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;
pi a[maxn];
int ans,k,b[maxn][18],c[maxn][18],n,query;
bool flag;

int rmq1(int x,int y)
{
    int r=log2(y-x+1);
    return min(b[x][r],b[y-(1<<r)+1][r]);
}

int rmq2(int x,int y)
{
    int r=log2(y-x+1);
    return max(c[x][r],c[y-(1<<r)+1][r]);
}

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d",&n); flag=true;
        for (int i=1;i<=n;i++) scanf("%d",&b[i][0]);
        for (int i=1;i<=n;i++) scanf("%d",&c[i][0]);
        for (int i=1;i<=n;i++) flag&=c[i][0]<=b[i][0];
        if (!flag) {printf("-1\n");continue;}
        for (int j=1;j<18;j++)
            for (int i=1;i+(1<<j)-1<=n;i++)
                b[i][j]=min(b[i][j-1],b[i+(1<<(j-1))][j-1]),
                c[i][j]=max(c[i][j-1],c[i+(1<<(j-1))][j-1]);
        for (int i=1;i<=n;i++) a[i].x=c[i][0],a[i].y=i;
        sort(a+1,a+n+1); ans=0; k=0;
        for (int i=1;i<=n;i++)
        {
            if (i>1&&a[i-1].x==a[i].x&&rmq1(a[i-1].y,a[i].y)>=a[i].x&&rmq2(a[i-1].y,a[i].y)<=a[i].x)
                k|=b[a[i].y][0]!=c[a[i].y][0];
            else ans+=k,k=b[a[i].y][0]!=c[a[i].y][0];
        }
        ans+=k;
        cout << ans << endl;
    }
    return 0;
}