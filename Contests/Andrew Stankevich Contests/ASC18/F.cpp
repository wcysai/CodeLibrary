#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
map<string,int> mp;
vector<string> call[MAXN];
string nam[MAXN];
void get_call(int id)
{
    string str;
    char ch;
    while(cin>>ch&&ch!='}')
    {
        if(ch==';') {call[id].push_back(str); str="";}
        else str+=ch;
    }
}
string get_id()
{
    string str;
    char ch;
    while(cin>>ch&&ch!='{') str+=ch;
    return str;
}
void process_function(const string &s)
{
    string id=get_id();
    int ind=mp.size();
    nam[ind]=(s==""?"":s+".")+id;
    mp[nam[ind]]=ind;
    get_call(ind);
}
void process_program(const string &s);
void process_namespace(const string &s)
{
    string id=get_id();
    process_program((s==""?"":s+".")+id);
}
void process_program(const string &s)
{
    string str;
    char ch;
    while(cin>>ch&&ch!='}')
    {
        cin>>str;
        if(str=="amespace") process_namespace(s);
        else process_function(s);
    }
}
int get_callee(int i,const string &s)
{
    string str=nam[i];
    while(true)
    {
        int id=str.find_last_of('.');
        if(id==(int)string::npos) str="";
        else str.erase(id);
        if(str=="")
        {
            if(mp.count(s)) return mp[s];
            return -1;
        }
        if(mp.count(str+"."+s)) return mp[str+"."+s];
    }
}
int main()
{
    freopen("polymorphism.in","r",stdin);
    freopen("polymorphism.out","w",stdout);
    process_program("");
    for(int i=0;i<(int)mp.size();i++)
    {
        cout<<"["<<i+1<<"] "<<nam[i]<<endl;
        for(int j=0;j<(int)call[i].size();j++)
        {
            int id=get_callee(i,call[i][j]);
            cout<<"  (";
            if(id==-1) cout<<"ERROR"; else cout<<id+1;
            cout<<")\n";
        }
    }
    return 0;
}
