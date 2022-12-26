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
int t,n,m,k;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        cin>>str;
        int cnt=1;
        vector<int> v;
        for(int i=1;i<(int)str.size();i++) 
        {
            if(str[i]!=str[i-1])
            {
                v.push_back(cnt);
                cnt=1;
            }
            else cnt++;
        }
        v.push_back(cnt);
        int now=0,need=0;
        while(now<(int)v.size()-1){
            if(now+2<(int)v.size()&&v[now+1]==1){
                need++; now+=2;
            }
            else {need++; now++;}
        }
        if(k>=need) puts("Yes"); else puts("No");
    }
    return 0;
}

