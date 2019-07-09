#include<bits/stdc++.h>
#define MAXN 35
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
vector<string> ss,tt;
void transform(vector<string> &ss)
{
    int sz=(int)ss.size();
    for(int i=0;i<sz;i++)
    {
        string tmp=ss[i];
        for(int j=0;j<n;j++)
        {
            for(int k=j;k<n;k++)
            {
                string mid=tmp.substr(j,k-j+1);
                reverse(mid.begin(),mid.end());
                string rev=tmp.substr(0,j)+mid+tmp.substr(k+1);
                ss.push_back(rev);
            }
        }
    }
    sort(ss.begin(),ss.end());
    ss.erase(unique(ss.begin(),ss.end()),ss.end());
}
int main()
{
    freopen("dna.in","r",stdin);
    freopen("dna.out","w",stdout);
    cin>>s;
    cin>>t;
    n=(int)s.size();
    ss.push_back(s); tt.push_back(t);
    transform(ss); transform(ss);
    transform(tt); transform(tt); 
    for(auto str:tt)
    {
        auto it=lower_bound(ss.begin(),ss.end(),str);
        if(it!=ss.end()&&*it==str)
        {
            puts("Similar");
            return 0;
        }
    }
    puts("Different");
    return 0;
}
