#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
string mul2(string x)
{
	int flag=0;
	for(int i=9999;i>=0;i--)
	{
		int num=(x[i]-48)*2+flag;
		flag=num/10;
		x[i]=num%10+48;
	}
	return x;
}
int main()
{
	string S(10000,'0');
	S[9999]='1';
	for(int i=0;i<1000;i++)
		S=mul2(S);
	int s=0;
	for(int i=0;i<10000;i++)
		s=s+S[i]-48;
	printf("%d\n",s);
	return 0;
}