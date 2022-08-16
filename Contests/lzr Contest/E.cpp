#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,m;
vector<int> v;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&m);
        if(m==1) {printf("1\n1\n"); continue;}
        int now=1,cnt=0;
        while(now*2<=m) now*=2,cnt++;
        v.clear();
        if(m&(1<<(cnt-1)))
        {
            now=102;
            v.push_back(102);
            v.push_back(101);
            v.push_back(1);
        }
        else
        {
            now=101;
            v.push_back(101);
            v.push_back(1);
        }
        int tot=1,counter=1;
        for(int i=0;i<cnt-1;i++)
        {
            if(m&(1<<(cnt-2-i)))
            {
                v.push_back(now+2);
                v.push_back(now+1);
                now+=2;
                for(int i=0;i<counter;i++) v.push_back(++tot);
                counter=1;
            }
            else
            {
                v.push_back(now+2);
                v.push_back(now+1);
                counter++;
                now+=2;
            }
        }
        for(int j=0;j<(int)v.size();j++)
            if(v[j]>=100) v[j]=(tot+1+v[j]-101);
        printf("%d\n",(int)v.size());
        for(auto x:v) printf("%d ",x);
        puts("");
    }
    return 0;
}
