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
#define MOD 1000000007
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
mat _pow(mat A,ll n)
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
mat trans(500,vec(500));
int get_hash(vector<int> v)
{
    bool f=true;
    for(int i=1;i<(int)v.size();i++)
        if(max(v[i]-v[i-1],v[i-1]-v[i])>k) {f=false; break;}
    if(!f) return -1;
    vector<int> v1,v2;v1.clear();v2.clear();
    int k1=0,k2=0,cnt=0;
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]>=(int)v.size()+1-k)
        {
            if(i==0) k1=1;
            if(i==(int)v.size()-1) k2=1;
            v1.push_back(v[i]-(v.size()-k));
            cnt++;
            if(cnt>1)
            {
                if(v[i-1]>=(int)v.size()+1-k) v2.push_back(1); else v2.push_back(0);
            }
        }
    }
    if(v1[0]>v1.back()) {reverse(v1.begin(),v1.end()); reverse(v2.begin(),v2.end()); swap(k1,k2);}
    v2.push_back(k1);v2.push_back(k2);
    int cur=0;
    for(auto it:v1) cur=(1LL*cur*BASE+it)%MOD;
    for(auto it:v2) cur=(1LL*cur*BASE+it)%MOD;
    if(mp.find(cur)==mp.end()) {mp[cur]=tot++;}
    return mp[cur];
}
int main()
{
    scanf("%d%d",&k,&n);
    if(n<=k+1)
    {
        int ans=1;
        for(int i=1;i<=n;i++) ans*=i;
        printf("%d\n",ans);
        return 0;
    }
    if(k==1) {if(n==1) puts("1"); else puts("2"); return 0;} 
    for(int i=1;i<=9;i++) perm.push_back(i);
    memset(used,false,sizeof(used));
    do
    {
        int num=get_hash(perm);
        //printf("%d\n",num);
        if(used[num]||num==-1) continue;
        //for(auto it:perm) printf("%d ",it);
        //printf("%d\n",num);
        used[num]=true;
        for(int i=0;i<10;i++)
        {
            perm.insert(perm.begin()+i,10);
            int num2=get_hash(perm);
            perm.erase(perm.begin()+i);
            if(num2!=-1) trans[num2][num]++;
        }
    }while(next_permutation(perm.begin(),perm.end()));
    trans.resize(tot);
    for(int i=0;i<(int)trans.size();i++) trans[i].resize(tot);
    /*for(int i=0;i<tot;i++)
    {
        for(int j=0;j<tot;j++)
            printf("%d ",trans[i][j]);
        puts("");
    }*/
    mat v(tot,vec(1));
    //rintf("%d\n",tot);
    perm.clear();
    for(int i=1;i<=k+1;i++) perm.push_back(i);
    do
    {
        //printf("%d\n",++cnt);
        int num=get_hash(perm);
        if(num!=-1) v[num][0]++;
    }while(next_permutation(perm.begin(),perm.end()));
    /*printf("\n");
    for(int i=0;i<tot;i++) printf("%d\n",v[i][0]);
    printf("\n");*/
    int id=n-(k+1);
    trans=_pow(trans,id);v=mul(trans,v);
    int ans=0;
    for(int i=0;i<tot;i++) ans=(ans+v[i][0])%MOD;
    printf("%d\n",ans);
    return 0;
}

