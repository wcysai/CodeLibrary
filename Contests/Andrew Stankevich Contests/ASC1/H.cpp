#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<102> bs;
int t,m,cnt;
int prime[MAXN],b[MAXN];
bool is_prime[MAXN];
bs bas[MAXN];
vector<int> vec;
void add_basis(bs &a)
{
    for(int i=t-1;i>=0;i--)
    {
        if(a[i])
        {
            if(!(bas[i].count()))
            {
                bas[i]=a;
                cnt++;
                return;
            }
            a^=bas[i];
        }
    }
}
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void mult2()
{
    int sz=(int)vec.size();
    int carry=0;
    for(int i=0;i<sz;i++)
    {
        int result=vec[i]*2+carry;
        carry=result/10; result=result%10;
        vec[i]=result;
        if(i==(sz-1)&&carry) vec.push_back(1);
    }
}
void dec()
{
    vec[0]--;
}
void print()
{
    int sz=(int)vec.size();
    for(int i=sz-1;i>=0;i--) printf("%d",vec[i]);
}
int main()
{
    freopen("rsa.in","r",stdin);
    freopen("rsa.out","w",stdout);
    sieve(1000);
    scanf("%d%d",&t,&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        bs bb; bb.reset();
        for(int j=0;j<t;j++)
        {
            int cnt=0;
            while(x%prime[j]==0) {x/=prime[j]; cnt^=1;}
            if(cnt) bb.set(j);
        }
        add_basis(bb);
    }
    int fr=m-cnt;
    vec.push_back(1);
    for(int i=0;i<fr;i++) mult2();
    dec();
    print();
    return 0;
}
