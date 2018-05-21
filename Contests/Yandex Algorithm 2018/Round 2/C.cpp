#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,ds,cs,da,ca;
int a[MAXN];
bool C(int x)
{
	int t=m;
	priority_queue<int> pque;
	while(pque.size()) pque.pop();
	for(int i=0;i<x;i++)
		pque.push(a[i]);
	int p=pque.top();
	if(p<=(t/ca)*da) return true;
	while(t>0)
	{
		p=pque.top();
		pque.pop();
		p-=ds;
		pque.push(p);
		p=pque.top();
		t-=cs;
		if(t<0) break;
		if(p<=(t/ca)*da) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&ds,&cs,&da,&ca);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) l=mid; else r=mid;
	}
	printf("%d\n",l);
	return 0;
}