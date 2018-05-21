#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int num[21]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,9,6};
int tenth[10]={0,0,6,6,5,5,5,7,6,6};
int main()
{
	int sum=0,s=0;
	for(int i=1;i<=20;i++)
		s+=num[i];
	sum=s;
	for(int i=3;i<=9;i++)
		s+=tenth[i];
	for(int i=2;i<=9;i++)
		for(int j=1;j<=9;j++)
			s+=tenth[i]+num[j];
	sum=s*10+7*900;
	for(int i=1;i<=9;i++)
		sum+=num[i]+3*99;
	sum+=11;
	printf("%d\n",sum);
	return 0;
}