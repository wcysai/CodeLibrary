#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,type,x,c;
deque<P> deq;
int main()
{
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&x,&c);
			deq.push_back(P(x,c));
		}
		else
		{
			scanf("%d",&c);
			ll sum=0;
			while(c)
			{
				P p=deq.front(); deq.pop_front();
				int need=min(c,p.S);
				sum+=1LL*p.F*need; c-=need; p.S-=need;
				if(p.S) deq.push_front(p); 
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}