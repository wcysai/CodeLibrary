#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int text[MAXN],res[MAXN];
int main()
{
	freopen("p059_cipher.txt", "r", stdin);
	int cnt=0,x;
	while(scanf("%d",&x)!=EOF)
		text[cnt++]=x;
	printf("%d\n",cnt);
	int ans=0;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			for(int k=0;k<26;k++)
			{
				memset(res,0,sizeof(res));
				bool the=false,ad=false,to=false;
				for(int num=0;num<cnt;num++)
				{
					int pswd;
					if(num%3==0) pswd='a'+i;
					else if(num%3==1) pswd='a'+j;
					else pswd='a'+k;
					res[num]=text[num]^pswd;
					the=the||(num>=2&&res[num-2]=='t'&&res[num-1]=='h'&&res[num]=='e');
					ad=ad||(num>=2&&res[num-2]=='a'&&res[num-1]=='n'&&res[num]=='d');
					to=to||(num>=1&&res[num-1]=='t'&&res[num]=='o');
				} 
				if(!the||!ad||!to) continue;
				printf("%c%c%c\n",'a'+i,'a'+j,'a'+k);
				for(int num=0;num<cnt;num++)
				{
					if('a'+i=='g'&&'a'+j=='o'&&'a'+k=='d') ans+=res[num];
					printf("%c",res[num]);
				}
				puts("");
			}
	printf("%d\n",ans);
	fclose(stdin);
	return 0;
}