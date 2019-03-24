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
int n,k,a[MAXN];
int find_intersect(P p,P q)
{
    P ret;
    ret.F=max(p.F,q.F); ret.S=min(p.S,q.S);
    return max(0,ret.S-ret.F+1);
}
struct line_set
{
    set<P> s;
    P original_line;
    int len;
    void add_line(P p)
    {
        auto it=s.lower_bound(p);
        while(it!=s.end()&&it->F<=p.S)
        {
            p.S=max(p.S,it->S);
            len-=(it->S-it->F+1);
            it=s.erase(it);
        }
        if(it!=s.begin())
        {
            it--;
            while(true)
            {
                if(it->S>=p.F)
                p.F=min(p.F,it->F);
                len-=(it->S-it->F+1);
                it=s.erase(it);
                if(it==s.begin()) break; else it--;
            }
        }
        s.insert(p);
        len+=(p.S-p.F+1);
    }
    void erase_line(P p)
    {
        auto it=s.lower_bound(p);
        while(it!=s.end()&&find_intersect(p,*it))
        {
            len-=find_intersect(p,*it);
            if(p.F<=it->F&&p.S>=it->S) it=s.erase(it);
            else if(p.F>=it->F&&p.S<=it->S)
            {
                if(p.F>it->F) s.insert(P(it->F,p.F-1));
                if(p.S<it->S) s.insert(P(p.S+1,it->S));
                s.erase(it);
                break;
            }
            else
            {
                s.insert(P(p.S+1,it->S));
                s.erase(it);
                break;
            }
        }
        it=s.lower_bound(p);
        if(it==s.begin()) return; else it--;
        while(find_intersect(p,*it))
        {
            len-=find_intersect(p,*it);
            if(p.F<=it->F&&p.S>=it->S) 
            {
                it=s.erase(it);
                if(it==s.begin()) return; else it--;
            }
            else if(p.F>=it->F&&p.S<=it->S)
            {
                if(p.F>it->F) s.insert(P(it->F,p.F-1));
                if(p.S<it->S) s.insert(P(p.S+1,it->S));
                s.erase(it);
                break;
            }
            else
            {
                s.insert(P(it->F,p.F-1));
                s.erase(it);
                break;
            }
        }
    }
};
vector<line_set> v;
int main()
{
    return 0;
}

