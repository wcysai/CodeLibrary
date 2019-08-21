#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN][6];
mt19937 wcy(time(NULL));
set<P> us;
vector<int> v[32];
int seed[125][5];
int val[MAXN];
void gen_seed()
{
    for(int j=48;j<=122;j++)
        for(int k=0;k<5;k++)
            seed[j][k]=wcy()%2;
}
void get_hash()
{
    for(int i=0;i<n;i++)
    {
        val[i]=0;
        for(int j=0;j<5;j++)
            val[i]=2*val[i]+seed[(int)(str[i][j])][j];
        v[val[i]].push_back(i);
    }
}
void print()
{
    printf("%d\n",(int)us.size());
    for(auto p:us) printf("%d %d\n",p.F+1,p.S+1);
}
void solve()
{
    gen_seed(); get_hash();
    for(int i=0;i<32;i++) v[i].clear();
    for(int i=0;i<n;i++)
    {
        for(auto x:v[31-val[i]])
        {
            us.insert(P(x,i));
            if((int)us.size()>=100000)
            {
                print();
                exit(0);
            }
        }
        v[val[i]].push_back(i);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
   /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++) printf("%d ",(int)str[i][j]);
        puts("");
    } */
    for(int i=0;i<800;i++) solve();
    print();
    return 0;
}
