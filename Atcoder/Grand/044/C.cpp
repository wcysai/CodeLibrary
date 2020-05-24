#include<bits/stdc++.h>
#define MAXN 13
#define MAXM 550005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int ans[MAXM];
int curdigit[MAXN],curres[MAXN];
string reduce(string &t)
{
    vector<char> st;
    string ret="";
    for(auto ch:t)
    {
        st.push_back(ch);
        if(st.size()>=2&&st[(int)st.size()-1]=='S'&&st[(int)st.size()-2]=='S') st.pop_back(),st.pop_back();
    }
    for(auto ch:st) ret+=ch;
    return ret;
}
void update_ans()
{
    int x=0,y=0;
    for(int i=n-1;i>=0;i--)
    {
        x=x*3+curdigit[i];
        y=y*3+curres[i];
    }
    ans[x]=y;
}
void solve(int cur,string t)
{
    if(cur==n) 
    {
        update_ans();
        return;
    }
    for(int d=0;d<3;d++)
    {
        string curt="";
        int curd=d;
        for(auto ch:t)
        {
            if(ch=='S')
            {
                if(curd) curd=3-curd;
                curt+='S';
            }
            if(ch=='R')
            {
                curd++;
                if(curd==3)
                {
                    curd=0;
                    curt+='R';
                }
            }
        }
        curdigit[cur]=d;
        curres[cur]=curd;
        solve(cur+1,reduce(curt));
    }
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    solve(0,reduce(str));
    int p=1;
    for(int i=0;i<n;i++) p=p*3;
    for(int i=0;i<p;i++) printf("%d ",ans[i]);
    return 0;
}