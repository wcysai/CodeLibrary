#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#define MAXT 105
#define MAXN 220
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
map<int,int> mp;
int save[MAXT][3];
ll n,t,s,e;
mat mul(mat A,mat B)
{
    int sz=A.size();
    mat C(sz,vec(sz));
    for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            C[i][j]=INF;
    for(int k=0;k<sz;k++)
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
    return C;
}
mat matpow(mat A,ll x)
{
     int sz=A.size();
     mat C(sz,vec(sz));
     for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            C[i][j]=i==j?0:INF;
     while(x)
     {
         if(x&1) C=mul(C,A);
         A=mul(A,A);
         x>>=1;
     }
     return C;
}
int main()
{
     scanf("%d %d %d %d",&n,&t,&s,&e);
     int k=0;
     for(int i=0;i<t;i++)
     {
         scanf("%d %d %d",&save[i][2],&save[i][0],&save[i][1]);
         map<int,int>::iterator it=mp.find(save[i][0]);
         if(it==mp.end()) mp[save[i][0]]=k,k++;
         it=mp.find(save[i][1]);
         if(it==mp.end()) mp[save[i][1]]=k,k++;
     }
     mat D(k,vec(k));
     for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            D[i][j]=INF;
     for(int i=0;i<t;i++)
        D[mp[save[i][0]]][mp[save[i][1]]]=D[mp[save[i][1]]][mp[save[i][0]]]=save[i][2];
     D=matpow(D,n);
     printf("%d\n",D[mp[s]][mp[e]]);
    return 0;
}
