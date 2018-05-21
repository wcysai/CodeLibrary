#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int pattern[10][3]=
{
	5,4,0,
	5,3,0,
	5,2,0,
	5,1,0,
	4,3,0,
	4,2,0,
	4,1,0,
	3,2,0,
	3,1,0,
	2,1,0
};
int num[10]={1110,10110,11010,11100,100110,101010,101100,110010,110100,111000};
int minnum[10]={0,0,0,0,1,1,1,1,1,1};
int pownum[6]={1,10,100,1000,10000,100000};
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
	int p=sieve(1000000);
	int ans=10000000;
	for(int i=0;i<9;i++)
	{
		int mina=pattern[i][0]==5?1:0;
		for(int a=mina;a<10;a++)
			for(int b=0;b<10;b++)
				for(int c=0;c<10;c++)
				{
					int base=a*pownum[pattern[i][0]]+b*pownum[pattern[i][1]]+c*pownum[pattern[i][2]];
					//printf("%d\n",base);
					int cnt=0;
					for(int j=minnum[i];j<10;j++)
						if(is_prime[base+j*num[i]]) cnt++;
					//printf("%d\n",cnt);
					if(cnt==8) ans=min(ans,base+minnum[i]*num[i]);
				}
	}
	printf("%d\n",ans);
	return 0;
}



