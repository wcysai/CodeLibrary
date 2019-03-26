#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
vector<int> v;
int find_mod()
{
    int sz=(int)v.size();
    int x;
    if(sz==1) x=v[sz-1];
    else x=v[sz-2]*10+v[sz-1];
    return x%4;
}
void dec()
{
    int sz=(int)v.size();
    v[sz-1]--;
    int pos=sz-1;
    while(v[pos]<0&&pos>=0)
    {
        v[pos]+=10; v[pos-1]--;
        pos--;
    }
}
void div2()
{
    int sz=(int)v.size();
    int pos=sz-1;
    while(pos>=0)
    {
        if(pos>0&&v[pos-1]&1)
        {
            v[pos]=(v[pos]+10)/2;
            v[pos-1]--;
        }
        else v[pos]=v[pos]/2;
        pos--;
    }
}
void print()
{
    int sz=(int)v.size();
    bool lz=true;
    for(int i=0;i<sz;i++)
    {
        if(lz&&v[i]==0) continue;
        lz=false;
        printf("%d",v[i]);
    }
}
int main()
{
    freopen("china.in","r",stdin);
    freopen("china.out","w",stdout);
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++) v.push_back(str[i]-'0');
    int x=find_mod();
    if(x&1) {dec(); div2();}
    else if(x==0) {div2(); dec();}
    else {div2(); dec(); dec();}
    print();
    return 0;
}
