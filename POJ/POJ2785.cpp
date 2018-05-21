#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAX_N 4000
using namespace std;
int n;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N];
int CD[MAX_N*MAX_N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	    CD[i*n+j]=C[i]+D[j];
	sort(CD,CD+n*n);
	long long res=0;
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	  {
	    int cd=-(A[i]+B[j]);
	    res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
      }
    printf("%lld\n",res);
    return 0;
}