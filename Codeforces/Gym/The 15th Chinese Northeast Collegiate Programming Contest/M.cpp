#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<string> v[26]; 
map<string,string> mp;
string solve(string &str)
{
    string x="";
    if(str.size()==1) 
    {
        x+=str; x+=str;
        return x;
    }
    else if(str.size()==2) return str;
    else if(str=="ang") return "ah";
    else if(str=="en") return "ef";
    else if(str=="ou") return "oz";
    else return mp[str];
}
int main()
{
    for(int i=0;i<26;i++) 
    {
        string str="";
        str+=(char)(i+'a');
        v[i].push_back(str);
    }   
    v['q'-'a'].push_back("iu"); 
    v['w'-'a'].push_back("ei");
    v['r'-'a'].push_back("uan");
    v['t'-'a'].push_back("ue");
    v['y'-'a'].push_back("un"); 
    v['u'-'a'].push_back("sh");
    v['i'-'a'].push_back("ch"); 
    v['o'-'a'].push_back("uo");
    v['p'-'a'].push_back("ie"); 
    v['s'-'a'].push_back("ong");
    v['s'-'a'].push_back("iong"); 
    v['d'-'a'].push_back("ai");
    v['f'-'a'].push_back("en"); 
    v['g'-'a'].push_back("eng");
    v['h'-'a'].push_back("ang");
    v['j'-'a'].push_back("an");
    v['k'-'a'].push_back("uai"); 
    v['k'-'a'].push_back("ing");
    v['l'-'a'].push_back("uang"); 
    v['l'-'a'].push_back("iang");
    v['z'-'a'].push_back("ou"); 
    v['x'-'a'].push_back("ia");
    v['x'-'a'].push_back("ua");
    v['c'-'a'].push_back("ao"); 
    v['v'-'a'].push_back("zh");
    v['v'-'a'].push_back("ui");
    v['b'-'a'].push_back("in");
    v['n'-'a'].push_back("iao");
    v['m'-'a'].push_back("ian");
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            for(auto x:v[i])
                for(auto y:v[j])
                {
                    string str="";
                    str+=(char)('a'+i);
                    str+=(char)('a'+j);
                    mp[x+y]=str;
                }
        }
    string str;
    while(getline(cin,str))
    {
        string x="";
        for(int i=0;i<(int)str.size();i++)
        {
            if(str[i]==' ')
            {
                cout<<solve(x)<<' ';
                x="";
            }
            else x+=str[i];
        }
        cout<<solve(x)<<endl;
    }
    return 0;
}