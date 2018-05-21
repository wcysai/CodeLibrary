#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int main()
{
	cin>>str;
	int n=str.size();
	int t=26;
	for(int i=0;i<n-1;i++)
		if(str[i]==str[i+1]) t=min(t,str[i]-'a');
	if(t<26)
	{
		printf("%c%c\n",'a'+t,'a'+t);
		return 0;
	}
	bool f=false;
	string x="zzz";
	for(int i=0;i<n-2;i++)
		if(str[i]==str[i+2]) 
		{
			if(str.substr(i,3)<x)
			{
				x=str.substr(i,3);
				f=true;
			}
		}
	if(!f) puts("-1"); else cout<<x<<endl;
	return 0;
}