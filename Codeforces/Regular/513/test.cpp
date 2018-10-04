/*************************************************************************
    > File Name: test.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 16:24:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char n[14];
ll a,b;
ll f[24][2];
int main()
{
    string n;
    cin>>n;
    int sz=n.size();
    int ans=0;int ost=0;
    for(int i=sz-1;i>=0;i--)
    {
        if(ost>0)
        {
            if(n[i]=='0') n[i]='9';
            else 
            {
                n[i]--;
                ost=0;
            }
        }
        if(n[i]=='9') ans+=9;
        else
        {
            ans+=n[i]-'0'+10;
            ost=1;
        }
    }
    if(ost==1) ans-=10;
    cout<<ans<<'\n';
}
