#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
vector<P> v[MAXN];
int x[MAXN],y[MAXN];
map<int,int> id;
string str;
int get_id(int y)
{
	if(id.find(y)==id.end()) id[y]=++tot;
	return id[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	cin>>str;
	for(int i=0;i<n;i++)
	{
		y[i]=get_id(y[i]);
		v[y[i]].push_back(P(x[i],str[i]=='L'?0:1));
	}
	bool f=true;
	for(int i=1;i<=tot;i++)
	{
		sort(v[i].begin(),v[i].end());
		for(int j=1;j<(int)v[i].size();j++) if(v[i][j].S==0&&v[i][j-1].S==1) f=false;
	}
	if(!f) puts("Yes"); else puts("No");
	return 0;
}