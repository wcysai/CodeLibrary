#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
vector<int> sg[21];
int mex[MAXN];
vector<int> v,tmp;
string str;
//0: II. 1: III
//2: .I. 3: I.I
int trans1(int digit,int mask,int pos)
{
    int d1=pos-1,val1,val2,d2=digit-pos-2;
    if(pos==0) val1=0;
    else if(mask&(1<<(pos-1))) val1=sg[d1][mask&((1<<(pos-1))-1)]^1;
    else val1=sg[d1][mask&((1<<(pos-1))-1)];
    if(pos==digit-1) val2=0;
    else if((mask>>(pos+1))&1) val2=sg[d2][mask>>(pos+2)]^1;
    else val2=sg[d2][mask>>(pos+2)];
    return val1^val2;
}
int trans2(int digit,int mask,int pos)
{
    int d1=pos,val1,d2=digit-pos-1,val2;
    if(pos==0) val1=0; else val1=sg[d1][mask&((1<<pos)-1)];
    if(pos==digit-1) val2=0; else val2=sg[d2][mask>>(pos+1)];
    return val1^val2;
}
int trans3(int digit,int mask,int pos)
{
    return sg[digit][mask^(1<<pos)];
}
int get_id()
{
    cin>>str;
    if(str[0]=='I'&&str[1]=='I'&&str[2]=='I') return 1;
    else if(str[0]=='.'&&str[1]=='I'&&str[2]=='.') return 2;
    else if(str[0]=='I'&&str[1]=='.'&&str[2]=='I') return 3;
    else return 0;
}
int get_val(vector<int> v)
{
    if(v.size()==0) return 0;
    int mask=0;
    for(int i=0;i<(int)v.size();i++) mask=(mask<<1)+v[i];
    return sg[(int)v.size()][mask];
}
int main()
{
    sg[0].resize(10);
    for(int i=1;i<=20;i++)
    {
        sg[i].resize(1<<i);
        memset(mex,-1,sizeof(mex));
        for(int mask=0;mask<(1<<i);mask++)
        {
            for(int j=0;j<i;j++)
            {
                if(!(mask&(1<<j)))
                {
                    mex[trans1(i,mask,j)]=mask;
                }
                else
                {
                    mex[trans2(i,mask,j)]=mask;
                    mex[trans3(i,mask,j)]=mask;
                }
            }
            for(int j=0;;j++)
            {
                if(mex[j]!=mask)
                {
                    sg[i][mask]=j;
                    break;
                }
            }
            //printf("%d %d %d\n",i,mask,sg[i][mask]);
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        v.clear();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=get_id();
            if(x<=1) v.push_back(x);
            else if(x==3)
            {
                ans^=get_val(v);
                v.clear();
            }
            else
            {
                if(v.size()>0)
                {
                    if(v.back()==1) ans^=1;
                    v.pop_back();
                    ans^=get_val(v);
                    v.clear();
                }
                if(i!=n-1)
                {
                    int x=get_id();
                    if(x==1) ans^=1;
                    i++;
                }
            }
        }
        ans^=get_val(v);
        if(ans) puts("First"); else puts("Second");
    }
    return 0;
}
