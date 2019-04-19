#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int m,save=0;
mat a[5];
mat one,two,three,four;
mat optone,opttwo,optthree,optfour;
bool cmp(vec &x,vec &y)
{
    return x.back()>y.back();
}
int main()
{
    freopen("tickets.in","r",stdin);
    freopen("tickets.out","w",stdout);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        vector<int> v; v.clear();
        for(int j=0;j<x;j++)
        {
            int p;scanf("%d",&p);
            v.push_back(p);
        }
        v.push_back(y);
        a[x].push_back(v);
    }
    int ans=-1;
    int sz1=(int)a[3].size(),sz2=(int)a[4].size();
    for(int mask1=0;mask1<(1<<sz1);mask1++)
        for(int mask2=0;mask2<(1<<sz2);mask2++)
        {
            one.clear(); two.clear(); three.clear(); four.clear();
            int cnt2=(int)a[2].size(),cnt3=0,cnt4=0,res=0;
            for(int i=0;i<(int)a[1].size();i++) one.push_back(a[1][i]);
            two.clear();
            for(int i=0;i<(int)a[2].size();i++)
            {
                two.push_back(a[2][i]);
                res+=2*a[2][i][2];
            }
            for(int i=0;i<sz1;i++) 
            {
                if(mask1&(1<<i)) {cnt3++; res+=6*a[3][i][3]; three.push_back(a[3][i]);}
                else {cnt2++; res+=2*a[3][i][3]; two.push_back((vec){a[3][i][0],a[3][i][1],a[3][i][3]}); one.push_back((vec){a[3][i][2],a[3][i][3]});}
            }
            for(int i=0;i<sz2;i++)
            {
                if(mask2&(1<<i)) {cnt4++; res+=12*a[4][i][4]; four.push_back(a[4][i]);}
                else {cnt2+=2; res+=4*a[4][i][4]; two.push_back((vec){a[4][i][0],a[4][i][1],a[4][i][4]}); two.push_back((vec){a[4][i][2],a[4][i][3],a[4][i][4]});}
            }
            if(cnt4+cnt3>9) continue;
            if(cnt4+cnt3+(cnt2+1)/2>9)
            {
                int need=(cnt2)-(18-2*(cnt3+cnt4));
                sort(two.begin(),two.end(),cmp);
                for(int j=0;j<need;j++)
                {
                    auto x=two.back();
                    res-=2*x[2];
                    one.push_back((vec){x[0],x[2]}); one.push_back((vec){x[1],x[2]});
                    two.pop_back();
                }
            }
            if(res>ans)
            {
                ans=res;
                optone=one;
                opttwo=two;
                optthree=three;
                optfour=four;
            }
        }
    printf("%d\n",ans);
    int cnt=0;
    for(int i=0;i<(int)optfour.size();i++) {printf("%d %d %d %d\n",optfour[i][0],optfour[i][1],optfour[i][2],optfour[i][3]); cnt++;}
    for(int i=0;i<(int)optthree.size();i++)
    {
        printf("%d %d %d ",optthree[i][0],optthree[i][1],optthree[i][2]);
        if(optone.size())
        {
            auto x=optone.back();
            printf("%d\n",x[0]);
            optone.pop_back();
        }
        else printf("0\n");
        cnt++;
    }
    while(opttwo.size())
    {
        if(opttwo.size()==1)
        {
            auto x=opttwo.back(); 
            printf("%d %d ",x[0],x[1]); opttwo.pop_back();
            if(optone.size()) {auto it=optone.back(); printf("%d ",it[0]); optone.pop_back();} else printf("0 ");
            if(optone.size()) {auto it=optone.back(); printf("%d\n",it[0]); optone.pop_back();} else printf("0\n");
        }
        else
        {
            auto x=opttwo.back(); printf("%d %d ",x[0],x[1]); opttwo.pop_back();
            x=opttwo.back(); printf("%d %d\n",x[0],x[1]); opttwo.pop_back();
        }
        cnt++;
    }
    while(optone.size())
    {
        if(optone.size()) {auto it=optone.back(); printf("%d ",it[0]); optone.pop_back();} else printf("0 ");
        if(optone.size()) {auto it=optone.back(); printf("%d ",it[0]); optone.pop_back();} else printf("0 ");
        if(optone.size()) {auto it=optone.back(); printf("%d ",it[0]); optone.pop_back();} else printf("0 ");
        if(optone.size()) {auto it=optone.back(); printf("%d\n",it[0]); optone.pop_back();} else printf("0\n");
        cnt++;
    }
    for(int i=0;i<9-cnt;i++) printf("%d %d %d %d\n",0,0,0,0);
    return 0;
}
