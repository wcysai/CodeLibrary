#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int main()
{
	for(int i=1;i<=1000;i++)
		for(int j=i+1;i+j<=1000;j++)
		{
			if(i*i+j*j==(1000-i-j)*(1000-i-j))
			{
				printf("%d\n",i*j*(1000-i-j));
				return 0;
			}
		}
	return 0;
}