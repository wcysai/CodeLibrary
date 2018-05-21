#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,k;
int a[MAXN];
int bit[MAXN+1];
bool used[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
	scanf("%d",&n);
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int st[MAXN],t=0,cnt=0;
	int counter;
	for(int i=0;i<n;i++)
	{
		add(a[i],1);
		st[t++]=a[i];
		cnt++;
		if(cnt-sum(a[i])==n-a[i])
		{
			counter++;
			if(counter!=n) printf("%d ",a[i]); else printf("%d",a[i]);
			t--;
		}
	}
	for(int i=t-1;i>=0;i--)
		if(i!=0) printf("%d ",st[i]); else printf("%d",st[i]);
	return 0;
}