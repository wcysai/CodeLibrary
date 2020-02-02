#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,cnt;
int state[MAXN][MAXN];
vector<P> v;
vector<P> ans;
vector<P> more;
string construct(int x,int y)
{
    string str="";
    if(x<=y)
    {
        for(int i=0;i<x/2;i++) str+="D";
        for(int i=0;i<y;i++) str+="R";
        for(int i=0;i<(x+1)/2;i++) str+="D";
    }
    else
    {
        for(int i=0;i<y/2;i++) str+="R";
        for(int i=0;i<x;i++) str+="D";
        for(int i=0;i<(y+1)/2;i++) str+="R";
    }
    return str;
}
void query(string &str)
{
    ans.clear(); 
    cout<<"? "<<str<<endl;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans.push_back(P(x,y));
        if(state[x][y]!=0) 
        {
            cnt--;
            v.push_back(P(x,y));
        }
        state[x][y]=0;
    }
    sort(v.begin(),v.end());
    int x=1,y=1;
    for(int i=0;i<(int)str.size();i++) 
    {
        if(str[i]=='D') x++; else y++;
        if(state[x][y]==-1) state[x][y]=1;
    }
    x=1,y=1;
    int id=0;
    while(x<n||y<m)
    {
        if(id+1<(int)v.size()&&v[id+1].F==x)
        {
            for(int i=y+1;i<v[id+1].S;i++) 
            {
                if(state[x][i]==-1) {cnt--; ans.push_back(P(x,i));}
                state[x][i]=0;
            }
            x=v[id+1].F; y=v[id+1].S;     
        }
        else if(id+1<(int)v.size()&&v[id+1].S==y)
        {
            for(int i=x+1;i<v[id+1].F;i++) 
            {
                if(state[i][y]==-1) {cnt--; ans.push_back(P(i,y));}
                state[i][y]=0;
            }
            x=v[id+1].F; y=v[id+1].S;     
        }
        else if(x<n&&state[x+1][y]==0) x++;
        else if(y<m&&state[x][y+1]==0) y++;
        else if(x<n&&state[x+1][y]==1)
        {
            y++;
            if(state[x][y]==-1) {cnt--; ans.push_back(P(x,y));}
            state[x][y]=0;
        }
        else if(y<m&&state[x][y+1]==1)
        {
            x++;
            if(state[x][y]==-1) {cnt--; ans.push_back(P(x,y));}
            state[x][y]=0;
        }
        else
        {
            x=v[id+1].F; y=v[id+1].S;
        }
        while(id<(int)v.size()&&v[id+1].F<=x&&v[id+1].S<=y) id++;
    }
    for(auto p:ans) v.push_back(p);
}
void answer(string &str)
{
    cout<<"! "<<str<<endl;
    exit(0);
}
int main()
{
    scanf("%d%d",&n,&m);
    cnt=n+m-3;
    v.push_back(P(1,1)); v.push_back(P(n,m));
    memset(state,-1,sizeof(state));
    state[1][1]=state[n][m]=0;
    for(int i=0;i<10;i++)
    {
        sort(v.begin(),v.end());
        string str="";
        for(int j=1;j<(int)v.size();j++) str+=construct(v[j].F-v[j-1].F,v[j].S-v[j-1].S);
        query(str);
        if(cnt==0) break;
    }
    assert(cnt==0);
    sort(v.begin(),v.end());
    string str="";
    for(int j=1;j<(int)v.size();j++) str+=construct(v[j].F-v[j-1].F,v[j].S-v[j-1].S);
    answer(str);
    return 0;
}