#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define eps 1e-6
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
int n;
vector<P> nodes;
int main()
{
	scanf("%d",&n);
	nodes.clear();
	for(int i=0;i<n;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==0)
		{
			double x,y,r;
			scanf("%lf%lf%lf",&r,&x,&y);
			nodes.push_back(P(x,y));
		}
		else
		{
			double x1,y1,x2,y2,x3,y3,x4,y4;
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			nodes.push_back(P((x1+x3)/2,(x2+x4)/2));
		}
	}
	if(n==1||n==2)
	{
		puts("Yes");
		return 0;
	}
	sort(nodes.begin(),nodes.end());
	bool f=true;
	for(int i=0;i<n-2;i++)
	{
		if(abs((nodes[i].F-nodes[i+2].F)*(nodes[i+1].S-nodes[i+2].S)-(nodes[i+1].F-nodes[i+2].F)*(nodes[i].S-nodes[i+2].S))>=eps)
		{
			f=false;
			break;
		}
	}
	if(f) puts("Yes"); else puts("No");
	return 0;
}