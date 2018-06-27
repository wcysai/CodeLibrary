#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	if(str[n-1]=='0') puts("0"); else puts("1");
	return 0;
}