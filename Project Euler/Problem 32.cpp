#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int perm[9];
bool used[10000];
int main()
{
	memset(used,false,sizeof(used));
	for(int i=0;i<9;i++)
		perm[i]=i+1;
	int cnt=0;
	do
	{
		int res=perm[8]+perm[7]*10+perm[6]*100+perm[5]*1000;
		int a1=perm[0],b1=perm[4]+perm[3]*10+perm[2]*100+perm[1]*1000;
		int a2=perm[1]+perm[0]*10,b2=perm[4]+perm[3]*10+perm[2]*100;
		int a3=perm[2]+perm[1]*10+perm[0]*100,b3=perm[4]+perm[3]*10;
		int a4=perm[3]+perm[2]*10+perm[1]*100+perm[0]*1000,b4=perm[4];
		if(a1*b1==res||a2*b2==res||a3*b3==res||a4*b4==res) 
		{
			printf("%d\n",res);
			if(!used[res]) cnt+=res;
			used[res]=true;
		}
	}while(next_permutation(perm,perm+9));
	printf("%d\n",cnt);
	return 0;
}