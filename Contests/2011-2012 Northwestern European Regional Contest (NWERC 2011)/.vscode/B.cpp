#include<bits/stdc++.h>
#define MAXN 45005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a,b;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d/%d",&a,&b);
        string str="";
        while(a!=1||b!=1)
        {
            if(a>b) {str+="R"; a-=b; swap(a,b);}
            else {str+="L"; swap(a,b); a-=b;}
            int g=__gcd(a,b);
            a/=g; b/=g;
        }
        cout<<str<<endl;
    }
    return 0;
}