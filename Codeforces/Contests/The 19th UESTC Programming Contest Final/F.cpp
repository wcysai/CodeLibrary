#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
#define hash sbcjb
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string s[2];
int hash[2][5][2*MAXN];
int MOD[5]={998244353,993244853,998244853,1000000007,1000000009};
int BASE[5]={19260817,114514,1919810,233,666};
int get_hash(int x,int y,int base,int mod)
{
    if(x>y) swap(x,y);
    x=(1LL*x*base+y)%mod;
    return x^(x>>15);
}
void init_hash(int sid,int id,int k)
{
    if(k>=n)
    {
        int pos=k-n;
        hash[sid][id][k]=s[sid][pos]-'a'+1;
        return;
    }
    init_hash(sid,id,k*2); init_hash(sid,id,k*2+1);
    int x=hash[sid][id][k*2],y=hash[sid][id][k*2+1];
    hash[sid][id][k]=get_hash(x,y,BASE[id],MOD[id]);
}
void update(int sid,int id,int pos,char ch)
{
    int k=pos+n;
    hash[sid][id][k]=ch-'a'+1;
    while(k>1)
    {
        k=k/2;
        int x=hash[sid][id][k*2],y=hash[sid][id][k*2+1];
        if(x<y) swap(x,y);
        hash[sid][id][k]=get_hash(x,y,BASE[id],MOD[id]);
    }
}
bool check_equivalent()
{
    for(int i=0;i<2;i++) if(hash[0][i][1]!=hash[1][i][1]) return false;
    return true;
}
void output_hash()
{
    for(int sid=0;sid<2;sid++)
        for(int id=0;id<2;id++)
        {
            for(int i=1;i<=2*n-1;i++) printf("%d ",hash[sid][id][i]);
            puts("");
        }
}
string ss,tt;
int main()
{
    scanf("%d",&n);
    cin>>s[0]; cin>>s[1];
    for(int sid=0;sid<2;sid++)
        for(int id=0;id<2;id++)
            init_hash(sid,id,1);
    if(check_equivalent()) puts("YES"); else puts("NO");
    //output_hash();
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        cin>>ss;
        int x;
        scanf("%d",&x);
        cin>>tt;
        if(ss=="s") 
        {
            for(int j=0;j<5;j++) update(0,j,x-1,tt[0]);
        }
        else
        {
            for(int j=0;j<5;j++) update(1,j,x-1,tt[0]);
        }
        //output_hash();
        if(check_equivalent()) puts("YES"); else puts("NO");
    }
    return 0;
}

