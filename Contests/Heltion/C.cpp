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
int t,n,q;
set<int> good,bad,unknown;
int added;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        good.clear(); bad.clear(); unknown.clear();
        for(int i=1;i<=n;i++) bad.insert(i);
        for(int i=0;i<q;i++)
        {
            string str;
            cin>>str;
            if(str=="add")
            {
                if(added==n)
                {
                    puts("bug");
                    continue;
                }
                else
                {
                    for(auto x:bad) unknown.insert(x);
                    bad.clear();
                    added++;
                    if(added==n)
                    {
                        for(auto x:unknown) good.insert(x);
                        unknown.clear();
                    }
                }
            }
            else 
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(y==0)
                {
                    if(good.count(x))
                    {
                        puts("bug");
                        continue;
                    }
                    else 
                    {
                        if(unknown.count(x)) {unknown.erase(x); bad.insert(x);}
                        if(added+bad.size()==n)
                        {
                            for(auto x:unknown) good.insert(x);
                            unknown.clear();
                        }
                    }
                }
                else
                {
                    if(bad.count(x)||((good.size()==added)&&(!good.count(x))))
                    {
                        puts("bug");
                        continue;
                    }
                    else 
                    {
                        if(good.count(x)) good.erase(x);
                        added--;
                        bad.insert(x);
                        if(good.size()==added) {for(auto x:unknown) bad.insert(x); unknown.clear();}
                    }
                }
            }
            printf("%d %d\n",(int)good.size(),(int)bad.size());
        }
    }
    return 0;
}

