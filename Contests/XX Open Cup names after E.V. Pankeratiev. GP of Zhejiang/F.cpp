#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> node;
typedef vector<node> vec;
typedef vector<vec> mat;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int tmpa[18][(1<<18)],tmpb[18][(1<<18)],tmpc[18][(1<<18)];
node add(node &a,node &b,int m)
{
    node c;
    for(int i=0;i<(1<<m);i++) 
    {
        c[i]=a[i];
        add(c[i],b[i]);
    }
    return c;
}
node mult(node &a,node &b,int m)
{
    for(int i=0;i<(1<<m);i++) 
    {
        tmpa[__builtin_popcount(i)][i]=a[i];
        tmpb[__builtin_popcount(i)][i]=b[i];
    }
    for(int i=0;i<m;i++)
    {
		for(int j=0;j<m;j++)
        {
			for(int k=0;k<(1<<m);k++)
            {
				if((k>>j)&1)
                {
					add(tmpa[i][k],tmpa[i][k^(1<<j)]);
					add(tmpb[i][k],tmpb[i][k^(1<<j)]);
				}
			}
		}
	}
    for(int i=0;i<(1<<m);i++)
    {
		for(int j=0;j<m;j++)
        {
			int res=0;
			for(int k=0;k<=j;k++) add(res,1LL*tmpa[k][i]*tmpb[j-k][i]%MOD;
			tmpc[j][i]=res;
		}
	}
    for(int i=0;i<m;i++)
    {
		for(int j=0;j<m;j++)
        {
			for(int k=0;k<(1<<m);k++)
            {
				if((k>>j)&1)
                {
					dec(tmpc[i][k],tmpc[i][k^(1<<j)]);
				}
			}
		}
	}
    node c;
    for(int i=0;i<(1<<m);i++) c[i]=tmpc[__builtin_popcount(i)][i];
    return c;
}
int n,m,c;
int compute_hafnian(mat &B)
{
    node h;
    h.resize(1<<(n/2));
    int n=(int)B.size();
    assert(n%2==0);
    n/=2;
    
}