#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main()
{
	int a[8],ans=0;
	memset(a,0,sizeof(a));
	for(int i=0;i<100000000;i++)
	{
		int id=7;
		while(a[id]>=10) {a[id]-=10; a[id-1]++; id--;}
		int S=a[0]+a[1]+a[2]+a[3];
		int x=S-a[4]-a[5]-a[6];
		int z=S-a[0]-a[4]-a[7];
		int y=S-a[3]-a[6]-z;
		int p=S-y-a[1]-a[5];
		if(x<0||x>9||y<0||y>9||z<0||z>9||p<0||p>9) {a[7]++; continue;}
		int k1=S-a[7]-y;
		int k2=S-z-p;
		int k3=S-a[2]-a[6];
		int k4=S-a[0]-a[5];
		assert(!((k4-k2+k3)&1));
		int _a=(k4-k2+k3)/2;
		int _b=k1-_a;
		int _c=k3-_a;
		int _d=k2-_c;
		if(_a>=0&&_a<=9&&_b>=0&&_b<=9&&_c>=0&&_c<=9&&_d>=0&&_d<=9) ans++;
		a[7]++;
	}
	printf("%d\n",ans);
	return 0;
}