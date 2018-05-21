#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
string convert(string s)
{
	int n=s.size();
	string s1(10000-n,'0');
	return s1+s;
}
string add(string a,string b)
{
	string s;
	int flag=0;
	for(int i=9999;i>=0;i--)
	{
		int num=a[i]-'0'+b[i]-'0'+flag;
		if(num>=10)
		{
			b[i]=num+38;
			flag=1;
		}
		else
		{
			b[i]=num+48;
			flag=0;
		}
	}
	return b;
}
void output(string x)
{
	for(int i=0;i<10000;i++)
		if(x[i]!='0') {cout<<x.substr(i)<<endl; return;}
}
int main()
{
	string x,y;
	cin>>x;
	x=convert(x);
	for(int i=0;i<99;i++)
	{
		cin>>y;
		y=convert(y);
		x=add(x,y);
	}
	for(int i=0;i<10000;i++)
	{
		if(x[i]!='0')
		{
			cout<<x.substr(i,10)<<endl;
			return 0;
		}
	}
	return 0;
}