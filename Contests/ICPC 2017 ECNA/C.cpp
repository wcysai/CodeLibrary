#include<bits/stdc++.h>
#define MAXN 15005
using namespace std;
string str;
int main()
{
	cin>>str;
	int n=str.size();
	int cnt=0;
	for(int i=0;i<n/2;i++)
		cnt+=str[i]-'A';
	for(int i=0;i<n/2;i++)
		str[i]=(str[i]-'A'+cnt)%26+'A';
	cnt=0;
	for(int i=n/2;i<n;i++)
		cnt+=str[i]-'A';
	for(int i=n/2;i<n;i++)
		str[i]=(str[i]-'A'+cnt)%26+'A';
	for(int i=0;i<n/2;i++)
		str[i]=(str[i]-'A'+str[i+n/2]-'A')%26+'A';
	str=str.substr(0,n/2);
	cout<<str<<endl;
	return 0;
}