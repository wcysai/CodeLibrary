#include<bits/stdc++.h>
#define MAXN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[128]; 
vector<P> v;
void draw_one_hole(int mask)
{
    v.push_back(P(0,0));
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) 
        {
            v.push_back(P(i,1));
            v.push_back(P(i+1,1));
            v.push_back(P(i+1,0));
        }
        else v.push_back(P(i+1,0));
    }
    for(int i=n-1;i>=0;i--) v.push_back(P(i,0));
    puts("Possible");
    printf("%d\n",(int)v.size());
    for(auto p:v) printf("%d %d\n",p.F,p.S);
    exit(0);
    
}
void draw_two_holes(int mask1,int mask2)
{
    v.push_back(P(0,0));
    for(int i=0;i<n;i++)
    {
        if(mask1&(1<<i)) 
        {
            v.push_back(P(i,1));
            v.push_back(P(i+1,1));
            v.push_back(P(i+1,0));
        }
        else v.push_back(P(i+1,0));
    }
    for(int i=n-1;i>=0;i--) v.push_back(P(i,0));
    puts("Possible");
    printf("%d\n",(int)v.size());
    for(auto p:v) printf("%d %d\n",p.F,p.S);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
    for(int i=0;i<(1<<n);i++)
    {
        bool f=true;
        for(int j=0;j<(1<<n);j++)
        {
            if((i&j)==j)
            {
                if(!a[j]) f=false;
            }
            else
            {
                if(a[j]) f=false;
            }
        }
        if(f) draw_one_hole(i);
    }
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            if(i&j) continue;
            bool f=true;
            for(int k=0;k<(1<<n);k++)
            {
                if((k&i)&&(k&j))
                {
                    if(a[k]) f=false;
                }
                else
                {
                    if(!a[k]) f=false;
                }
            }
            if(f) draw_two_holes(i,j);
        }
    }
    puts("Impossible");
    return 0;
}