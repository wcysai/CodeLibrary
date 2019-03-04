#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1005
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
int n,m,a,b;
char mp[MAXN][MAXN];
void fill(int x1,int y1,int x2,int y2)
{
    if(x1==x2) {mp[x1][y1]='<'; mp[x1][y2]='>';}
    else {mp[x1][y1]='^'; mp[x2][y1]='v';}
}
void print()
{
    for(int i=1;i<=n;i++) printf("%s\n",mp[i]+1);
}
void clear()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j]='.';
}
bool fill_even_area(int n,int m)
{
    for(int i=1;i<=n/2;i++)
    {
        if(!a&&!b) break;
        for(int j=1;j<=m/2;j++)
        {
            if(a>=2) {fill(i*2-1,j*2-1,i*2-1,j*2); fill(i*2,j*2-1,i*2,j*2); a-=2;}
            else if(a==1) {fill(i*2-1,j*2-1,i*2-1,j*2); a--;}
            else if(b>=2) {fill(i*2-1,j*2-1,i*2,j*2-1); fill(i*2-1,j*2,i*2,j*2); b-=2;}
            else if(b==1) {fill(i*2-1,j*2-1,i*2,j*2-1); b--;}
        }
    }
    if(a||b) return false;
    return true;
}
void succ()
{
    puts("YES");
    print();
    exit(0);
}
void fail()
{
    puts("NO");
    exit(0);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(2*(a+b)>n*m) fail();
    clear();
    if(n%2==0&&m%2==0) 
    {
        if(fill_even_area(n,m)) succ(); else fail();
    }
    else 
    {
        if((n&1)&&(m&1))
        {
            int aa=a,bb=b;
            int now=1;
            while(now+1<=m&&a)
            {
                fill(n,now,n,now+1);
                now+=2;a--;
            }
            now=1;
            while(now+1<=n&&b)
            {
                fill(now,m,now+1,m);
                now+=2;b--;
            }
            if(fill_even_area(n-1,m-1)) succ();
            a=aa;b=bb;
            clear();
            if(a>=2&&b>=2&&n>=3&&m>=3)
            {
                fill(n-2,m-2,n-2,m-1);fill(n,m-1,n,m);
                fill(n-1,m-2,n,m-2);fill(n-2,m,n-1,m);
                a-=2;b-=2;
                int now=1;
                while(now+1<=m-3&&a)
                {
                    fill(n,now,n,now+1);
                    now+=2;a--;
                }
                now=1;
                while(now+1<=n-3&&b)
                {
                    fill(now,m,now+1,m);
                    now+=2;b--;
                }
                for(int i=1;i<=n/2;i++)
                {
                    if(!a&&!b) break;
                    for(int j=1;j<=(m-3)/2;j++)
                    {
                        if(a>=2) {fill(i*2-1,j*2-1,i*2-1,j*2); fill(i*2,j*2-1,i*2,j*2); a-=2;}
                        else if(a==1) {fill(i*2-1,j*2-1,i*2-1,j*2); a--;}
                        else if(b>=2) {fill(i*2-1,j*2-1,i*2,j*2-1); fill(i*2-1,j*2,i*2,j*2); b-=2;}
                        else if(b==1) {fill(i*2-1,j*2-1,i*2,j*2-1); b--;}
                    }
                }
                for(int i=1;i<=(n-3)/2;i++)
                {
                    if(!a&&!b) break;
                    for(int j=(m-1)/2;j<=(m-1)/2;j++)
                    {
                        if(a>=2) {fill(i*2-1,j*2-1,i*2-1,j*2); fill(i*2,j*2-1,i*2,j*2); a-=2;}
                        else if(a==1) {fill(i*2-1,j*2-1,i*2-1,j*2); a--;}
                        else if(b>=2) {fill(i*2-1,j*2-1,i*2,j*2-1); fill(i*2-1,j*2,i*2,j*2); b-=2;}
                        else if(b==1) {fill(i*2-1,j*2-1,i*2,j*2-1); b--;}
                    }
                }
                if(a||b) fail(); else succ();
            }
            else fail();
        }
        if(n&1)
        {
            int now=1;
            while(now+1<=m&&a)
            {
                fill(n,now,n,now+1);
                now+=2;a--;
            }
        }
        if(m&1)
        {
            int now=1;
            while(now+1<=n&&b)
            {
                fill(now,m,now+1,m);
                now+=2;b--;
            }
        }
        if(fill_even_area(n-(n&1),m-(m&1))) succ(); else fail();
    }
    return 0;
}

