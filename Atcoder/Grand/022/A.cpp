#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
string str;
set<char> s;
bool has[26];
int main()
{
    cin>>str;
    int n=str.size();
    if(str=="zyxwvutsrqponmlkjihgfedcba")
    {
        puts("-1");
        return 0;
    }
    if(n<26)
    {
        memset(has,false,sizeof(has));
        for(int i=0;i<n;i++) has[str[i]-'a']=true;
        for(int i=0;i<26;i++)
        {
            if(!has[i])
            {
                str+=(char)('a'+i);
                break;
            }
        }
        cout<<str<<endl;
        return 0;
    }
    for(int i=25;i>=0;i--)
    {
        bool f=false;
        for(int j=i+1;j<26;j++)
        {
            if(str[j]>str[i])
            {
                f=true;
                break;
            }
        }
        if(f)
        {
            int now=INF;
            for(int j=i+1;j<26;j++) if(str[j]>str[i]) now=min(now,str[j]-'a');
            str=str.substr(0,i);
            str+=(char)('a'+now);
            cout<<str<<endl;
            return 0;
        }
    }
    return 0;
}

