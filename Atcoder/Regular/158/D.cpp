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
int T,n,p;
mt19937 wcy(time(NULL));
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%p;
        a=1LL*a*a%p;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&p);
        while(true){
            int x,y,z;
            x=wcy()%(p-1)+1;
            do{
                y=wcy()%(p-1)+1;
            }while(y==x);
            do{
                z=wcy()%(p-1)+1;
            }while(z==x||z==y);
            int l=x; add(l,y); add(l,z);
            if(!l) continue;
            int tx=pow_mod(x,n),ty=pow_mod(y,n),tz=pow_mod(z,n);
            int ttx=1LL*tx*tx%p,tty=1LL*ty*ty%p,ttz=1LL*tz*tz%p;
            int cx=1LL*tx*ttx%p,cy=1LL*ty*tty%p,cz=1LL*tz*ttz%p;
            add(tx,ty); add(tx,tz); add(ttx,tty); add(ttx,ttz);
            add(cx,cy); add(cx,cz);
            if(!tx) continue;
            if(!ttx) continue;
            if(!cx) continue;
            l=1LL*l*tx%p*ttx%p;
            int a=1LL*pow_mod(l,p-2)*cx%p;
            x=1LL*x*a%p; y=1LL*y*a%p; z=1LL*z*a%p;
            if(y>z) swap(y,z);
            if(x>y) swap(x,y);
            if(y>z) swap(y,z);
            printf("%d %d %d\n",x,y,z);
            break;
        }
    }
    return 0;
}

