/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 16:05:36
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define BASE 19260817
#define MOD 1000000009
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%MOD;
    return C;
}
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<(int)A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int n,k,tot=0;
vector<int> perm;
map<int,int> mp;
bool used[500];
int get_hash(vector<int> v)
{
    bool f=true;
    for(int i=1;i<(int)v.size();i++)
        if(max(v[i]-v[i-1],v[i-1]-v[i])>k) {f=false; break;}
    if(!f) return -1;
    vector<int> v1,v2;v1.clear();v2.clear();
    int k1=0,k2=0,cnt=0;
    for(int i=0;i<=(int)v.size();i++)
    {
        if(v[i]>=(int)v.size()+1-k)
        {
            if(i==1) k1=1;
            if(i==(int)v.size()) k2=1;
            v1.push_back(v[i]);
            cnt++;
            if(cnt>1)
            {
                if(v[i-1]>=10-k) v2.push_back(1); else v2.push_back(0);
            }
        }
    }
    if(v1[0]>v1.back()) return -1;
    v2.push_back(k1);v2.push_back(k2);
    int cur=0;
    for(auto it:v1) cur=(1LL*cur*BASE+it)%MOD;
    for(auto it:v2) cur=(1LL*cur*BASE+it)%MOD;
    if(!mp[cur]) mp[cur]=++tot;
    return mp[cur];
}
int main()
{
    scanf("%d%d",&k,&n);
    if(k==1) {if(n==1) puts("1"); else puts("2"); return 0;}
    int states=1;
    for(int i=1;i<=k;i++) states*=i;
    states*=2;
    for(int i=1;i<=9;i++) perm.push_back(i);
    do
    {
        int num=get_hash(perm);
    }while(next_permutation(perm.begin(),perm.end()));
    printf("%d\n",tot);
    return 0;
}

