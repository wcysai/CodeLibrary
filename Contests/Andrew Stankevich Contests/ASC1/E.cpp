#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
string str;
vector<int> v;
vector<int> bits;
int n,m,p;
int check(int mask1,int mask2)
{
    for(int i=0;i<m-1;i++)
    {
        int c1=(mask1>>i)&1,c2=(mask1>>(i+1))&1;
        int c3=(mask2>>i)&1,c4=(mask2>>(i+1))&1;
        if(c1==c2&&c2==c3&&c3==c4) return 0;
    }
    return 1;
}
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%p;
    return C;
}   
bool checkzero()
{
    int sz=(int)v.size();
    if(sz==0) return true;
    for(int i=0;i<sz;i++) if(v[i]!=0) return false;
    return true;
}
bool isodd()
{
    return (v[0]&1);
}
void dec()
{
    v[0]--;
    int pos=0;
    while(v[pos]<0)
    {
        v[pos]+=10;
        v[pos+1]--;
        pos++;
    }
    while(v.size()>0&&v.back()==0) v.pop_back();
}
void div2()
{
    int sz=(int)v.size();
    for(int i=0;i<sz;i++)
    {
        if(i!=sz-1&&v[i+1]&1)
        {
            v[i]=(10+v[i])/2;
            v[i+1]--;
        }
        else v[i]=v[i]/2;
    }
    while(v.size()>0&&v.back()==0) v.pop_back();
}
int main()
{
    freopen("nice.in","r",stdin);
    freopen("nice.out","w",stdout);
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++) v.push_back(str[i]-'0');
    reverse(v.begin(),v.end());
    scanf("%d%d",&m,&p);
    mat trans((1<<m),vec((1<<m)));
    for(int mask1=0;mask1<(1<<m);mask1++)
        for(int mask2=0;mask2<(1<<m);mask2++)
            trans[mask1][mask2]=check(mask2,mask1);
    dec();
    if(checkzero())
    {
        printf("%d\n",(1<<m)%p);
        return 0;
    }
    while(!checkzero())
    {
        if(isodd()) {bits.push_back(1); dec(); div2();}
        else
        {
            bits.push_back(0);
            div2();
        }
    }
    mat v((1<<m),vec(1));
    for(int i=0;i<(1<<m);i++) v[i][0]=1;
    int sz=(int)bits.size();
    for(int i=0;i<sz;i++)
    {
        if(bits[i]==1) v=mul(trans,v);
        trans=mul(trans,trans);
    }
    int ans=0;
    for(int i=0;i<(1<<m);i++) {ans+=v[i][0]; if(ans>=p) ans-=p;}
    printf("%d\n",ans);
    return 0;
}
