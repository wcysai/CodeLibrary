#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define BASE 19260817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int n;
int ids[MAXN],idt[MAXN];
int hashs[MAXN],hasht[MAXN];
int p[MAXN],invp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    p[0]=invp[0]=1;
    int inv=pow_mod(BASE,MOD-2);
    for(int i=1;i<=1000000;i++) p[i]=1LL*p[i-1]*BASE%MOD;
    for(int i=1;i<=1000000;i++) invp[i]=1LL*invp[i-1]*inv%MOD;
    while(cin>>s)
    {
        n=(int)s.size();
        cin>>t;
        int i=0,j=1,k,m=1;
        while(m<=n)
        {
            while(i<m&&j<m) 
            {
                for(k=0;k<m&&s[i+k]==s[j+k];k++);
                if(k==m) break;
                if(s[i+k]>s[j+k]) 
                {
                    i+=k+1; if(i==j) i++;
                }
                else 
                {
                    j+=k+1; if(i==j) j++;
                }
            }
            ids[m]=min(i,j);
            m++;
        }
        i=0;j=1;m=1;
        while(m<=n)
        {
            while(i<m&&j<m) 
            {
                for(k=0;k<m&&t[i+k]==t[j+k];k++);
                if(k==m) break;
                if(t[i+k]>t[j+k]) 
                {
                    i+=k+1; if(i==j) i++;
                }
                else 
                {
                    j+=k+1; if(i==j) j++;
                }
            }
            idt[m]=min(i,j);
            m++;
        }
        for(int i=1;i<=n;i++) printf("%d %d\n",ids[i],idt[i]);
        hashs[0]=hasht[0]=0;
        for(int i=0;i<n;i++) hashs[i+1]=(1LL*BASE*hashs[i]+s[i])%MOD;
        for(int i=0;i<n;i++) hasht[i+1]=(1LL*BASE*hasht[i]+t[i])%MOD;
        for(int i=0;i<n;i++)
        {
            int x,y;
            int len=(i+1)-ids[i+1];
            x=hashs[i+1];
            dec(x,1LL*hashs[i+1-len]*p[len]%MOD);
            x=1LL*x*p[ids[i+1]]%MOD;
            add(x,hashs[i+1-len]);
            y=hasht[i+1];
            len=(i+1)-idt[i+1];
            dec(y,1LL*hasht[i+1-len]*p[len]%MOD);
            y=1LL*y*p[idt[i+1]]%MOD;
            add(y,hasht[i+1-len]);
            if(x==y) printf("1"); else printf("0");
        }
        puts("");
    }
    return 0;
}