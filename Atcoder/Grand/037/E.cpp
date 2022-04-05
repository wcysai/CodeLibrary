#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define hash sdakdo
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int MOD[2]={1000000007,998244353};
int base[2]={233,666};
int hash[2][2*MAXN];
int pw[2][2*MAXN];
string s;
void precompute_hash(string &str)
{
	int m=(int)str.size();
	for(int i=0;i<2;i++)
	{
		hash[i][0]=0;
		for(int j=1;j<=m;j++)
			hash[i][j]=(1LL*base[i]*hash[i][j-1]+(str[j-1]-'a'+1))%MOD[i];
	}
}
P find_hash(int l,int r)
{
	int len=r-l+1;
	int x=(hash[0][r+1]-1LL*pw[0][len]*hash[0][l]%MOD[0]+MOD[0])%MOD[0];
	int y=(hash[1][r+1]-1LL*pw[1][len]*hash[1][l]%MOD[1]+MOD[1])%MOD[1];
	return P(x,y);
}
bool is_smaller(string &str,int l1,int l2)
{
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(find_hash(l1,l1+mid-1)==find_hash(l2,l2+mid-1)) l=mid; else r=mid;
	}
	if(l<n&&str[l1+l]<str[l2+l]) return true; else return false;
}
string find_smallest(string &str)
{
	precompute_hash(str);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(is_smaller(str,i,cur)) cur=i;
	}
	return str.substr(cur,n);
}
int main()
{
	for(int i=0;i<2;i++)
	{
		pw[i][0]=1;
		for(int j=1;j<=10000;j++) pw[i][j]=1LL*pw[i][j-1]*base[i]%MOD[i];
	}
	scanf("%d%d",&n,&k);
	cin>>s;
	if(k>=20)
	{
		char ch='z';
		for(int i=0;i<n;i++) ch=min(ch,s[i]);
		for(int i=0;i<n;i++) printf("%c",ch);
		puts("");
		return 0;
	}
	for(int i=0;i<k-1;i++)
	{
		string t=s;
		reverse(t.begin(),t.end());
		t=s+t;
		reverse(t.begin(),t.end());
		string tmp=find_smallest(t);
		reverse(tmp.begin(),tmp.end());
		s=tmp;
	}
	string t=s;
	reverse(t.begin(),t.end());
	t=s+t;
	string tmp=find_smallest(t);
	cout<<tmp<<endl;
	return 0;
}