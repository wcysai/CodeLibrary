#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
string str;
int n;
lll p2[105];

map<pair<lll,int>,int> mp;
lll get(lll x,int num,int l,int r)
{
	x>>=(num-r);
	int len=r-l+1;
	return x&(p2[len]-1);
}
int solve(pair<lll,int> p)
{
	if(p.S==0) return 1;
	if(mp.find(p)!=mp.end()) return mp[p];
	pair<lll,int> q;
	q.S=p.S-1; 
	if(p.F>=p2[p.S-1]) q.F=p.F-p2[p.S-1]; else q.F=p.F;
	int ans=solve(q);
	if(p.F>=p2[p.S-1]) ans=2LL*ans%MOD;
	for(int i=1;i<=p.S/2;i++)
	{
		lll tmp=get(p.F,p.S,1,i);
		for(int j=2;i*j<=p.S;j++) 
		{
			tmp&=(get(p.F,p.S,i*(j-1)+1,i*j));
			add(ans,1LL*solve(make_pair(tmp,i))*solve(make_pair(get(p.F,p.S,i*j+1,p.S),p.S-i*j))%MOD);
		}
	}
	return mp[p]=ans;
}
void print(__int128 x) 
{
    if(x < 0) 
    {
        putchar('-');
        x=-x;
    }
    if(x>9) print(x / 10);
    putchar(x%10+'0');
}
int main()
{
	p2[0]=1;
	for(int i=1;i<=100;i++) p2[i]=2*p2[i-1];
	cin>>str;
	n=(int)str.size();
	lll x=0;
	for(int i=0;i<str.size();i++) x=x*2+(str[i]-'0');
	printf("%d\n",solve(make_pair(x,n)));
	return 0;
}