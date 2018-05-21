#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int b[MAXN],c[MAXN];
int main()
{
	scanf("%d",&t);
	int casecnt=0;
	while(t--)
	{
		casecnt++;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("Case #%d: ",casecnt);
		for(int i=0;i<n;i+=2)
			b[i/2]=a[i];
		for(int j=1;j<n;j+=2)
			c[j/2]=a[j];
		sort(b,b+(n+1)/2);
		sort(c,c+n/2);
		for(int i=0;i<n;i+=2)
			a[i]=b[i/2];
		for(int j=1;j<n;j+=2)
			a[j]=c[j/2];
		bool f=true;
		for(int i=1;i<n;i++)
			if(a[i]<a[i-1]) {f=false; printf("%d\n",i-1); break;}
		if(f) puts("OK");
	}
	return 0;
}