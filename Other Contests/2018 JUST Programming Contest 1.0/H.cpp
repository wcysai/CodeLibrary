#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0;
		scanf("%d%d",&n,&m);
		cin>>str;
		int dif=0;
		for(int i=0;i<n/2;i++)
			if(str[i]!=str[n-1-i]) dif++;
		int x;
		string S;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&x);
			x--;
			cin>>S;
			bool f1,f2;
			if(str[x]==str[n-1-x]) f1=true; else f1=false;
			str[x]=S[0];
			if(str[x]==str[n-1-x]) f2=true; else f2=false;
			if(f1&&!f2) dif++;
			if(!f1&&f2) dif--;
			if(dif==0) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}