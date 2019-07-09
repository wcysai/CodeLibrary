#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<bool> vec;
typedef vector<vec> mat;
typedef bitset<4000> bs;
int n;
char str[1005];
bs A[MAXN],B[MAXN],C[MAXN],D[MAXN],E[MAXN];
void read(bs &A)
{
    scanf("%s",str);
    int t=(n+3)/4;
    for(int j=0;j<t;j++)
    {
        int val=(str[j]>='0'&&str[j]<='9'?str[j]-'0':str[j]-'A'+10);
        int now=8;
        for(int k=0;k<4;k++)
        {
            if(j*4+k<n&&((val/now)&1)) A.set(j*4+k);
            now>>=1;
        }
    }
}
void mul(bs A[MAXN], bs &B,bs &C)
{
    for(int i=0;i<n;i++) if(B.test(i)) C^=A[i];
}
mt19937 wcy(time(NULL));
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) read(A[i]); 
    for(int i=0;i<n;i++) read(B[i]); 
    for(int i=0;i<n;i++) read(C[i]);
    bool flag=true;
    for(int trial=0;trial<5;trial++)
    {
        bs tmp1,tmp2,tmp3;
        tmp1.reset(); tmp2.reset(); tmp3.reset();
        for(int j=0;j<n;j++) 
            if(wcy()&1)
            {
                tmp1.set(j);
                tmp2.set(j);
            }
        mul(A,tmp1,tmp3);
        tmp1=tmp3; tmp3.reset();
        mul(B,tmp1,tmp3);
        tmp1.reset();
        mul(C,tmp2,tmp1);
        if((tmp1^tmp3).count())
        {
            flag=false;
            break;
        }
    }
    if(flag) puts("YES"); else puts("NO");
    return 0;
}
