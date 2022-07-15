#pragma GCC optimize(3)
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
string s,t;
vector<pair<char,int> > vs,vt;
int main()
{
    cin>>s;
    cin>>t;
    char ch=s[0];
    int cnt=1;
    for(int i=1;i<(int)s.size();i++)
    {
        if(s[i]==ch) cnt++;
        else
        {
            vs.push_back(make_pair(ch,cnt));
            ch=s[i]; cnt=1;
        }
    }
    vs.push_back(make_pair(ch,cnt));
    ch=t[0]; cnt=1;
    for(int i=1;i<(int)t.size();i++)
    {
        if(t[i]==ch) cnt++;
        else
        {
            vt.push_back(make_pair(ch,cnt));
            ch=t[i]; cnt=1;
        }
    }
    vt.push_back(make_pair(ch,cnt));
    bool f=true;
    if(vs.size()!=vt.size()) f=false;
    else
    {
        for(int i=0;i<(int)vs.size();i++)
        {
            if(vs[i].F!=vt[i].F) f=false;
            if(vs[i].S>vt[i].S) f=false;
            if(vs[i].S==1&&vt[i].S!=1) f=false;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

