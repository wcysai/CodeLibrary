#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,q,a[MAXN],mex[500];
const block=400;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<(n-1)/block+1;i++)
	{
		for(int j=i*block;j<min(n,(i+1)*block);j++)
		{

		}
	}
}