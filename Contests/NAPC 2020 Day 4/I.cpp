#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int t,n;
bool les(string &x,string &y)
{
    if((int)x.size()<(int)y.size()) return true;
    if((int)x.size()>(int)y.size()) return false;
    for(int i=0;i<(int)x.size();i++)
    {
        if(x[i]>y[i]) return false;
        if(x[i]<y[i]) return true;
    }
    return true;
}
string glue(string &x,int odd)
{
    string tmp=x;
    if(odd) tmp.pop_back();
    reverse(tmp.begin(),tmp.end());
    return x+tmp;
}
string largest_palindrome(string &str)
{
    int n=(int)str.size();
    bool f=true;
    if(str[0]!='1') f=false;
    for(int i=1;i<n;i++) if(str[i]!='0') f=false;
    if(f)
    {
        if(n==1) return "1";
        string ret="";
        for(int i=0;i<n-1;i++) ret+='9';
        return ret;
    }
    string pre=str.substr(0,(n+1)/2);
    string tmp=glue(pre,n&1);
    if(les(tmp,str)) return tmp;
    else
    {
        for(int i=(int)pre.size()-1;i>=0;i--)
        {
            if(pre[i]>'0') {pre[i]--; break;}
            else {pre[i]='9';}
        }
        string tmp=glue(pre,n&1);
        assert(les(tmp,str)); return tmp;
    }
}
void dec(string &x,string &y)
{
    int num=(int)x.size()-(int)y.size();
    string z="";
    for(int i=0;i<num;i++) z+='0';
    z+=y;
    for(int i=(int)x.size()-1;i>=0;i--)
    {
        int d=x[i]-z[i];
        if(d<0)
        {
            x[i-1]--;
            d+=10;
        }
        x[i]='0'+d;
    }
    int cnt=0;
    for(int i=0;i<(int)x.size();i++) if(x[i]=='0') cnt++; else break;
    x=x.substr(cnt,(int)x.size()-cnt); 
}
vector<string> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        cin>>str;
        while(str.size()>=1)
        {
            string pal=largest_palindrome(str);
            ans.push_back(pal);
            dec(str,pal);
        }
        printf("%d\n",(int)ans.size());
        for(auto x:ans) cout<<x<<endl;
    }
    return 0;
}