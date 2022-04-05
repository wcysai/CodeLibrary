#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll x;
vector<int> st;
string str;
int main()
{
	scanf("%d%lld",&n,&x);
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='U') st.push_back(0);
		else if(str[i]=='L') st.push_back(1);
		else st.push_back(2);
		while(st.size()>=2)
		{
			if(st.back()==0&&st[st.size()-2]!=0)
			{
				st.pop_back();
				st.pop_back();
			}
			else break;
		}
	}
	for(auto op:st)
	{
		if(op==0) x/=2;
		else if(op==1) x*=2;
		else x=x*2+1;
	}
	printf("%lld\n",x);
	return 0;
}