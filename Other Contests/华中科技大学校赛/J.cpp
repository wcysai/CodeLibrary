#include<bits/stdc++.h>
#define MAXN 1000050
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dis[MAXN],a,b,pre[MAXN];
int cal(int x)
{
	if(x==0) return 0;
	return cal(x>>1)+(x&1);
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=1000020;i++)
	{
		pre[i]=cal(i);
		dis[i]=INF;
	}
	queue<P> que;
	que.push(P(0,a));
	dis[a]=0;
	while(que.size())
	{
		P p=que.front();
		que.pop();
		int x=p.S;
		if(x==b) {printf("%d\n",p.F); return 0;}
		if(x+1<=1000020&&dis[x+1]==INF) {dis[x+1]=p.F+1; que.push(P(p.F+1,x+1));}
		if(x-1>=0&&dis[x-1]==INF) {dis[x-1]=p.F+1; que.push(P(p.F+1,x-1));}
		if(x+pre[x]<=1000020&&dis[x+pre[x]]==INF) {dis[x+pre[x]]=p.F+1; que.push(P(p.F+1,x+pre[x]));}
		if(x-pre[x]>=0&&dis[x-pre[x]]==INF) {dis[x-pre[x]]=p.F+1; que.push(P(p.F+1,x-pre[x]));}
	}
	return 0;
}