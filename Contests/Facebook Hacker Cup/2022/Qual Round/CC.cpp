#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1025
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
string cand[MAXN];
bool good[MAXN];
string str;
bool check(int id)
{
    int sz=(int)str.size();
    if(sz<=10&&cand[id].substr(0,sz)==str) return false;
    if(sz>=10&&str.substr(0,10)==cand[id]) return false;
    return true;
}
int main()
{
    for(int i=0;i<1024;i++)
        for(int j=0;j<10;j++)
            if(i&(1<<j)) cand[i]+='-'; else cand[i]+='.';
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        cin>>str;
        printf("Case #%d:\n",t);
        int need=n-1;
        for(int i=0;i<1024;i++)
        {
            if(!need) break;
            if(check(i)) {cout<<cand[i]<<endl; need--;}
        }
    }
    return 0;
}

