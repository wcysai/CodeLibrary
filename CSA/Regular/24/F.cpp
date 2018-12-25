/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-25 19:43:35
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 30005
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD; if(a<0) a+=MOD;}
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%MOD;
    return C;
}
string str;
int n,q;
mat pre[MAXN];
mat inv[MAXN];
mat c[10],invc[10];
int main()
{
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++) 
    {
        pre[i].resize(10,vec(10));
        inv[i].resize(10,vec(10));
    }
    for(int i=1;i<=9;i++)
    {
        c[i].resize(10,vec(10));
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                if(j==k) c[i][j][k]=1; else c[i][j][k]=0;
        for(int j=0;j<10;j++) c[i][i][j]=1;
        invc[i].resize(10,vec(10));
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                if(j==k) invc[i][j][k]=1; else invc[i][j][k]=0;
        for(int j=0;j<10;j++) if(i!=j) invc[i][i][j]=-1; 
    }
    pre[1]=c[str[0]-'a'+1];
    for(int i=2;i<=n;i++) pre[i]=mul(c[str[i-1]-'a'+1],pre[i-1]);
    inv[1]=invc[str[0]-'a'+1];
    for(int i=2;i<=n;i++) inv[i]=mul(inv[i-1],invc[str[i-1]-'a'+1]);
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        mat ret;
        if(l==1) ret=pre[r]; else ret=mul(pre[r],inv[l-1]);
        mat v(10,vec(1)); 
        for(int i=0;i<10;i++) v[i][0]=0;
        v[0][0]=1;
        v=mul(ret,v);
        int ans=0;
        for(int i=1;i<10;i++) add(ans,v[i][0]);
        printf("%d\n",ans);
    }
    return 0;
}

