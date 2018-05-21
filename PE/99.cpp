#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	double ans=0;
	freopen("p099_base_exp.txt", "r", stdin);
	double x,y;
	int num;
	num=0;
	for(int i=1;i<=1000;i++)
	{
		scanf("%lf%lf",&x,&y);
		if(y*log(x)>ans)
		{
			ans=y*log(x);
			num=i;
		}
	}
	printf("%d\n",num);
	fclose(stdin);
	return 0;
}