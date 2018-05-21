#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX_N 100000
#define MAX_M 5000
using namespace std;
const int ST_SIZE=(1<<18)-1;
int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];
int nums[MAX_N];
vector<int> dat[ST_SIZE];
void init(int k,int l,int r)
{
    if(r-l==1)
    {
        dat[k].push_back(A[l]);
    }
    else
    {
        int lch=k*2+1,rch=k*2+2;
        init(lch,l,(l+r)/2);
        init(rch,(l+r)/2,r);
        dat[k].resize(r-l);
        merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),dat[k].begin());
    }
}
int query(int i,int j,int x,int k,int l,int r)
{
    if(j<=l||r<=i)
    {
        return 0;
    }
    else if(i<=l&&r<=j)
    {
        return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
    }
    else
    {
        int lc=query(i,j,x,k*2+1,l,(l+r)/2);
        int rc=query(i,j,x,k*2+2,(l+r)/2,r);
        return lc+rc;
    }
}
void solve()
{
    for(int i=0;i<N;i++) nums[i]=A[i];
    sort(nums,nums+N);
    init(0,0,N);
    for(int i=0;i<M;i++)
    {
        int l=I[i]-1,r=J[i],k=K[i];
        int lb=-1,ub=N-1;
        while(ub-lb>1)
        {
            int md=(ub+lb)/2;
            int c=query(l,r,nums[md],0,0,N);
            if(c>=k) ub=md;
            else lb=md;
        }
        printf("%d\n",nums[ub]);
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<M;i++)
        scanf("%d%d%d",&I[i],&J[i],&K[i]);
    solve();
    return 0;
}
