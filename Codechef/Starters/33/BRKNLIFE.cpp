#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,M;
string s,t;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		cin>>s>>t;
		int now=0;
		for(int i=0;i<N;i++)
		{
			if(s[i]=='?')
			{
				int num=(t[now]-'a'+1)%5;
				s[i]='a'+num;
			}
			else if(s[i]==t[now]) now++;
			if(now==M) break;
		}
		if(now==M) puts("-1"); else cout<<s<<endl;
	}
	return 0;
}