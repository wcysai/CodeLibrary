#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 daskodsa
#define y1 dasklod
#define x2 dzsokdsao
#define y2 dxzoikdoas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,x,y,curx,cury;
string ans;
char mp[5];
vector<P> v;
void go_up() {curx--; v.push_back(P(curx,cury));}
void go_down() {curx++; v.push_back(P(curx,cury));}
void go_left() {cury--; v.push_back(P(curx,cury));}
void go_right() {cury++; v.push_back(P(curx,cury));}
char get_char(int x1,int y1,int x2,int y2)
{
    if(x2==x1+1) return 'D';
    else if(x2==x1-1) return 'U';
    else if(y2==y1+1) return 'R';
    else return 'L';
}
bool check(int n,int m,int x,int y)
{
    if(n==1)
    {
        if(y==1||y==m) return true;
        return false;
    }
    if(m==1)
    {
        if(x==1||x==n) return true;
        return false;
    }
    if((n&1)&&(m&1)&&((x&1)^(y&1))) return false;
    return true;
}
void solve_corner(int n,int m,int x,int y,int U,int L,int D,int R)
{
    if(x!=1)
    {
        solve_corner(n,m,1,y,D,L,U,R);
        return;
    }
    if(y!=1)
    {
        solve_corner(n,m,x,1,U,R,D,L);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++) if(i&1) ans+=mp[R]; else ans+=mp[L];
        if(i!=n) ans+=mp[D];
    }
}
void solve_border(int n,int m,int x,int y,int U,int L,int D,int R)
{
    //printf("solve border %d %d %d %d\n",n,m,x,y);
    if(y==1)
    {
        solve_border(m,n,y,x,L,D,R,U);
        return;
    }
    if(x==n)
    {
        solve_border(n,m,1,y,D,L,U,R);
        return;
    }
    if(n%2==0)
    {
        int len=y;
        for(int i=1;i<=n;i++)
        {
             for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[L]; else ans+=mp[R];
             if(i!=n) ans+=mp[D];
        } 
        ans+=mp[R];
        len=m-y;
        for(int i=1;i<=n;i++)
        {
             for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[R]; else ans+=mp[L];
             if(i!=n) ans+=mp[U];
        } 
        return;
    }
    else if((m-y)%2==0)
    {
        for(int i=y;i<=m;i++)
        {
            if((i-y+1)&1) ans+=mp[D]; else ans+=mp[U];
            if(i!=m) ans+=mp[R];
        } 
        ans+=mp[D];
        int len=n-2;
        for(int i=y;i<=m;i++)
        {
            for(int j=1;j<=len-1;j++) if((i-y+1)&1) ans+=mp[D]; else ans+=mp[U];
            ans+=mp[L];
        }
        solve_corner(n,y-1,n,y-1,U,L,D,R);
    }
    else
    {
        assert(y&1);
        for(int i=1;i<=y;i++)
        {
            if(i&1) ans+=mp[D]; else ans+=mp[U];
            if(i!=y) ans+=mp[L];
        } 
        ans+=mp[D];
        int len=n-2;
        for(int i=1;i<=y;i++)
        {
            for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[D]; else ans+=mp[U];
            ans+=mp[R];
        }
        solve_corner(n,m-y,n,1,U,L,D,R);
    }
}
void solve_center(int n,int m,int x,int y,int U,int L,int D,int R)
{
    printf("solve center %d %d %d %d\n",n,m,x,y);
    bool xflag=(x%2==0)||((n-x+1)%2==0);
    bool yflag=(y%2==0)||((m-y+1)%2==0);
    if(yflag&&(!xflag))
    {
        solve_center(m,n,y,x,L,D,R,U);
        return;
    }
    if((n-x+1)%2==0&&(n-x+1<x))
    {
        solve_center(n,m,n-x+1,y,D,L,U,R);
        return;
    }
    if(x%2==0)
    {
        int len=y;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[L]; else ans+=mp[R];
            if(i!=x) ans+=mp[U];
        }
        ans+=mp[R];
        len=m-y;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[R]; else ans+=mp[L];
            if(i!=x) ans+=mp[D];
        }
        ans+=mp[D];
        cout<<ans<<endl;
        solve_border(n-x,m,1,y+1,U,L,D,R);
    }
    else
    {
        assert(x&1); assert((n-x+1)&1);
        assert(y&1); assert((n-y+1)&1);
        for(int i=1;i<=y-1;i++) ans+=mp[L];
        ans+=mp[U];
        int len=x-1;
        for(int i=1;i<=y;i++)
        {
            for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[U]; else ans+=mp[D];
            if(i!=y) ans+=mp[R];
        }
        ans+=mp[R];
        len=m-y+1;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=len-1;j++) if(i&1) ans+=mp[R]; else ans+=mp[L];
            if(i!=x) ans+=mp[D];
        }
        ans+=mp[D];
        solve_corner(n-x,m,1,m,U,L,D,R);
    }
    
}
int main()
{
    mp[0]='U'; mp[1]='L'; mp[2]='D'; mp[3]='R';
    scanf("%d",&t);
    while(t--)
    {
        ans="";
        scanf("%d%d%d%d",&n,&m,&x,&y);
        if(!check(n,m,x,y)) {puts("IMPOSSIBLE"); continue;}
        if(n==1)
        {
            if(y==1) for(int i=1;i<=m-1;i++) ans+='R';
            else for(int i=1;i<=m-1;i++) ans+='L';
        }
        else if(m==1)
        {
            if(x==1) for(int i=1;i<=n-1;i++) ans+='D';
            else for(int i=1;i<=n-1;i++) ans+='U';
        }
        else if(m%2==0)
        {
            v.clear();
            curx=1; cury=1;
            v.push_back(P(curx,cury));
            go_down();
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n-2;j++) 
                    if(i&1) go_down(); else go_up();
                if(i!=m) go_right();
            }
            go_up();
            for(int i=1;i<=m-2;i++) go_left();
            int id=-1;
            for(int i=0;i<(int)v.size();i++) if(v[i].F==x&&v[i].S==y) {id=i; break;}
            for(int i=0;i<(int)v.size()-1;i++)
            {
                int nid=(id+1);
                if(nid==(int)v.size()) nid=0;
                ans+=get_char(v[id].F,v[id].S,v[nid].F,v[nid].S);
                id=nid;
            }
        }
        else if(n%2==0)
        {
            v.clear();
            curx=1; cury=1;
            v.push_back(P(curx,cury));
            go_right();
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m-2;j++) 
                    if(i&1) go_right(); else go_left();
                if(i!=n) go_down();
            }
            go_left();
            for(int i=1;i<=n-2;i++) go_up();
            int id=-1;
            for(int i=0;i<(int)v.size();i++) if(v[i].F==x&&v[i].S==y) {id=i; break;}
            for(int i=0;i<(int)v.size()-1;i++)
            {
                int nid=(id+1);
                if(nid==(int)v.size()) nid=0;
                ans+=get_char(v[id].F,v[id].S,v[nid].F,v[nid].S);
                id=nid;
            }
        }
        else if(x%2==0)
        {
            for(int i=1;i<=x;i++)
            {
                for(int j=1;j<=y-1;j++) if(i&1) ans+='L'; else ans+='R';
                if(i!=x) ans+='U'; else ans+='R';
            }
            for(int i=1;i<=m-y;i++)
            {
                for(int j=1;j<=x-1;j++) if(i&1) ans+='D'; else ans+='U';
                if(i!=m-y) ans+='R'; else ans+='D';
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n-x-1;j++) if(i&1) ans+='D'; else ans+='U';
                if(i!=m) ans+='L';
            }
        }
        else 
        {
            bool swapx=false; bool swapy=false;
            if(x==1) {x=n; swapx=true;}
            if(y==m) {y=1; swapy=true;}
            for(int i=1;i<=y-1;i++) ans+='L';
            ans+='U';
            for(int i=1;i<=y;i++)
            {
                for(int j=1;j<=x-2;j++) if(i&1) ans+='U'; else ans+='D';
                ans+='R';
            }
            for(int i=1;i<=x;i++)
            {
                for(int j=1;j<=m-y-1;j++) if(i&1) ans+='R'; else ans+='L';
                if(i!=x) ans+='D'; 
            }
            if(x!=n)
            {
                ans+='D';
                for(int i=1;i<=m;i++)
                {
                    for(int j=1;j<=n-x-1;j++) if(i&1) ans+='D'; else ans+='U';
                    if(i!=m) ans+='L';
                }
            }
            if(swapx) for(auto &ch:ans) if(ch=='U') ch='D'; else if(ch=='D') ch='U';
            if(swapy) for(auto &ch:ans) if(ch=='L') ch='R'; else if(ch=='R') ch='L';
        }
        cout<<ans<<endl;
    }
    return 0;
}