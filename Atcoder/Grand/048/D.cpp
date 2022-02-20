#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll l[MAXN][MAXN],r[MAXN][MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) l[i][i]=r[i][i]=1;
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(r[i+1][j]>a[j]) l[i][j]=1;
				else l[i][j]=a[j]-r[i+1][j]+l[i][j-1]+1;
				if(l[i][j-1]>a[i]) r[i][j]=1;
				else r[i][j]=a[i]-l[i][j-1]+r[i+1][j]+1; 
			}
		}
		if(l[1][n]>a[1]) puts("Second"); else puts("First");
	}
	return 0;
}