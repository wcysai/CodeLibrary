#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 500000

using namespace std;
int n,m,lhy1[maxn],lhy2[maxn],p1[maxn],p2[maxn],h1[maxn],h2[maxn],x,y,u,v,k,x1[maxn],x2[maxn],snk1,snk2,e;
long long int s,res[maxn],step;
bool f;

int min(int x,int y)
{
	if (x>y) return y; else return x;
}

int abs(int x)
{
	if (x>0) return x; else return -x;
}

void put_in1(int x,int y,int z)
{
    snk1++;
	p1[snk1]=z;
	x1[snk1]=y;
	lhy1[snk1]=h1[x];
	h1[x]=snk1;
}

void put_in2(int x,int y,int z)
{
    snk2++;
	p2[snk1]=z;
	x2[snk1]=y;
	lhy2[snk2]=h2[x];
	h2[x]=snk2;
}

void go()
{
	int cnt1,cnt2,cnt;
	if (u+v){
		cnt=h1[y-x+e];
		while (cnt)
		{
			if (res[p1[cnt]]==-1) res[p1[cnt]]=s+abs(x1[cnt]-x);
			cnt=lhy1[cnt];
		}
	}
	else{
		cnt=h2[x+y];
		while (cnt)
		{
			if (res[p2[cnt]]==-1) res[p2[cnt]]=s+abs(x2[cnt]-x);
			cnt=lhy2[cnt];
		}
	}
	if (u==1) cnt1=n-x; else cnt1=x;
	if (v==1) cnt2=m-y; else cnt2=y;
	step=min(cnt1,cnt2);
	x+=u*step;
	y+=v*step;
	if (x==0||x==n) u=-u; else v=-v;
	s+=step;
}

void check()
{
	if ((x==0||x==n)&&(y==0||y==m)) f=false;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	snk1=snk2=0;
	if (n<m) e=m; else e=n;
	memset(lhy1,0,sizeof(lhy1));
	memset(lhy2,0,sizeof(lhy2));
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for (int i=1;i<k+1;i++)
	{
		scanf("%d%d",&x,&y);
		put_in1(y-x+e,x,i);
		put_in2(x+y,x,i);
		res[i]=-1;
	}
	x=0;y=0;u=1;v=1;
	s=0;f=true;
	while (f){
		go();
		check();
	}
	for (int i=1;i<=k;i++)
	    printf("%I64d\n",res[i]);
	return 0;
}

