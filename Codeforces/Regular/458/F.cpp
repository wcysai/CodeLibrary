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
int n,q;
string str;
bitset<100005> bs[27];
int main()
{
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
        bs[str[i]-'a'].set(i);
    scanf("%d",&q);
    while(q--)
    {
        int type,i,l,r;
        string c,y;
        cin>>type;
        if(type==1)
        {
            cin>>i>>c; i--;
            bs[str[i]-'a'].reset(i);
            str[i]=c[0];
            bs[str[i]-'a'].set(i);
        }
        else
        {
            cin>>l>>r>>y; l--; r--;
            if(r-l+1<(int)y.size()) {puts("0"); continue;}
            bitset<100005> b=bs[y[0]-'a'];
            for(int j=1;j<(int)y.size();j++) b&=(bs[y[j]-'a']>>j);
            int res=(b>>l).count();
            res-=(b>>(r-(int)y.size()+2)).count();
            printf("%d\n",res);
        }
    }
    return 0;
}

