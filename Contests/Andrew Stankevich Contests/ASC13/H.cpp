#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
db h,r,s;
const db PI=acos(-1.0);
int m;
int main()
{
    freopen("sand.in","r",stdin);
    freopen("sand.out","w",stdout);
    scanf("%Lf%Lf%Lf%d",&h,&r,&s,&m);
    db sand=1.0/3.0*PI*r*r*s*s*s/h/h;
    db rate=sand/m;
    db ratio=sqrt(r*r+h*h)/h;
    for(int i=0;i<m;i++)
    {
        printf("%.20Lf\n",ratio*s);
        sand-=rate;
        s=pow(3*sand*h*h/r/r/PI,1.0/3.0);
    }
    return 0;
}
