#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w;
int perm1[6],perm2[6];
string str[12];
char mp[12][12];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)
		cin>>str[i];
	for(int i=0;i<(h+1)/2;i++)
		perm1[i]=i;
	do
	{
		for(int i=0;i<(w+1)/2;i++)
			perm2[i]=i;
		do
		{
			bool f=true;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					int x,y;
					if(i<(h+1)/2) x=perm1[i]; else x=i;
					if(j<(w+1)/2) y=perm2[j]; else y=j;
					mp[x][y]=str[i][j];
				}
			for(int i=0;i<(h+1)/2;i++)
				for(int j=0;j<(w+1)/2;j++)
					if(mp[h-1-i][w-1-j]!=mp[i][j]) {f=false; break;}
			if(f) {puts("YES"); return 0;}
		}while(next_permutation(perm2,perm2+(w+1)/2));
	}while(next_permutation(perm1,perm1+(h+1)/2));
	for(int i=0;i<(h+1)/2;i++)
		perm1[i]=i;
	do
	{
		for(int i=0;i<(w+1)/2;i++)
			perm2[i]=i;
		do
		{
			bool f=true;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					int x,y;
					if(i>=h/2) x=perm1[i-h/2]+h/2; else x=i;
					if(j>=w/2) y=perm2[j-w/2]+w/2; else y=j;
					mp[x][y]=str[i][j];
				}
			for(int i=0;i<(h+1)/2;i++)
				for(int j=0;j<(w+1)/2;j++)
					if(mp[h-1-i][w-1-j]!=mp[i][j]) {f=false; break;}
			if(f) {puts("YES"); return 0;}
		}while(next_permutation(perm2,perm2+(w+1)/2));
	}while(next_permutation(perm1,perm1+(h+1)/2));
	for(int i=0;i<(h+1)/2;i++)
		perm1[i]=i;
	do
	{
		for(int i=0;i<(w+1)/2;i++)
			perm2[i]=i;
		do
		{
			bool f=true;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					int x,y;
					if(i<(h+1)/2) x=perm1[i]; else x=i;
					if(j>=w/2) y=perm2[j-w/2]+w/2; else y=j;
					mp[x][y]=str[i][j];
				}
			for(int i=0;i<(h+1)/2;i++)
				for(int j=0;j<(w+1)/2;j++)
					if(mp[h-1-i][w-1-j]!=mp[i][j]) {f=false; break;}
			if(f) {puts("YES"); return 0;}
		}while(next_permutation(perm2,perm2+(w+1)/2));
	}while(next_permutation(perm1,perm1+(h+1)/2));
	for(int i=0;i<(h+1)/2;i++)
		perm1[i]=i;
	do
	{
		for(int i=0;i<(w+1)/2;i++)
			perm2[i]=i;
		do
		{
			bool f=true;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					int x,y;
					if(i>=h/2) x=perm1[i-h/2]+h/2; else x=i;
					if(j<(w+1)/2) y=perm2[j]; else y=j;
					mp[x][y]=str[i][j];
				}
			for(int i=0;i<(h+1)/2;i++)
				for(int j=0;j<(w+1)/2;j++)
					if(mp[h-1-i][w-1-j]!=mp[i][j]) {f=false; break;}
			if(f) {puts("YES"); return 0;}
		}while(next_permutation(perm2,perm2+(w+1)/2));
	}while(next_permutation(perm1,perm1+(h+1)/2));
	puts("NO");
	return 0;
}