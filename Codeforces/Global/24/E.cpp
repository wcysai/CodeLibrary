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
int t,n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        if(k<=a[1]) {puts("YES"); continue;}
        else if(k>a[1]+b[1]) {puts("NO"); continue;}
        int pos=k-b[1];
        vector<P> v;
        for(int i=2;i<=n;i++)
        {
            v.push_back(P(a[i]+b[i],b[i]));
        }
        sort(v.begin(),v.end());
        multiset<P> ms;
        bool f=false;
        do
        {
            while(v.size()&&v.back().F>=pos) {ms.insert(P(v.back().S,v.back().F-v.back().S)); v.pop_back();}
            if(!ms.size()) break;
            auto it=ms.end();
            it--;
            if(it->S>=pos) {f=true; break;}
            pos-=(it->F);
            ms.erase(it);
        }while(true);
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

