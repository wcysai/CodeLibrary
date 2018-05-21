#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
bool valid[28124];
int find_sum(int x)
{
	int s=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i*i==x) s+=i;
			else s+=i+x/i;
		}
	}
	return s-x;
}
vector<int> abd;
int main()
{
	for(int i=1;i<=28123;i++)
		if(find_sum(i)>i) abd.push_back(i);
	memset(valid,true,sizeof(valid));
	for(int i=0;i<abd.size();i++)
	{
		for(int j=i;j<abd.size();j++)
		{
			if(abd[i]+abd[j]>28123) break;
			valid[abd[i]+abd[j]]=false;
		}
	}
	int sum=0;
	for(int i=1;i<=28123;i++)
		if(valid[i]) sum+=i;
	printf("%d\n",sum);
	return 0;
}