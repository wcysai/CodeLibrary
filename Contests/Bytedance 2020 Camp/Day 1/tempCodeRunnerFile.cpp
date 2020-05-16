#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
string ans;
char oper[4]={'+','-','*','/'};
int x,y,z,op;
map<char,int> mp;
bool add(int &x,int y)
{
    if(x==0&&y==0) return false;
    if(10LL*x+y>INF) return false;
    x=x*10+y;
    return true;
}
bool parse()
{
    x=y=z=0;
    bool f1=false,f2=false;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            if(f1) return false;
            f1=true;
            op=mp[str[i]];
            continue;
        }
        else if(str[i]=='=')
        {
            if(!f1||f2) return false;
            f2=true;
            continue;
        }
        else if(str[i]<'0'||str[i]>'9') return false;
        if(!f1) {if(!add(x,str[i]-'0')) return false;}
        else if(!f2)  {if(!add(y,str[i]-'0')) return false;}
        else  {if(!add(z,str[i]-'0')) return false;}
    }
    if(!f1||!f2) return false;
    return true;
}
int need(ll x,ll y)
{
    if(y<=0||y>INF) return 10;
    int cnt=0;
    if(y==0) return 10;
    while(x||y)
    {
        if(!x||!y) return 10;
        if(x%10!=y%10) cnt++;
        x/=10; y/=10;
    }
    return cnt;
}
bool check(int x,int y,int z,int op)
{
    if(op==0) return (x+y==z);
    else if(op==1) return (x-y==z);
    else if(op==2) return (1LL*x*y==z);
    else return (1LL*y*z==x);
}

void construct(int x,int y,int z,int op)
{
    string str=to_string(x);
    str+=oper[op];
    str+=to_string(y);
    str+='=';
    str+=to_string(z);
    ans=str;
}
bool check_all(int x,int y,int z,int op,int rem)
{
    if(check(x,y,z,op)) 
    {
        construct(x,y,z,op);
        return true;
    }
    if(rem==0) return false;
    if(op==0)
    {
        if(need(x+y,z)<=1) construct(x,y,x+y,op);
        else if((need(x,z-y)<=1)) construct(z-y,y,z,op);
        else if((need(y,z-x)<=1)) construct(x,z-x,z,op);
        else return false;
    }
    else if(op==1)
    {
        if(need(x-y,z)<=1) construct(x,y,x-y,op);
        else if((need(x,z+y)<=1)) construct(z+y,y,z,op);
        else if((need(y,x-z)<=1)) construct(x,x-z,z,op);
        else return false;
    }
    else if(op==2)
    {
        if(need(1LL*x*y,z)<=1) construct(x,y,x*y,op);
        else if(z%y==0&&(need(x,z/y)<=1)) construct(z/y,y,z,op);
        else if((z%x==0&&need(y,z/x)<=1)) construct(x,z/x,z,op);
        else return false;
    }
    else
    {
        if(x%y==0&&need(x/y,z)<=1) construct(x,y,x/y,op);
        else if((need(x,1LL*y*z)<=1)) construct(y*z,y,z,op);
        else if((x%z==0&&need(y,x/z)<=1)) construct(x,x/z,z,op);
        else return false;
    }
    return true;
}
int main()
{
    mp['+']=0; mp['-']=1; mp['*']=2; mp['/']=3;
    cin>>str;
    if(!parse()) {puts("Format Error"); return 0;}
    if(check(op,x,y,z)) {puts("Correct"); return 0;}
    ans="";
    bool flag=false;
    for(int nop=0;nop<4;nop++)
    {
        if(flag) break;
        int need=2;
        need-=(nop!=op);
        for(int i=1;i<=x;i*=10)
        {
            int id=(x/i)%10;
            for(int j=0;j<=9;j++)
            {
                if(10LL*i>x&&j==0) continue;
                int xx=x-id*i+j*i,yy=y,zz=z;
                if(check_all(xx,yy,zz,nop,2-(nop!=op)-(id!=j))) {flag=true; break;}
            }
            if(flag) break;
        }
        for(int i=1;i<=y;i*=10)
        {
            int id=(y/i)%10;
            for(int j=0;j<=9;j++)
            {
                if(10LL*i>y&&j==0) continue;
                int xx=x,yy=y-id*i+j*i,zz=z;
                if(check_all(xx,yy,zz,nop,2-(nop!=op)-(id!=j))) {flag=true; break;}
            }
            if(flag) break;
        }
        for(int i=1;i<=z;i*=10)
        {
            int id=(z/i)%10;
            for(int j=0;j<=9;j++)
            {
                if(10LL*i>z&&j==0) continue;
                int xx=x,yy=y,zz=z-id*i+j*i;
                if(check_all(xx,yy,zz,nop,2-(nop!=op)-(id!=j))) {flag=true; break;}
            }
            if(flag) break;
        }
    }
    if(flag) {cout<<"Typo: "<<str<<" instead of "<<ans<<endl;}
    else puts("Math Error");
    return 0;
}