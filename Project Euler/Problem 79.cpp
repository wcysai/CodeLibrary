#include<bits/stdc++.h>
using namespace std;
string str;
bool pre[10][10],suf[10][10];
int main()
{
	freopen("p079_keylog.txt","r",stdin);
	memset(pre,false,sizeof(pre));
	memset(suf,false,sizeof(suf));
	while(cin>>str)
	{
		cout<<str<<endl;
		suf[str[0]-'0'][str[1]-'0']=true;
		suf[str[0]-'0'][str[2]-'0']=true;
		suf[str[1]-'0'][str[2]-'0']=true;
		pre[str[2]-'0'][str[0]-'0']=true;
		pre[str[2]-'0'][str[1]-'0']=true;
		pre[str[1]-'0'][str[0]-'0']=true;
	}
	for(int i=0;i<10;i++)
	{
		printf("numbers before %d:",i);
		for(int j=0;j<10;j++)
			if(pre[i][j]) printf("%d ",j);
		puts("");
		printf("numbers after %d:",i);
		for(int j=0;j<10;j++)
			if(suf[i][j]) printf("%d ",j);
		puts("");
	}
	fclose(stdin);
}