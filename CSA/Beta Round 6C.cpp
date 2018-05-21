#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n;
set<int> s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(s.count(x)) s.erase(x); else s.insert(x);
        }
        if(s.size()) printf("A\n"); else printf("B\n");
    }
    return 0;
}
