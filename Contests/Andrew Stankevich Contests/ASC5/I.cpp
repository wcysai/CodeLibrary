#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
deque<int> deq;
void solve(int l,int r,deque<int> deq)
{
    if(l==r) return;
    int mid=(l+r)/2;
    deque<int> deq1,deq2;
    deq1.clear(); deq2.clear();
    for(int i=0;i<(int)deq.size();i++)
    {
        if(deq[i]<=mid) 
        {
            printf("%d %d ",deq[i],deq[i]);
            deq1.push_back(deq[i]);
        }
        else
        {
            printf("%d ",deq[i]);
            deq2.push_front(deq[i]);
        }
    }
    solve(l,mid,deq1);
    for(int i=0;i<(int)deq2.size();i++) printf("%d ",deq2[i]);
    solve(mid+1,r,deq2);
}
int main()
{
    freopen("railsort.in","r",stdin);
    freopen("railsort.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++)
    {
        int x;
        scanf("%d",&x);
        deq.push_back(x);
    }
    solve(1,(1<<n),deq);
    return 0;
}
