#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN];
vector<int> op;
int find_pos(int cur)
{
    for(int i=1;i<=n;i++) if(p[i]==cur) return i;
    assert(0);
}
void apply_swap(int pos)
{
    op.push_back(pos);
    swap(p[pos],p[pos+1]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        op.clear();
        int cur=1,pos=find_pos(1);
        int tot=0;
        do
        {
            if(pos==cur)
            {
                cur++;
                if(cur==n+1) break;
                pos=find_pos(cur);
                continue;
            }
            if(cur>=n-2)
            {
                while(p[n-2]!=n-2||p[n-1]!=n-1||p[n]!=n)
                {
                    tot++;
                    if((tot&1)==((n-2)&1)) apply_swap(n-2); else apply_swap(n-1);
                }
                break;
            }
            tot++;
            if((tot&1)==((pos-1)&1))
            {
                apply_swap(pos-1);
                pos--;
            }
            else
            {
                bool f=false;
                for(int i=cur;i<=n-1;i++)
                {
                    if(((tot&1)==(i&1))&&(i!=pos))
                    {
                        apply_swap(i);
                        f=true;
                        break;
                    }
                }
                if(!f)
                {
                    apply_swap(pos);
                    pos++;
                }
            }
        } while(true);
        printf("%d\n",(int)op.size());
        for(auto x:op) printf("%d ",x);
        puts("");
    }
    return 0;
}