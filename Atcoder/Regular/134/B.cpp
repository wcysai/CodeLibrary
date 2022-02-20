#include<bits/stdc++.h>
#define MAXN 200005
#define MAXQ 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
vector<int> pos[26];
int n;
int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++) pos[str[i]-'a'].push_back(i);
	int l=0,r=n-1;
	while(l<r)
	{
		int id=str[l]-'a';
		for(int j=0;j<id;j++)
		{
			while(pos[j].size()&&pos[j].back()>r) pos[j].pop_back();
			if(pos[j].size()&&pos[j].back()>l)
			{
				swap(str[l],str[pos[j].back()]);
				r=pos[j].back()-1;
				break;
			}
		}
		l++;
	}
	cout<<str<<endl;
	return 0;
}