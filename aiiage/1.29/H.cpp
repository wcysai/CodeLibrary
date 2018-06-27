#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int t,n;
string str;
vector<P> que;
bool C(int x)
{
	int res=que[0].S*x;
	int now=res;
	for(int i=1;i<que.size();i+=2)
	{
		if(now-que[i].S<0) return false;
		now=now-que[i].S+que[i+1].S;
		if(now>res) {res=res+(now-res)*x; now=res;}
	}
	return true;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		que.clear();
		n=str.size();
		if(str[0]=='P')
		{
			printf("-1\n");
			continue;
		}
		int cnt=0,state=0;
		for(int i=0;i<n;i++)
		{
			if(state==0)
			{
				if(str[i]=='V') cnt++;
				else {que.push_back(P(state,cnt)); state=1-state; cnt=1;}
			}
			else
			{
				if(str[i]=='P') cnt++;
				else {que.push_back(P(state,cnt)); state=1-state; cnt=1;}
			}
		}
		que.push_back(P(state,cnt));
		if(que[que.size()-1].F==1) que.push_back(P(0,0));
		//for(int i=0;i<que.size();i++)
			//printf("%d %d\n",que[i].F,que[i].S);
		int l=0,r=n+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(C(mid)) r=mid; else l=mid;
		}
		printf("%d\n",r);
	}
	return 0;
}