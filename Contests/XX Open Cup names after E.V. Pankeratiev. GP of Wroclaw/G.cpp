#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int T;
int b[MAXN][MAXN],c[MAXN][MAXN],vis[MAXN*MAXN],n,m;
int row[4][MAXN][MAXN],col[4][MAXN][MAXN];

int a[MAXN][MAXN];
int r[MAXN*MAXN]; // r[x] = row of element x
int p[MAXN][MAXN]; // p[x][y] = row of element y in column x

int nxt(int row)
{
	int col = 0;
	while (a[row][col] != -1)
		++col;
	return col;
}
	
void solve(int x[4][MAXN][MAXN])
{
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
            x[3][i][j]=(i-1)*n+j;
    memset(vis,0,sizeof(vis));
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) vis[x[0][i][j]]=true;
        for(int j=(i-1)*n+1;j<=(i-1)*n+n;j++) if(!vis[j]) f=false;
    }
    if(f)
    {
        for(int k=1;k<=2;k++)
            for(int i=1;i<=n;i++) 
                for(int j=1;j<=n;j++)
                    x[k][i][j]=(i-1)*n+j;
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]=(x[0][i][j]+n-1)/n;
    f=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) vis[j]=0;
        for(int j=1;j<=n;j++) vis[c[j][i]]=1;
        for(int j=1;j<=n;j++) if(!vis[j]) f=false;
    }
    if(f)
    {
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)
                x[2][i][j]=(i-1)*n+j;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                x[1][c[i][j]][j]=x[0][i][j];
        return;
    }
    for(int i=0;i<n*n;i++) r[i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            p[i][j]=0;
    for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			r[x[0][i][j]-1] = i-1;
			a[i-1][j-1] = -1;
		}
	for (int i = 0; i < n * n; ++i)
	{
		int row = r[i];
		int col1 = i % n;
		int col2 = nxt(row);
		int val = i / n;
		if (col1 == col2)
		{
			a[row][col1] = val;
			p[col1][val] = row;
		} 
		else 
			while (val != -1)
			{
				p[col1][val] = row;
				swap(val, a[row][col1]);
				a[row][col2] = val;
				if (val != -1)
					swap(row, p[col2][val]);
			}
	}
    for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int val = a[i][j] * n;
			for (int k = 0; k < n; ++k)
				if (r[val + k] == i)
				{
					a[i][j] = val + k;
					r[val + k] = -1;
					break;
				}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			x[1][i+1][j+1]=a[i][j]+1;
	
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < n; ++j)
			for (int k = 0; k < n - j; ++k)
				if (a[k][i] > a[k + 1][i])
					std::swap(a[k][i], a[k + 1][i]);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			x[2][i+1][j+1]=a[i][j]+1;
}
int main()
{
    //freopen("G.in","r",stdin);
    clock_t startTime,endTime;
    startTime = clock();
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&b[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                row[0][i][j]=b[i][j];
        solve(row);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int ii=(b[j][i]+(n-1))/n,jj=(b[j][i]-(ii-1)*n);
                col[0][i][j]=(jj-1)*n+ii;
            }
        solve(col);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=3;i++)
        {
            bool f=true;
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(row[i][j][k]!=row[i-1][j][k]) f=false;
            if(!f) cnt1++;
        }
        for(int i=1;i<=3;i++)
        {
            bool f=true;
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(col[i][j][k]!=col[i-1][j][k]) f=false;
            if(!f) cnt2++;
        }
        if(cnt1<=cnt2)
        {
            printf("%d\n",cnt1);
            for(int i=1;i<=3;i++)
            {
                bool f=true;
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                        if(row[i][j][k]!=row[i-1][j][k]) f=false;
                if(!f) 
                {
                    for(int j=1;j<=n;j++)
                    {
                        for(int k=1;k<=n;k++) printf("%d ",row[i][j][k]);
                        puts("");
                    }
                }
            }
        }
        else
        {
            printf("%d\n",cnt2);
            for(int i=1;i<=3;i++)
            {
                bool f=true;
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                        if(col[i][j][k]!=col[i-1][j][k]) f=false;
                if(!f) 
                {
                    for(int j=1;j<=n;j++)
                    {
                        for(int k=1;k<=n;k++)
                        {
                            int jj=(col[i][k][j]+(n-1))/n,kk=(col[i][k][j]-(jj-1)*n);
                            printf("%d ",(kk-1)*n+jj);
                        }
                        puts("");
                    }
                }
            }
        } 
    }
    endTime = clock();//计时结束
   // cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}