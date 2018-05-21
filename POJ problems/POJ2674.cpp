#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX_N 32005
#define INF 10000000
using namespace std;
double l,v;
int n;
int N;
struct bio
{
	char dir[2];
	double pos;
	char name[255];
};
bio man[MAX_N];
int main()
{
	scanf("%d",&n);
	while(n!=0)
	{
	scanf("%lf %lf\n",&l,&v);
	for(int i=0;i<n;i++)
	{
		scanf("%s%lf%s",man[i].dir,&man[i].pos,man[i].name);
		if (man[i].dir[0]=='P') man[i].dir[0]='p';
		if (man[i].dir[0]=='N') man[i].dir[0]='n';
    }
	double max=-INF,x;
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(man[i].dir[0]=='p') x=l-man[i].pos; else x=man[i].pos;
		x/=v;
		if(x>max)
		{
			t=i;
			max=x;
		}
	}
	int y=t;
	if(man[t].dir[0]=='p')
	{
	    int cnt=0,f=1;
		for(int i=n-1;i>t;i--)
		{
		  if (f) 
		  {
		  if(man[i].dir[0]=='n') 
		  {
		      f=0;
		      cnt=1;
		  }
	     }
		  else if(man[i].dir[0]=='n') cnt++;
		}
		y+=cnt;
    }
	else
    {
	    int cnt=0,f=1;
		for(int i=0;i<t;i++)
		{
		  if (f) 
		  {
		  if(man[i].dir[0]=='p') 
		  {
		      f=0;
		      cnt=1;
		  }
     	}
		  else if(man[i].dir[0]=='p') cnt++;
		}
		y-=cnt;
    }
	printf("%13.2lf %s\n",floor(max*100)/100,man[y].name);
	scanf("%d",&n);
    }
	return 0;
}