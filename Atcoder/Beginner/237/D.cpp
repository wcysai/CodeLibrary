#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
deque<int> v;
int n;
int pos[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	v.push_back(n);
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='L') v.push_back(i); else v.push_front(i);
	}
	for(auto x:v) printf("%d ",x);
	puts("");
	return 0;
}