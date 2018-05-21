#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int x,y,z,d;
int main()
{
	int i=0;
	do
	{
		i++;
		scanf("%d %d %d %d",&x,&y,&z,&d);
		if ((x==-1)&&(y==-1)&&(z==-1)&&(d==-1)) break;
		int t=x;
		if(t<y)
		  while(t<y) t+=23;
		while((t-y)%28!=0) t+=23;
		if(t<z)
		  while(t<z) t+=644;
		while((t-z)%33!=0) t+=644;
		if(t-d<=0) t+=21252;
                if(t-d>21252) t-=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",i,t-d);
	}
		while ((x!=-1)||(y!=-1)||(z!=-1)||(d!=-1));
	return 0;
}
		