#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef pair<double,double> P;
bool inside(int a,int b)
{
	return (a>x1&&a<x2&&b>y1&&b<y2);
}
bool cal(int i)
{
	if(vx[i]==0)
	{
		if(vy[i]==0)
		{
			if(inside(rx[i],ry[i])) return P(0,INF);
			else return P(-1,-1);
		}
		else
		{
			if(rx[i]<=x1||rx[i]>=x2) return P(-1,-1);
			double t1=(y1-ry[i])/vy[i],t2=(y2-ry[i])/vy[i];
			if(t1<=0&&t2<=0) return P(-1,-1);
			if(t1>0&&t2>0) return P(min(t1,t2),max(t1,t2));
			return P(0,max(t1,t2));
		}
	}
	else
	{
		double t1=(x1-rx[i])/vx[i],t2=(x2-rx[i])/vx[i];
		if(t1<=0&&t2<=0) return P(-1,-1);
		else if(t1>0&&t2>0)
		{
			
		}
		if(t1>0||t2>0)
		{
			if(!inside(rx[i],ry[i])) return P(-1,-1);
			else
			{
				if(t1<0) swap(t1,t2);
				if(vy[i]==0) return P(0,t1);
				else
				{
					double t3=(y1-ry[i])/vy[i],t4=(y2-ry[i])/vy[i];
					if(t3<0) swap(t3,t4);;
					return P(0,min(t1,t3));
				}
			} 
			else
			{
				if(vy[i])
			}
		}
	}
}
int n;
double x1,x2,y1,y2;
double rx[MAXN],ry[MAXN],vx[MAXN],vy[MAXN];
int main()
{
	return 0;
}