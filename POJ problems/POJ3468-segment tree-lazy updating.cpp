#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_N 100000
#define MAX_Q 100000
using namespace std;
const int DAT_SIZE=(1<<18)-1;
typedef long long ll;
char s[2];
int N,Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q],R[MAX_Q],X[MAX_Q];
ll data[DAT_SIZE],datb[DAT_SIZE];
void add(int a,int b,int x,int k,int l,int r)
{
    if(a<=l&&r<=b) data[k]+=x;
    else if(l<b&&a<r)
    {
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
ll sum(int a,int b,int k,int l,int r)
{
    if(b<=l||r<=a) return 0;
    else if (a<=l&&r<=b)
    {
        return data[k]*(r-l)+datb[k];
    }
    else
    {
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
void solve()
{
    for(int i=0;i<N;i++)
        add(i,i+1,A[i],0,0,N);
    for(int i=0;i<Q;i++)
    {
        if(T[i]=='C') add(L[i]-1,R[i],X[i],0,0,N);
        else printf("%lld\n",sum(L[i]-1,R[i],0,0,N));
    }
}
int main()
 {
 	scanf("%d%d",&N,&Q);
 	for(int i=0;i<N;i++)
 	  scanf("%d",&A[i]);
	for(int i=0;i<Q;i++)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			scanf("%d%d",&L[i],&R[i]);
			T[i]=s[0];
		}
		else
		{
		    scanf("%d%d%d",&L[i],&R[i],&X[i]);
		    T[i]=s[0];
		}
	 }
	 solve();
	 return 0;
 }
