#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,m,l,u;
int b;
int save[(1<<20)];
string str;
int main()
{
	scanf("%d%d%d%d",&n,&m,&l,&u);
	memset(save,0,sizeof(save));
	for(int i=0;i<n;i++)
	{
		cin>>str;
		int cnt=0;
		b=0;
		for(int j=0;j<m;j++)
		{
			b<<=1;
			if(str[j]=='1') {b=b+1; cnt++;}
		}
		if(cnt<5) continue;
		int comb=(1<<5)-1;
		while(comb<1<<m)
		{
			if((comb&b)==comb) save[comb]++;
			int x=comb&-comb,y=comb+x;
			comb=((comb&-y)/x>>1)|y;
		}
	}
	int comb1=(1<<8)-1,ans=0;
	while(comb1<(1<<m))
	{
		int comb=(1<<5)-1,cnt=0;
		while(comb<(1<<m))
		{
			if((comb&comb1)==comb) cnt+=save[comb];
			int x=comb&-comb,y=comb+x;
			comb=((comb&-y)/x>>1)|y;
		}
		int x1=comb1&-comb1,y1=comb1+x1;
		comb1=((comb1&~y1)/x1>>1)|y1;
		printf("%d\n",cnt);
		if(cnt%3==0&&cnt>=l&&cnt<=u) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
/*3 12 3 3
100000001111
111111111111
111111111111*/