#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
char str[MAXN];
int t,n,a,b;
bool f1,f2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		f1=f2=false;
		a=0,b=0;
		scanf("%d",&n);
		getchar();
		fgets(str,sizeof(str),stdin);
		char* p=strtok(str," ");
		while(p!=NULL)
		{
			if(p[0]=='a'&&p[1]=='b') a++;
			else if(p[0]=='b'&&p[1]=='a') b++;
			else if(p[0]=='a') f1=true;
			else if(p[0]=='b') f2=true;
			p=strtok(NULL," ");
		}
		if(a==0&&b==0)
		{
			if(f1&&f2) printf("2\n");
			else if(!f1&&!f2) printf("0\n");
			else printf("1\n");
		}
		else if(a>b) printf("%d\n",2*a); else if(a==b) printf("%d\n",2*a+1); else printf("%d\n",2*b);
	}
	return 0;
}