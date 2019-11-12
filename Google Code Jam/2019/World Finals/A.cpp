#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,Nmax,N,M,R,tot;
vector<int> x,y;
int askchebyshev(int x,int y)
{
    ++tot;
    assert(tot<=R);
    printf("%d %d\n",x,y);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}
void get_x_coordinates()
{
    x.clear();
    int lastpos=0;
    for(int i=1;i<=Nmax;i++)
    {
        int l=lastpos,r=4*M+2;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            int below=askchebyshev(-2*M,mid)-askchebyshev(-2*M,mid-1);
            if(below<i) {l=mid; lastpos=l;} else r=mid;
        }
        x.push_back(-2*M+l);
    }
}
void get_y_coordinates()
{
    y.clear();
    int lastpos=0;
    for(int i=1;i<=N;i++)
    {
        int l=lastpos,r=4*M+2;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            int below=askchebyshev(2*M,mid)-askchebyshev(2*M,mid-1);
            if(below<i) {l=mid; lastpos=l;} else r=mid;
        }
        y.push_back(2*M-l);
    }
}
void next_phase()
{
    printf("READY\n");
    fflush(stdout);
}
int get_answer(int xx,int yy)
{
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans+=max(x[i]-xx,xx-x[i]);
        ans+=max(y[i]-yy,yy-y[i]);
    }
    ans/=2;
    return ans;
}
string str;
void answer_queries()
{
    while(true)
    {
        cin>>str;
        if(str[0]=='E') exit(0);
        if(str[0]=='D') return;
        int x=atoi(str.c_str());
        cin>>str;
        int y=atoi(str.c_str());
        printf("%d\n",get_answer(x+y,x-y));
        fflush(stdout);
    }
}
void solve()
{
    tot=0;
    N=askchebyshev(-2*M,4*M+2)-askchebyshev(-2*M,4*M+1);
    get_x_coordinates();
    get_y_coordinates();
    next_phase();
    answer_queries();
}
int main()
{
    scanf("%d%d%d%d",&T,&Nmax,&M,&R);
    while(T--) solve();
    return 0;
}
