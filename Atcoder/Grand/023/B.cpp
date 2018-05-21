#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++)
		cin>>str[i];
	for(int i=0;i<n;i++)
	{
		bool f=true;
		for(int j=0;j<n;j++)
			for(int k=0;k<j;k++)
				if(str[j][k]!=str[k][j]) {f=false; break;}
		if(f) ans+=n;
		for(int j=0;j<n;j++)
		{
			char ch=str[j][0];
			for(int k=1;k<n;k++)
				str[j][k-1]=str[j][k];
			str[j][n-1]=ch;
		}
	}
	printf("%d\n",ans);
	return 0;
}