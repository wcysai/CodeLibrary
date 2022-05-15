#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],ans;
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    multiset<int> s;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='R')
        {
            int l=i-1,r=i+1,cnt=0;
            while(l>=0&&r<n&&str[l]=='A'&&str[r]=='C') {cnt++; l--; r++;}
            if(cnt) s.insert(cnt);
        }
    }
    int tot=1;
    while(s.size())
    {
        if(tot&1)
        {
            auto it=(--s.end());
            int x=*it; s.erase(it);
            if(x>1) s.insert(x-1);
        }
        else
        {
            s.erase(s.begin());
        }
        tot++;
    }
    printf("%d\n",tot-1);
    return 0;
}

