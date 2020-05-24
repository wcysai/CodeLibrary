#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int L=0,Q=850,q=0;
int sigma=62;
char alpha[MAXN];
int ask(string &str)
{
    q++; assert(q<=Q);
    cout<<"? "<<str<<endl;
    int x;
    scanf("%d",&x);
    return x;
}
bool is_subsequence(string &str)
{
    return (ask(str)==(L-(int)str.size()));
}
void answer(string &str)
{
    cout<<"! "<<str<<endl;
    exit(0);
}
string get_str(char ch)
{
    string x=string(128,ch);
    int ret=ask(x);
    L+=128-ret;
    return string(128-ret,ch);
}
vector<string> v;
bool cmp(string x,string y)
{
    return x.size()>y.size();
}
string merge(string &s,string &t)
{
    string ret=s;
    int now=0,i=0;
    while(i<(int)t.size())
    {
        if(now==(int)s.size())
        {
            ret=ret+t.substr(i);
            break;
        }
        int num=now+i;
        string tmp=ret.substr(0,num)+t[i]+ret.substr(num);
        if(is_subsequence(tmp)) {ret=tmp; i++;} else now++;
    }
    return ret;
}
int main()
{
    for(int i=0;i<26;i++) alpha[i]='a'+i;
    for(int i=26;i<52;i++) alpha[i]='A'+i-26;
    for(int i=52;i<62;i++) alpha[i]='0'+i-52;
    for(int i=0;i<62;i++) 
    {
        string str=get_str(alpha[i]);
        if(str.size()) v.push_back(str);
    }
    while(v.size()>1)
    {
        sort(v.begin(),v.end(),cmp);
        string s=v.back(); v.pop_back();
        string t=v.back(); v.pop_back();
        v.push_back(merge(s,t));
    }
    assert(v[0].size()==L);
    answer(v[0]);
    return 0;
}