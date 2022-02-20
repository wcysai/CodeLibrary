#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool used[MAXN];
string str;
vector<int> pos;
int calc()
{
	int res=0;
	vector<int> tmp=pos;
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<(int)tmp.size();i++) res+=tmp[i]-i;
	for(int i=0;i<(int)pos.size();i++)
		for(int j=i+1;j<(int)pos.size();j++)
			if(pos[i]>pos[j]) res++;
	return res;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		n=(int)str.size();
		int ans=INF;
		int now=0;
		string t="atcoder";
		for(int i=0;i<n;i++) used[i]=false;
		pos.clear();
		for(int i=0;i<7;i++)
		{
			bool f=false;
			for(int j=0;j<n;j++) 
				if(!used[j]&&str[j]>t[i])
				{
					f=true;
					pos.push_back(j);
					break;
				} 
			if(f) {ans=min(ans,calc()); pos.pop_back();}
			f=false;
			for(int j=0;j<n;j++) 
				if(!used[j]&&str[j]==t[i])
				{
					f=true;
					pos.push_back(j);
					used[j]=true;
					break;
				} 
			if(!f) break;
		}
		if(pos.size()==7&&n>7) ans=min(ans,calc());
		if(ans==INF) puts("-1"); else printf("%d\n",ans);
	}
	return 0;
}