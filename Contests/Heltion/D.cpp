#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rank sbcjb
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
map<char,int> suit,rank; 
int T;
//2S-AS : 0-12
//2H-AH : 13-25
//2C-AC : 26-38
//2D-AD : 39-51
int read_card()
{
    string str;
    cin>>str;
    int st=suit[str[1]],rk=rank[str[0]];
    return st*13+rk;
}
int flush(vector<int> &v)
{
    int st=v[0]/13;
    for(int i=1;i<(int)v.size();i++) if(v[i]/13!=st) return 0;
    int sum=0;
    for(int i=4;i>=0;i--) sum=sum*13+(v[i]%13);
    return sum;
}
int straight(vector<int> &v)
{
    bool consec=true;
    for(int i=1;i<5;i++) if(v[i]%13!=v[i-1]%13+1) {consec=false; break;}
    if(consec) return v[4]%13;
    if(v[0]%13==0&&v[1]%13==1&&v[2]%13==2&&v[3]%13==3&&v[4]%13==12) return 4;
    return 0;
}
int high_card(vector<int> &v)
{
    int sum=0;
    for(int i=4;i>=0;i--) sum=sum*13+(v[i]%13);
    return sum;
}
int one_pair(vector<int> &v)
{
    int sum=0;
    if(v[0]%13==v[1]%13) {sum=v[0]%13; for(int i=4;i>=2;i--) sum=sum*13+(v[i]%13);}
    else if(v[1]%13==v[2]%13) {sum=v[1]%13; for(int i=4;i>=3;i--) sum=sum*13+(v[i]%13); sum=sum*13+(v[0]%13);}
    else if(v[2]%13==v[3]%13) {sum=v[2]%13; sum=sum*13+(v[4]%13); for(int i=1;i>=0;i--) sum=sum*13+(v[i]%13); }
    else if(v[3]%13==v[4]%13) {sum=v[3]%13; for(int i=2;i>=0;i--) sum=sum*13+(v[i]%13); }
    return sum;
}
int two_pairs(vector<int> &v)
{
    int sum=0;
    if((v[0]%13==v[1]%13)&&(v[2]%13==v[3]%13)) sum=(v[2]%13)*13*13+(v[0]%13)*13+v[4]%13; 
    else if((v[0]%13==v[1]%13)&&(v[3]%13==v[4]%13)) sum=(v[3]%13)*13*13+(v[0]%13)*13+v[2]%13; 
    else if((v[1]%13==v[2]%13)&&(v[3]%13==v[4]%13)) sum=(v[3]%13)*13*13+(v[1]%13)*13+v[0]%13; 
    return sum;
}
int full_house(vector<int> &v)
{
    int sum=0;
    if((v[0]%13==v[1]%13)&&(v[1]%13==v[2]%13)&&(v[3]%13==v[4]%13)) sum=(v[0]%13)*13+(v[3]%13); 
    else if((v[0]%13==v[1]%13)&&(v[2]%13==v[3]%13)&&(v[3]%13==v[4]%13)) sum=(v[2]%13)*13+(v[0]%13); 
    return sum;
}
int three_of_a_kind(vector<int> &v)
{
    int sum=0;
    if((v[0]%13==v[1]%13)&&(v[1]%13==v[2]%13)) sum=(v[0]%13)*13*13+(v[4]%13)*13+v[3]%13; 
    else if((v[1]%13==v[2]%13)&&(v[2]%13==v[3]%13)) sum=(v[1]%13)*13*13+(v[4]%13)*13+v[0]%13; 
    else if((v[2]%13==v[3]%13)&&(v[3]%13==v[4]%13)) sum=(v[2]%13)*13*13+(v[1]%13)*13+v[0]%13; 
    return sum;
}
int four_of_a_kind(vector<int> &v)
{
    if(v[0]%13==v[3]%13) return (v[0]%13)*13+(v[4]%13);
    else if(v[1]%13==v[4]%13) return (v[1]%13)*13+(v[0]%13);
    return 0;
}
int straight_flush(vector<int> &v)
{
    if(flush(v)) return straight(v);
    return 0;
}
int poker(vector<int> &v1,vector<int> &v2)
{
    int x,y;
    x=straight_flush(v1); y=straight_flush(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=four_of_a_kind(v1); y=four_of_a_kind(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=full_house(v1); y=full_house(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=flush(v1); y=flush(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=straight(v1); y=straight(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=three_of_a_kind(v1); y=three_of_a_kind(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=two_pairs(v1); y=two_pairs(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=one_pair(v1); y=one_pair(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    x=high_card(v1); y=high_card(v2); if(x!=y) return x>y?1:-1; else if(x) return 0;
    return 0;
}
bool cmp(int x,int y)
{
    return x%13<y%13;
}
int alice[2],bob[2];
int community[6];
int dp[(1<<6)][(1<<6)];
int get_ans(int mask1,int mask2)
{
    vector<int> v1,v2;
    v1.push_back(alice[0]); v1.push_back(alice[1]);
    v2.push_back(bob[0]); v2.push_back(bob[1]);
    for(int i=0;i<6;i++) if(mask1&(1<<i)) v1.push_back(community[i]); else v2.push_back(community[i]);
    sort(v1.begin(),v1.end(),cmp); sort(v2.begin(),v2.end(),cmp);
    return poker(v1,v2);
}
int solve(int mask1,int mask2)
{
    if(dp[mask1][mask2]!=-2) return dp[mask1][mask2];
    int cnt=__builtin_popcount(mask1)+__builtin_popcount(mask2);
    if(cnt==6) return dp[mask1][mask2]=get_ans(mask1,mask2);
    if(cnt&1)
    {
        int res=1;
        for(int i=0;i<6;i++) 
        {
            if((mask1&(1<<i))||(mask2&(1<<i))) continue;
            res=min(res,solve(mask1,mask2^(1<<i)));
        }
        return dp[mask1][mask2]=res;
    }
    else
    {
        int res=-1;
        for(int i=0;i<6;i++) 
        {
            if((mask1&(1<<i))||(mask2&(1<<i))) continue;
            res=max(res,solve(mask1^(1<<i),mask2));
        }
        return dp[mask1][mask2]=res;
    }
}
int main()
{
    suit['S']=0; suit['H']=1; suit['C']=2; suit['D']=3;
    for(int i=2;i<=9;i++) rank[(char)('0'+i)]=i-2;
    rank['T']=8; rank['J']=9; rank['Q']=10; rank['K']=11; rank['A']=12;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<(1<<6);i++)
        {
            if(__builtin_popcount(i)>3) continue;
            for(int j=0;j<(1<<6);j++)
                dp[i][j]=-2;
        }
        for(int i=0;i<2;i++) alice[i]=read_card();
        for(int i=0;i<2;i++) bob[i]=read_card();
        for(int i=0;i<6;i++) community[i]=read_card();
        int ans=solve(0,0);
        if(ans==1) puts("Alice"); else if(ans==-1) puts("Bob"); else puts("Draw");
    }
    return 0;
}

