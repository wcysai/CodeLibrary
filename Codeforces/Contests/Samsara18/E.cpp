#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str1,str2;
int main()
{
	cin>>str1;
	cin>>str2;
	int n=str1.size();
	int t1=-1,t2=-1;
	for(int i=0;i<n;i++)
	{
		if(str1[i]!=str2[i])
		{
			if(t1==-1) t1=i;
			t2=i;
		}
	}
	if(t1==-1){puts("YES"); return 0;}
	string a=str1.substr(t1,t2-t1+1);
	string b=str2.substr(t1,t2-t1+1);
	reverse(a.begin(),a.end());
	if(a==b) puts("YES"); else puts("NO");
	return 0;
}