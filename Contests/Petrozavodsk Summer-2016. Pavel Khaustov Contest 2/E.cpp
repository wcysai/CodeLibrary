#include <bits/stdc++.h>
#define ll long long
#define MAXN 205
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
int n,m,K;
int a[MAXN][MAXN],g[30],q[30],num[MAXN][MAXN][30];
ll sum[MAXN][MAXN][30],ans;
char s[MAXN];
int lsum[MAXN],rsum[MAXN],ys[30],fy[30];
inline int snum(int i,int j,int x,int y,int k)
{
	return num[i][j][k]-num[i][y][k]-num[x][j][k]+num[x][y][k];
}
inline ll ssum(int i,int j,int x,int y,int k)
{
	return sum[i][j][k]-sum[i][y][k]-sum[x][j][k]+sum[x][y][k];
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=s[j]-'a'+1;
	}
	K=read();
	//printf("%d\n",K);
	for(int i=1;i<=K;i++)
	{
		int ch=getchar();
		while(ch<'a'||ch>'z')
			ch=getchar();
		ys[i]=ch-'a'+1;
		fy[ch-'a'+1]=i;
		q[i]=read(),g[i]=read();
	}
	for(int kk=1,k=ys[kk];kk<=K;kk++,k=ys[kk])
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		num[i][j][kk]=num[i-1][j][kk]+num[i][j-1][kk]-num[i-1][j-1][kk]+(a[i][j]==k);
		sum[i][j][kk]=sum[i-1][j][kk]+sum[i][j-1][kk]-sum[i-1][j-1][kk]+(q[fy[a[i][j]]]<q[kk]?g[fy[a[i][j]]]:0);
	}
	//printf("%d %lld\n",num[n][m][1],sum[3][3][2]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		{
			int l[30],r[30],tmp=1+m;
			memset(l,0,sizeof l),memset(r,0,sizeof r);
			for(int x=1;x<=m;x++)
				lsum[x]=rsum[x]=K;
			for(int x=0;x<m;x++)
			{
				tmp-=(rsum[x]>=lsum[x]);
				int minl=m,maxr=1;
				for(int k=1;k<=K;k++)
				{
					while(r[k]<=m&&ssum(i,r[k],j,x,k)<q[k])
					{
						if(r[k]>x)
						tmp-=(rsum[r[k]]>=lsum[r[k]]),rsum[r[k]]--,tmp+=(rsum[r[k]]>=lsum[r[k]]);
						r[k]++;
					}
					while(l[k]<=m&&l[k]<r[k]&&snum(i,l[k],j,x,k)==0)
					{
						if(l[k]>x)
						tmp-=(rsum[l[k]]>=lsum[l[k]]),lsum[l[k]]--,tmp+=(rsum[l[k]]>=lsum[l[k]]);
						l[k]++;
					}
					if(l[k]<r[k])
					minl=min(minl,l[k]),maxr=max(maxr,r[k]);
					//printf("%d %d %lld\n",l[k],r[k],ssum(2,2,0,0,2));
				}
				//for(int k=x;k<=m;k++)
					//printf("#%d %d %d\n",k,lsum[k],rsum[k]);
				//printf("^%d %d %d %d %d\n",tmp,l[1],r[1],l[2],r[2]);
				//printf("%d %d\n",minl,maxr);
				//if(minl<maxr)
					//ans+=m-x-(maxr-minl);
				//else
					//ans+=m-x;
				ans+=tmp;
				//if(i==3&&j==0)
				//printf("%d %d %d %d\n",i,j,x,ans);
			}
			//printf("%d %d %d\n",i,j,ans);
		}
	printf("%lld\n",ans);
	return 0;
}
