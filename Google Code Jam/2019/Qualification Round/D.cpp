#include<bits/stdc++.h>
#define MAXN 1025
#define MAXK 200
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,B,F;
vector<int> ans;
string str;
struct interval
{
    int l,r,broken;
    bool done;
};
vector<interval> intervals,dummy;
bool get_query(interval &x,bool get_id=false)
{
    int l=x.l,r=x.r,num=x.broken;
    if(num==r-l+1)
    {
        for(int i=0;i<r-l+1;i++) str+="0";
        if(get_id) for(int i=l;i<=r;i++) ans.push_back(i);
        x.done=true;
        return true;
    }
    if(num==0) 
    {
        for(int i=0;i<r-l+1;i++) str+="1";
        x.done=true;
        return true;
    }
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++) str+="1";
    for(int i=mid+1;i<=r;i++) str+="0";
    return false;
}
void construct_query(bool get_id=false)
{
    for(auto &x:intervals) get_query(x,get_id);
}
void parse_string(string str)
{
    dummy.clear();
    int now=0;
    for(auto x:intervals)
    {
        int l=x.l,r=x.r,num=x.broken;
        int has=r-l+1-num,tmp=0;
        if(x.done) {now+=has; dummy.push_back(x); continue;}
        int mid=(l+r)/2;
        int ori=mid-l+1;
        for(int j=now;j<now+has;j++) if(str[j]=='1') tmp++;
        now+=has;
        dummy.push_back((interval){l,mid,ori-tmp,false}); dummy.push_back((interval){mid+1,r,num-(ori-tmp),false});
    }
    intervals=dummy;
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        intervals.clear(); ans.clear();
        scanf("%d%d%d",&N,&B,&F);
        for(int i=0;i<N;i++) if((i/16)&1) printf("0"); else printf("1");
        printf("\n");
        fflush(stdout);
        cin>>str;
        int last=0,tot=0;
        for(int i=0;i<N-B;i++)
        {
            if(i!=0&&str[i]!=str[i-1])
            {
                intervals.push_back((interval){tot*16,min((tot+1)*16-1,N-1),16-(i-last),false});
                tot++;
                last=i;
            }
        }
        if(tot==(N-1)/16)
        {
            intervals.push_back((interval){tot*16,min((tot+1)*16-1,N-1),(N%16==0?16:N%16)-(N-B-last),false});
        }
        else
        {
            intervals.push_back((interval){tot*16,min((tot+1)*16-1,N-1),16-(N-B-last),false});
            intervals.push_back((interval){(tot+1)*16,N-1,N%16,false});
        }
        //for(auto x:intervals) printf("%d %d %d %d\n",x.l,x.r,x.broken,x.done);
        for(int j=0;j<4;j++)
        {
            str="";
            construct_query();
            cout<<str<<endl; fflush(stdout);
            cin>>str;
            parse_string(str);
            //for(auto x:intervals) printf("%d %d %d %d\n",x.l,x.r,x.broken,x.done);
        }
        construct_query(true);
        for(auto id:ans) printf("%d ",id);
        printf("\n");
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        assert(ret==1);
    }
    return 0;
}
