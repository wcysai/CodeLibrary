#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<P> G[MAXN];
template< typename T > 
struct SlopeTrick {
    const T INF = numeric_limits<T>::max()/3;
    T min_f;
    priority_queue<T,vector<T>,less<T> > L;
    priority_queue<T,vector<T>,greater<T> > R;
    T add_l,add_r;
    void push_R(const T& a) 
    {
        R.push(a-add_r);
    }
    T top_R() const 
    {
        if (R.empty()) return INF;
        else return R.top() + add_r;
    }
    T pop_R() 
    {
        T val=top_R();
        if(not R.empty()) R.pop();
        return val;
    }
    void push_L(const T& a) 
    {
        L.push(a-add_l);
    }
    T top_L() const 
    {
        if (L.empty()) return -INF;
        else return L.top()+add_l;
    }
    T pop_L() 
    {
        T val=top_L();
        if (not L.empty()) L.pop();
        return val;
    }
    size_t size() 
    {
        return L.size()+R.size();
    }

    SlopeTrick():min_f(0),add_l(0),add_r(0) {}

    struct Query 
    {
        T lx, rx, min_f;
    };
 
    // return min f(x)
    /*Query query() const {
        return (Query) { top_L(), top_R(), min_f };
    }*/
 
    // f(x) += a
    void add_all(const T& a) 
    {
        min_f+=a;
    }
 
    // add \_
    // f(x) += max(a - x, 0)
    void add_a_minus_x(const T& a) 
    {
        min_f+=max(T(0),a-top_R());
        push_R(a);
        push_L(pop_R());
    }
 
    // add _/
    // f(x) += max(x - a, 0)
    void add_x_minus_a(const T& a) 
    {
        min_f+=max(T(0),top_L()-a);
        push_L(a);
        push_R(pop_L());
    }
 
    // add \/
    // f(x) += abs(x - a)
    void add_abs(const T& a) 
    {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }
 
    // \/ -> \_
    // f_{new} (x) = min f(y) (y <= x)
    void clear_right() 
    {
        while(not R.empty()) R.pop();
    }
 
    // \/ -> _/
    // f_{new} (x) = min f(y) (y >= x)
    void clear_left() 
    {
        while(not L.empty()) L.pop();
    }
 
    // \/ -> \_/
    // f_{new} (x) = min f(y) (x-b <= y <= x-a)
    void shift(const T& a, const T& b) 
    {
        assert(a<=b);
        add_l+=a;
        add_r+=b;
    }
 
    // \/. -> .\/
    // f_{new} (x) = f(x - a)
    void shift(const T& a) 
    {
        shift(a,a);
    }
 
    // L, R を破壊する
    T get(const T& x) 
    {
        T ret=min_f;
        while(not L.empty()) ret+=max(T(0),pop_L()-x);
        while(not R.empty()) ret+=max(T(0),x-pop_R());
        return ret;
    }
 
    void merge(SlopeTrick& st) {
        if(st.size()>size()) 
        {
            swap(st.L,L);
            swap(st.R,R);
            swap(st.add_l,add_l);
            swap(st.add_r,add_r);
            swap(st.min_f,min_f);
        }
        while(not st.R.empty()) add_x_minus_a(st.pop_R());
        while(not st.L.empty()) add_a_minus_x(st.pop_L());
        min_f+=st.min_f;
    }
};
SlopeTrick<int> f[MAXN];
void dfs(int v,int p){
    f[]
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w)); G[v].push_back(P(u,w));
    }
    dfs(1,0);
    return 0;
}

