/*************************************************************************
    > File Name: M.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-30 13:56:21
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
int T,n,m,q;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int j=0;j<(int)B[0].size();j++)
            C[i][j]=INF;
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
    return C;
}
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<(int)B.size();i++)
        for(int j=0;j<(int)B.size();j++)
            B[i][j]=(i==j?0:INF);
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int ans=0,res;
        mat A(n,vec(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j]=INF;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);u--;v--;
            A[u][v]=min(A[u][v],w);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int s,t,k;
            res=INF;
            scanf("%d%d%d",&s,&t,&k);s--;t--;
            mat B=pow(A,k);
            
            for(int i=0;i<n;i++)
            {
                res=min(res,B[s][t]);
                for(int i=0;i<B.size();i++)
                {
                    for(int j=0;j<B[0].size();j++)
                        printf("%d ",B[i][j]);
                    puts("");
                }
                puts("");
                B=mul(A,B);
            }
            printf("%d\n",res);
            ans+=res;
        }
        if(ans>INF) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}

