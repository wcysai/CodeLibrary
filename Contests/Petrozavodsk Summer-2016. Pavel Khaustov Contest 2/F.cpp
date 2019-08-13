#include<bits/stdc++.h>
#define MAXN 10
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[6][6]=
{
	1,0,0,1,0,1,
	0,1,1,0,0,1,
	0,1,0,1,1,0,
	1,0,1,0,1,0,
	0,0,1,1,0,0,
	1,1,0,0,0,0,
};
int b[6][6];
int match[6];
void print()
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
			printf("%c",a[i][j]?'B':'A');
		printf("\n");
		fflush(stdout);
	}
}
int row_edit_distance(int x,int y)
{
	int cnt=0;
	for(int i=0;i<6;i++) if(a[x][i]!=b[y][i]) cnt++;
	return cnt;
}
int col_edit_distance(int x,int y)
{
	int cnt=0;
	for(int i=0;i<6;i++) if(a[i][x]!=b[i][y]) cnt++;
	return cnt;
}
bool checkrow()
{
	memset(match,-1,sizeof(match));
	for(int i=0;i<6;i++)
	{
		bool f=false;
		for(int j=0;j<6;j++)
		{
			if(match[j]!=-1) continue;
			if(row_edit_distance(i,j)<=1)
			{
				f=true;
				match[j]=i;
				break;
			}
		}
		if(!f) return false;
	}
	return true;
}
bool checkcol()
{
	memset(match,-1,sizeof(match));
	for(int i=0;i<6;i++)
	{
		bool f=false;
		for(int j=0;j<6;j++)
		{
			if(match[j]!=-1) continue;
			if(col_edit_distance(i,j)<=1)
			{
				f=true;
				match[j]=i;
				break;
			}
		}
		if(!f) return false;
	}
	return true;
}
string str;
int main()
{
	print();
	do
	{
		cin>>str;
		if (str=="Accepted") break;
		for(int i=0;i<6;i++) 
		{
			cin>>str;
			for(int j=0;j<6;j++) b[i][j]=(str[j]=='A'?0:1);
		}
		if(checkrow()&&checkcol())
		{
			puts("0"); fflush(stdout);
			checkrow();
			for(int i=0;i<6;i++) printf("%d%c",match[i]+1,i==5?'\n':' ');
			fflush(stdout);
			checkcol();
			for(int i=0;i<6;i++) printf("%d%c",match[i]+1,i==5?'\n':' ');
			fflush(stdout);
		}
		else if(checkrow())
		{
			puts("1"); fflush(stdout);
			for(int i=0;i<6;i++) printf("%d%c",match[i]+1,i==5?'\n':' ');
			fflush(stdout);
		}
		else
		{
			checkcol();
			puts("2"); fflush(stdout);
			for(int i=0;i<6;i++) printf("%d%c",match[i]+1,i==5?'\n':' ');
			fflush(stdout);
		}
	}while(true);
	return 0;
}
