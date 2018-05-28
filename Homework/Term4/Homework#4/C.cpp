#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<assert.h>
#include<queue>
#include<stack>
#define MAXN 5
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string S;
int check[10][4]=
{
	0,1,2,3,
	4,5,6,7,
	8,9,10,11,
	12,13,14,15,
	0,4,8,12,
	1,5,9,13,
	2,6,10,14,
	3,7,11,15,
	0,5,10,15,
	3,6,9,12
};
int check2[16][4]=
{
	0,4,8,-1,
	0,5,-1,-1,
	0,6,-1,-1,
	0,7,9,-1,
	1,4,-1,-1,
	1,5,8,-1,
	1,6,9,-1,
	1,7,-1,-1,
	2,4,-1,-1,
	2,5,9,-1,
	2,6,8,-1,
	2,7,-1,-1,
	3,4,9,-1,
	3,5,-1,-1,
	3,6,-1,-1,
	3,7,8,-1
};
int cnt[10][3],ans;
int A[16];
int C(int move,int last)
{
	for(int i=0;i<4;i++)
	{
		int x=check2[last][i];
		if(x==-1) break;
		if(A[check[x][0]]==1&&A[check[x][1]]==1&&A[check[x][2]]==1&&A[check[x][3]]==1) return move;
		if(A[check[x][0]]==0&&A[check[x][1]]==0&&A[check[x][2]]==0&&A[check[x][3]]==0) return 1-move;
	}
	return -1;
}
int dfs(int move,int dep,int last)
{
	int x=-1;
	if(last!=-1) x=C(move,last);
	//printf("x=%d\n",x);
	if(x!=-1) return x;
	bool f=false;
	for(int i=0;i<16;i++)
	{
		if(A[i]==-1)
		{
			f=true;
			A[i]=move;
			int res=dfs(1-move,dep+1,i);
			A[i]=-1;
			if(res==0) 
			{
				if(dep==0) ans=min(ans,i);
				return 1;
			}
		}
	}
	if(!f) return 1-move;
	return 0;
}
int main()
{
	while(getchar()=='?')
	{
		S="";
		string str;
		for(int i=0;i<4;i++) {cin>>str; S+=str; getchar();}
		memset(A,-1,sizeof(A));
		for(int i=0;i<16;i++)
			if(S[i]=='x') A[i]=1; else if(S[i]=='o') A[i]=0;
		/*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				printf("%3d",A[i*4+j]);
			puts("");
		}
		printf("%d\n",dfs(1));*/
		ans=15;
		if(dfs(1,0,-1)!=1) puts("#####"); else printf("(%d,%d)\n",ans/4,ans%4); 
		/*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				printf("%3d",A[i*4+j]);
			puts("");
		}*/
	}
	return 0;
}