#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q;
multiset<int> s;
queue<int> que;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        int type,x;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&x);
            que.push(x);
        }
        else if(type==2)
        {
            if(s.size())
            {
                printf("%d\n",*s.begin());
                s.erase(s.begin());
            }
            else
            {
                printf("%d\n",que.front());
                que.pop();
            }
        }
        else
        {
            while(que.size())
            {
                s.insert(que.front());
                que.pop();
            }
        }
    }
    return 0;
}