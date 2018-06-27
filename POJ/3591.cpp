#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<assert.h>
#define MAXN 200000
using namespace std;
int n,k;
int rank[MAXN+1];
int tmp[MAXN+1];
int N,A[MAXN];
int rev[MAXN*2],sa[MAXN*2];
bool compare_sa(int i,int j)
{
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    else
    {
        int ri=i+k<=n?rank[i+k]:-1;
        int rj=j+k<=n?rank[j+k]:-1;
        return ri<rj;
    }
}
void construct_sa(int *S,int n,int *sa)
{
    for(int i=0;i<=n;i++)
    {
        sa[i]=i;
        rank[i]=i<n?S[i]:-1;
    }
    for(k=1;k<=n;k*=2)
    {
        sort(sa,sa+n+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++)
        {
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++)
        {
            rank[i]=tmp[i];
        }
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    reverse_copy(A,A+N,rev);
    construct_sa(rev,N,sa);
    int p1;
    for(int i=0;i<N;i++)
    {
        p1=N-sa[i];
        if(p1>=1&&N-p1>=2) break;
    }
    int m=N-p1;
    reverse_copy(A+p1,A+N,rev);
    reverse_copy(A+p1,A+N,rev+m);
    construct_sa(rev,m*2,sa);
    int p2;
    for(int i=0;i<=2*m;i++)
    {
        p2=p1+m-sa[i];
        if(p2-p1>=1&&N-p2>=1) break;
    }
    reverse(A,A+p1);
    reverse(A+p1,A+p2);
    reverse(A+p2,A+N);
    for(int i=0;i<N;i++) printf("%d\n",A[i]);
    return 0;
}


