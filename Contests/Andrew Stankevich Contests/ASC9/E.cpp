#include<bits/stdc++.h>
#define MAXN 256
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> a,b,c;
typedef vector<int> vec;
typedef vector<vec> mat;
int sz;
void add(int &x) {x^=1;}
int ans[MAXN];
vector<int> pos;
void gauss_jordan(mat &A,vec &b)
{
    int pt=0;
    for(int i=0;i<128;i++)
    {
        int pivot=-1;
        for(int j=pt;j<512;j++) if(A[j][i]==1) {pivot=j; break;}
        if(pivot==-1) continue;
        swap(A[pt],A[pivot]); swap(b[pt],b[pivot]);
        pos.push_back(i);
        for(int j=pt+1;j<512;j++)
        {
            if(A[j][i]==1)
            {
                for(int k=0;k<128;k++) A[j][k]^=A[pt][k];
                b[j]^=b[pt];
            }
        }
        pt++;
    }
    for(int i=0;i<512;i++)
    {
        bool empty=true;
        for(int j=0;j<128;j++) if(A[i][j]) empty=false;
        if(empty&&b[i])
        {
            puts("no solution");
            return;
        }
    }
    for(int i=pt-1;i>=0;i--)
    {
        int x=pos[i],v=b[i];
        for(int j=x+1;j<128;j++) if(A[i][j]&&ans[j]) v^=1;
        ans[x]=v;
    }
    for(int i=127;i>=0;i--)
    {
        if(ans[i]==1)
        {
            printf("%d ",i);
            for(int j=i;j>=0;j--) printf("%d ",ans[j]);
            return;
        }
    }
    puts("-1");
}
int main()
{
    freopen("quadratic.in","r",stdin);
    freopen("quadratic.out","w",stdout);
    int x,y;
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
        scanf("%d",&y);
        a.push_back(y);
    }
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
        scanf("%d",&y);
        b.push_back(y);
    }
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
        scanf("%d",&y);
        c.push_back(y);
    }
    reverse(a.begin(),a.end()); reverse(b.begin(),b.end()); reverse(c.begin(),c.end());
    mat A(512,vec(128)); vec B(512,0);
    for(int i=0;i<(int)a.size();i++)
    {
        if(a[i]==0) continue;
        for(int j=0;j<128;j++) add(A[i+j*2][j]);
    }
    for(int i=0;i<(int)b.size();i++)
    {
        if(b[i]==0) continue;
        for(int j=0;j<128;j++) add(A[i+j][j]);
    }
    for(int i=0;i<(int)c.size();i++)
    {
        if(c[i]==0) continue;
        add(B[i]);
    }  
    gauss_jordan(A,B);
    return 0;
}
