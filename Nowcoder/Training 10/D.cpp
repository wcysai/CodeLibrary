#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m;
char str[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<m;i++)
	{
		int l,r;
		char str1[2],str2[2];
		scanf("%d%d%s%s",&l,&r,str1,str2);
		for(int j=l-1;j<=r-1;j++)
			if(str[j]==str1[0]) str[j]=str2[0];
	}
	printf("%s\n",str);
	return 0;
}