#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 200000
using namespace std;
int n,k,A[MAXN];
int r[MAXN+1],tmp[MAXN+1];
int rev[MAXN*2],sa[MAXN*2];
string S;
bool compare_sa(int i,int j)
{
    if(r[i]!=r[j]) return r[i]<r[j];
    else
    {
        int ri=i+k<=n?r[i+k]:-1;
        int rj=j+k<=n?r[j+k]:-1;
        return ri<rj;
    }
}
void construct_sa(int S[],int len,int *sa)
{
    for(int i=0;i<=len;i++)
    {
        sa[i]=i;
        r[i]=i<n?S[i]:-1;
    }
    for(k=1;k<=len;k*=2)
    {
        sort(sa,sa+len+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=len;i++)
        {
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=len;i++)
        {
            r[i]=tmp[i];
        }
    }
}
void solve()
{
	reverse_copy(A,A+n,rev);
	construct_sa(rev,n,sa);
	int p1;
	for(int i=0;i<n;i++)
	{
		p1=n-sa[i];
		if(p1>=1&&n-p1>=2) break;
	}
	int m=n-p1;
	reverse_copy(A+p1,A+n,rev);
	reverse_copy(A+p1,A+n,rev+m);
	construct_sa(rev,m*2,sa);
	int p2;
	for(int i=0;i<=2*m;i++)
	{
		p2=p1+m-sa[i];
		if(p2-p1>=1&&n-p2>=1) break;
	}
	reverse(A,A+p1);
	reverse(A+p1,A+p2);
	reverse(A+p2,A+n);
	for(int i=0;i<n;i++) printf("%d\n",A[i]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	solve();
	return 0;
}