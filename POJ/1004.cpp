#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
float x,sum;
int main()
{
	sum=0;
	for(int i=1;i<=12;i++)
	{
	  scanf("%f",&x);
	  sum+=x;
    }
    sum/=12;
    printf("$%.2f\n",sum);
    return 0;
}