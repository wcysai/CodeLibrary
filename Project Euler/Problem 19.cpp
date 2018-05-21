#include<bits/stdc++.h>
using namespace std;
int whatday(int d,int m,int y)
{
    int ans;
    if(m==1||m==2)
        m+=12,y--;
    if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
        ans=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
    else
        ans=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return ans;
}
int main()
{
	int cnt=0;
	for(int i=1901;i<=2000;i++)
		for(int j=1;j<=12;j++)
			if(whatday(1,j,i)==6) cnt++;
	printf("%d\n",cnt);
    return 0;
}
