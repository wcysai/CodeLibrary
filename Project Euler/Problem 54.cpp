#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
P a[2][5];
string str;
P value[2];
int cc(char ch)
{
	if(ch=='A') return 14;
	if(ch=='T') return 10;
	if(ch=='J') return 11;
	if(ch=='Q') return 12;
	if(ch=='K') return 13;
	return ch-'0';
}
int change(char ch)
{
	if(ch=='H') return 1;
	if(ch=='S') return 2;
	if(ch=='D') return 3;
	if(ch=='C') return 4;
	return -1;
}
int max_value(int type)
{
	return a[type][4].F;
}
bool is_straight(int type)
{
	if(a[type][0].F==2&&a[type][1].F==3&&a[type][2].F==4&&a[type][3].F==5&&a[type][4].F==14) return true;
	if(a[type][1].F==a[type][0].F+1&&a[type][2].F==a[type][1].F+1&&a[type][3].F==a[type][2].F+1&&a[type][4].F==a[type][3].F+1) return true;
	return false;
}
bool is_flush(int type)
{
	if(a[type][0].S==a[type][1].S&&a[type][0].S==a[type][2].S&&a[type][0].S==a[type][3].S&&a[type][0].S==a[type][4].S) return true;
	return false;
}
int four_of_a_kind(int type)
{
	if(a[type][0].F==a[type][1].F&&a[type][0].F==a[type][2].F&&a[type][0].F==a[type][3].F) return a[type][0].F;
	if(a[type][1].F==a[type][2].F&&a[type][1].F==a[type][3].F&&a[type][1].F==a[type][4].F) return a[type][1].F;
	return -1;
}
int full_house(int type)
{
	if(a[type][0].F==a[type][1].F&&a[type][0].F==a[type][2].F&&a[type][3].F==a[type][4].F) return a[type][0].F*15+a[type][3].F;
	if(a[type][0].F==a[type][1].F&&a[type][2].F==a[type][3].F&&a[type][2].F==a[type][4].F) return a[type][2].F*15+a[type][0].F;
	return -1;
}
int three_of_a_kind(int type)
{
	if(a[type][2].F==a[type][3].F&&a[type][3].F==a[type][4].F) return a[type][2].F;
	if(a[type][1].F==a[type][2].F&&a[type][1].F==a[type][3].F) return a[type][1].F;
	if(a[type][0].F==a[type][1].F&&a[type][0].F==a[type][2].F) return a[type][0].F;
	return -1;
}
int two_pairs(int type)
{
	if(a[type][3].F==a[type][4].F&&a[type][1].F==a[type][2].F) return a[type][3].F*15+a[type][1].F;
	if(a[type][3].F==a[type][4].F&&a[type][0].F==a[type][1].F) return a[type][3].F*15+a[type][0].F;
	if(a[type][2].F==a[type][3].F&&a[type][0].F==a[type][1].F) return a[type][2].F*15+a[type][0].F;
	return -1;
}
int one_pair(int type)
{
	if(a[type][3].F==a[type][4].F) return a[type][3].F;
	if(a[type][2].F==a[type][3].F) return a[type][2].F;
	if(a[type][1].F==a[type][2].F) return a[type][1].F;
	if(a[type][0].F==a[type][1].F) return a[type][0].F;
	return -1;
}
void compute(int type)
{
	if(is_straight(type))
	{
		int max_num;
		if(a[type][0].F==2&&a[type][4].F==14) max_num=5; else max_num=max_value(type);
		if(is_flush(type))
		{
			if(max_num==14)
			{
				value[type].F=10;
				value[type].S=14;
			}
			else
			{
				value[type].F=9;
				value[type].S=max_num;
			}
		}
		else
		{
			value[type].F=5;
			value[type].S=max_num;
		}
		return;
	}
	if(four_of_a_kind(type)!=-1)
	{
		value[type].F=8;
		value[type].S=four_of_a_kind(type);
		return;
	}
	if(full_house(type)!=-1)
	{
		value[type].F=7;
		value[type].S=full_house(type);
		return;
	}
	if(is_flush(type))
	{
		value[type].F=6;
		value[type].S=max_value(type);
		return;
	}
	if(three_of_a_kind(type)!=-1)
	{
		value[type].F=4;
		value[type].S=three_of_a_kind(type);
		return;
	}
	if(two_pairs(type)!=-1)
	{
		value[type].F=3;
		value[type].S=two_pairs(type);
		return;
	}
	if(one_pair(type)!=-1)
	{
		value[type].F=2;
		value[type].S=one_pair(type);
		return;
	}
	value[type].F=1;
	value[type].S=max_value(type);
	return;
}
bool fist_to_fist()
{
	for(int i=4;i>=0;i--)
	{
		if(a[0][i].F>a[1][i].F) return true;
		if(a[0][i].F<a[1][i].F) return false;
	}
	return false;
}
int main()
{
	freopen("p054_poker.txt","r",stdin);
	int cnt=0;
	while(getline(cin,str))
	{
		cout<<str<<endl;
		bool f=true;
		for(int i=0;i<5;i++)
			{a[0][i].F=cc(str[3*i]);a[0][i].S=change(str[3*i+1]);}
		for(int i=0;i<5;i++)
			{a[1][i].F=cc(str[15+3*i]);a[1][i].S=change(str[16+3*i]);}
		sort(a[0],a[0]+5);sort(a[1],a[1]+5);
		/*for(int i=0;i<5;i++)
			printf("%d %d\n",a[0][i].F,a[0][i].S);
		for(int i=0;i<5;i++)
			printf("%d %d\n",a[1][i].F,a[1][i].S);*/
		compute(0);
		compute(1);
		printf("%d %d %d %d\n",value[0].F,value[0].S,value[1].F,value[1].S);
		if((value[0].F<value[1].F)||(value[0].F==value[1].F&&value[0].S<value[1].S)||(value[0].F==value[1].F&&value[0].S==value[1].S&&!fist_to_fist()))
			f=false;
		if(f) {puts("Player 1 Wins"); cnt++;} else puts("Player 2 Wins");
	}
	printf("%d\n",cnt);
	fclose(stdin);
	return 0;
}