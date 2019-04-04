#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],v[MAXN],tot;
string op="+-*/%^";
string str;
map<string,int> mp;
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    p[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int get_id(string str)
{
    int val=0;
    if(str[0]>='0'&&str[0]<='9')
    {
        for(int i=0;i<(int)str.size();i++) val=val*10+(str[i]-'0');
    }
    if(!mp[str])
    {
        ++tot;
        mp[str]=tot;
        p[tot]=tot;
        v[tot]=val;
        return tot;
    }
    return mp[str];
}
int get_val(string str)
{
    return v[find(get_id(str))];
}
int get_pow(int a,int b)   
{
    if(a==0) return 0;
    if(b==0) return 1;
    if(a==1) return 1;
    if(a==-1) return (b&1?-1:1);
    int s=1;
    for(int i=0;i<b;i++) s=s*a;
    return s;
}
int eval(int l,int r)
{
    if(l>r) return 0;
    int cnt=0;
    for(int i=r;i>=l;i--)
    {
        if(str[i]==')') cnt++;
        if(str[i]=='(') cnt--;
        if(cnt==0&&str[i]=='+'&&i>0&&op.find(str[i-1])==string::npos) return eval(l,i-1)+eval(i+1,r);
        if(cnt==0&&str[i]=='-'&&i>0&&op.find(str[i-1])==string::npos) return eval(l,i-1)-eval(i+1,r);
    }
    for(int i=r;i>=l;i--)
    {
        if(str[i]==')') cnt++;
        if(str[i]=='(') cnt--;
        if(cnt==0&&str[i]=='*'&&i>0&&op.find(str[i-1])==string::npos) return eval(l,i-1)*eval(i+1,r);
        if(cnt==0&&str[i]=='/'&&i>0&&op.find(str[i-1])==string::npos) return eval(l,i-1)/eval(i+1,r);
        if(cnt==0&&str[i]=='%'&&i>0&&op.find(str[i-1])==string::npos)
        {
            int lop=eval(l,i-1),rop=eval(i+1,r);
            int sgn=1;
            if(lop<0) sgn=-sgn;
            if(rop<0) sgn=-sgn;
            return sgn*(abs(lop)%abs(rop));
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(str[i]=='(') cnt++;
        if(str[i]==')') cnt--;
        if(cnt==0&&str[i]=='^'&&i>0&&op.find(str[i-1])==string::npos) return get_pow(eval(l,i-1),eval(i+1,r));
    }
    if(str[l]=='+') return eval(l+1,r);
    if(str[l]=='-') return -eval(l+1,r);
    if(str[l]=='('&&str[r]==')') return eval(l+1,r-1);
    return get_val(str.substr(l,r-l+1));
}
int main()
{
    freopen("plcool.in","r",stdin);
    freopen("plcool.out","w",stdout);
    while(getline(cin,str))
    {
        for(int i=0;i<(int)str.size();i++) if(str[i]>='A'&&str[i]<='Z') str[i]-=('A'-'a');
        if(str.substr(0,5)=="print")
        {
            str=str.substr(6);
            n=str.size();
            string ss="";
            for(int i=0;i<n;i++) if(str[i]!=' ') ss+=str[i];
            str=ss;
            n=str.size();
            printf("%d\n",eval(0,n-1));
        }
        else
        {
            str=str.substr(7);
            n=str.size();
            int id=-1;
            for(int i=0;i<n;i++)
            {
                if(str[i]==' ')
                {
                    id=i;
                    break;
                }
            }
            int a=get_id(str.substr(0,id));
            int b=get_id(str.substr(id+1));
            if(find(a)!=a) continue;
            unite(a,b);
        }
    }
    return 0;
}
