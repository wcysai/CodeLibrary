#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int bas[20];
int ori[20];
void ins(int x)
{
	int tmp=x;
    for(int j=n-1;j>=0;j--)
    {
        if(x&(1<<j))
        {
            if(!bas[j])
            {
            	 ori[j]=tmp;
                 bas[j]=x;
                 break;
            }
            x^=bas[j];
        }
    }
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k%2==0||(k>=2&&n==k))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)==k) ins(i);
	for(int i=0;i<(1<<n);i++)
	{
		int x=i^(i>>1);
		int res=0;
		for(int j=0;j<n;j++) if(x&(1<<j)) res^=ori[j];
		printf("%d%c",res,(i==(1<<n)-1)?'\n':' ');
	}
	return 0;
}