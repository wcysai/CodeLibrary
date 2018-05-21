#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,y;
struct node
{
	int dis,coins,id;
};
vector<node> res;
bool cmp(node a,node b)
{
	if(a.dis!=b.dis) return a.dis<b.dis;
	if(a.coins!=b.coins) return a.coins>b.coins;
	return a.id<b.id;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		res.clear();
		scanf("%d%d%d",&n,&x,&y);
		int a,b;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>x||b<y) continue;
			res.push_back((node){a,b,i});
		}
		if(!res.size()) {puts("-1"); continue;}
		sort(res.begin(),res.end(),cmp);
		printf("%d\n",res[0].id+1);
	}
	return 0;
}