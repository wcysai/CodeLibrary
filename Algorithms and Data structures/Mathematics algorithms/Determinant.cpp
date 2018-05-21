#include<bits/stdc++.h>
#define MAXN 505
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
int n;
int det_mod(mat A,int M)
{
	int n=A.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]%=M;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			while(A[j][i]!=0)
			{
				int t=A[i][i]/A[j][i];
				for(int k=0;k<n;k++)
				{
					A[i][k]=A[i][k]-A[j][k]*t;
					swap(A[i][k],A[j][k]);
				}
				ans=-ans;
			}
			if(A[i][i]==0) return 0;
		}
		ans=ans*A[i][i];
	}
	return (ans%M+M)%M;
}
int main()
{
	scanf("%d",&n);
	mat A(n,vec(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	printf("%d\n",det_mod(A,3));
	return 0;
}