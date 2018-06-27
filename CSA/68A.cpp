#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k;
string S[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>S[i];
	for(int i=0;i<n;i++)
	{
		bool f=false;
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(j==i||k==i) continue;
				if(S[j]+S[k]==S[i]||S[k]+S[j]==S[i])
				{
					f=true;
					break;
				}
			}
			if(f) break;
		}
		if(f) printf("%d ",i+1);
	}
	return 0;
}