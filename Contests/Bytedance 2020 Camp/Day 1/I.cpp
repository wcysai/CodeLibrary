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
char oper[5]={'+','-','*','/'};
int x,y,z,op;
map<char,int> mp;
bool add(int &x,int y)
{
    if(x==-1&&y==0) return false;
    if(x==-1) x=0;
    if(10LL*x+y>INF) return false;
    x=x*10+y;
    return true;
}
bool check(int x,int y,int z,int op)
{
    if(op==0) return (x+y==z);
    else if(op==1) return (x-y==z);
    else if(op==2) return (1LL*x*y==z);
    else return (1LL*y*z==x);
}
bool parse(string &str)
{
    x=y=z=-1;
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
    if(!f1||!f2||x==-1||y==-1||z==-1) return false;
    return true;
}
int need(ll x,ll y)
{
    if(x<=0||x>INF||y<=0||y>INF) return 10;
    int cnt=0;
    while(x||y)
    {
        if(!x||!y) return 10;
        if(x%10!=y%10) cnt++;
        x/=10; y/=10;
    }
    return cnt;
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
    if(x<=0||x>INF||y<=0||y>INF||z<=0||z>INF) return false;
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
string symbol="+-*/=0123456789";
int main()
{
    mp['+']=0; mp['-']=1; mp['*']=2; mp['/']=3;
    cin>>str;
    if(!parse(str)) {puts("Format Error"); return 0;}
    if(check(x,y,z,op)) {puts("Correct"); return 0;}
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
        {
            for(int k=0;k<(int)str.size();k++)
            {
                for(int l=0;l<k;l++)
                {
                    string t=str;
                    t[k]=symbol[i];
                    t[l]=symbol[j];
                    if(parse(t))
                    {
                        if(check(x,y,z,op))
                        {
                            construct(x,y,z,op);
                            cout<<"Typo: "<<str<<" instead of "<<ans<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    puts("Math Error");
    return 0;
}