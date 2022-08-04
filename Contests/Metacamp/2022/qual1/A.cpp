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
int n,m,k,q,a[MAXN];
vector<string> v1;
vector<string> v2;
set<string> valid;
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        v1.push_back(str);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        string str;
        cin>>str;
        v2.push_back(str);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        string str;
        cin>>str;
        valid.insert(str);
    }
    set<string> ans;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(cnt==k) break;
        if(!ans.count(v1[i])&&valid.count(v1[i]))
        {
            ans.insert(v1[i]);
            cnt++;
        }
    }
    cnt=0;
    for(int i=0;i<m;i++)
    {
        if(cnt==k) break;
        if(!ans.count(v2[i])&&valid.count(v2[i]))
        {
            ans.insert(v2[i]);
            cnt++;
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) cout<<x<<endl;
    return 0;
}

