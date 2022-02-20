#include<bits/stdc++.h>
#define MAXN 200005
#define MAXQ 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<int> dis;
vector<P> pos[MAXN];
vector<int> ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) 
	{
		scanf("%d",&a[i]);
		dis.push_back(a[i]);
	}
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	for(int i=1;i<=2*n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
	for(int i=n;i>=1;i--)
		pos[a[i]].push_back(P(i,a[i+n]));
	int sz=(int)dis.size(),cur=1;
	for(int i=1;i<=sz;i++)
	{
		while(pos[i].size()&&pos[i].back().F<cur) pos[i].pop_back();
		if(pos[i].size())
		{
			P tmp=P(INF,0);
			for(auto p:pos[i])
				tmp=min(tmp,P(p.S,p.F));
			if(!ans.size()&&tmp.F<=i)
			{
				ans.push_back(tmp.S);
				cur=tmp.S+1;
				continue;
			}
			if(ans.size())
			{
				bool f=true;
				for(int j=0;j<ans.size();j++) 
				{
					if(a[ans[j]+n]<i) break;
					if(a[ans[j]+n]>i) {f=false; break;}
				}
				if(f) break;
			}
			for(int j=(int)pos[i].size()-1;j>=0;j--) ans.push_back(pos[i][j].F);
			cur=pos[i][0].F+1;
		}
	}
	for(auto x:ans) printf("%d ",dis[a[x]-1]);
	for(auto x:ans) printf("%d ",dis[a[x+n]-1]);
	puts("");
	return 0;
}