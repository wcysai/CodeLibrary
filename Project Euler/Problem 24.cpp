#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int perm[10];
int main()
{
	for(int i=0;i<10;i++)
		perm[i]=i;
	int cnt=1;
	while(next_permutation(perm,perm+10))
	{
		cnt++;
		if(cnt==1000000) break;
	}
	for(int i=0;i<10;i++)
		printf("%d ",perm[i]);
	printf("\n");
	return 0;
}