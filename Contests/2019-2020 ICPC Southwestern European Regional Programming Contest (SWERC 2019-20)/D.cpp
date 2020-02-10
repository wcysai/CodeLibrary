#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s;
string t;
int tot;
struct amino
{
    bool single;
    int id;
    int l;
    int r;
};
amino pool[MAXN];
typedef vector<int> vec;
map<P,int> mp;
vec check(string str)
{
    vec a;
    for(int i=0;i<10005;i++)
    {
        amino am;
        am.single=true;;
        am.id=10005-i; am.l=am.r=0;
        pool[i+1]=am;
        tot=max(tot,i+1);
        a.push_back(i+1);
    }
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='C')
        {
            int tmp=a.back();
            a.push_back(tmp);
        }
        else if(str[i]=='D')
        {
            a.pop_back();
        }
        else if(str[i]=='L')
        {
            if(pool[a.back()].single)
            {
                return vec();
            }
            else
            {
                int x=a.back();
                a.back()=pool[x].l;
            }
        }
        else if(str[i]=='P')
        {
            int x=a.back(); a.pop_back();
            int y=a.back(); a.pop_back();
            if(mp.find(P(x,y))!=mp.end()) a.push_back(mp[P(x,y)]);
            else
            {
                amino newamino;
                newamino.single=false;
                newamino.l=x; newamino.r=y;
                pool[++tot]=newamino; 
                a.push_back(tot); 
                mp[P(x,y)]=tot;
            }
        }
        else if(str[i]=='R')
        {
            if(pool[a.back()].single)
            {
                return vec();
            }
            else
            {
                int x=a.back();
                a.back()=pool[x].r;
            }
        }
        else if(str[i]=='S')
        {
            int x=a.back(); a.pop_back();
            int y=a.back(); a.pop_back();
            a.push_back(x); a.push_back(y);
        }
        else
        {
            if(pool[a.back()].single)
            {
                return vec();
            }
            else
            {
                int x=a.back(); a.pop_back();
                int y=pool[x].l; int z=pool[x].r;
                a.push_back(z); a.push_back(y);
            }
        }
        
    }
    return a;
}
bool same(vec &x,vec &y)
{
    if(x.size()!=y.size()) return false;
    for(int i=0;i<(int)x.size();i++) if(x[i]!=y[i]) return false;
    return true;
}
int main()
{
    cin>>s;
    cin>>t;
    vec cs=check(s); vec ct=check(t);
    if(same(cs,ct)) puts("True"); else puts("False");
    return 0;
}