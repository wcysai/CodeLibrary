#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
char str[MAXN];
char code[26];
int main()
{
	scanf("%s",str);
	scanf("%s",code);
	n=strlen(str);
	for(int i=0;i<n;i++)
		str[i]=code[str[i]-'a'];
	printf("%s\n",str);
	return 0;
}