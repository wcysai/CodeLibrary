#include<bits/stdc++.h>
#define MAXN 500005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<pair<int,string> > vec;
pair<int,string> find_place(string s)
{
    int l,r,rk=16,state=0;
    if(s[0]=='0') state=1;
    for(int i=1;i<(int)s.size();i++)
    {
        if(state==0&&s[i]=='1')
        {
            rk=rk/2;
            if(rk==1) {l=1; r=1; break;}
        }
        else if(state==0&&s[i]=='0')
        {
            if(rk==2) {l=r=2; break;}
            state=2;
        }
        else if(s[i]=='0') 
        {
            if(rk==2) {l=r=2; break;}
            if(state==1)
            {
                r=rk; l=r-rk/4+1;
                break;
            }
            else
            {
                l=rk/2+1; r=l+rk/4-1;
            }
        }
        else if(state==1) 
        {
            if(rk==2) {l=r=1; break;}
            state=2;
        }
        else 
        {
            rk/=2;
            state=1;
        }
    }
    if(l==r) return make_pair(l,to_string(l));
    else return make_pair(l,to_string(l)+'-'+to_string(r));
}
int main()
{
    string s,t;
    for(int i=0;i<16;i++)
    {
        cin>>s; cin>>t;
        auto p=find_place(t);
        s=p.S+' '+s;
        vec.push_back(make_pair(p.F,s));
    }
    sort(vec.begin(),vec.end());
    for(auto p:vec) cout<<p.S<<endl;
    return 0;
}