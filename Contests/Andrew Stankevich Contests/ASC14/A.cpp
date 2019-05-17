#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
//op 0: H 1: V 2:S
int vacant;
int get_id(int mask,int pos)
{
    return pos*(1<<n)+mask+1;
}
int go(int mask,int pos,int op)
{
    int nmask,npos=pos;
    if(mask&(1<<pos))
    {
        if(op==0||op==1) return vacant;
        else 
        {
            npos++; nmask=mask^(1<<pos);
            if(npos==n) npos=0; 
            return get_id(nmask,npos);
        }
    }
    else
    {
        if(op==2) return vacant;
        if(op==1) 
        {
            if(pos==n-1) return vacant;
            if(mask&(1<<(pos+1))) return vacant;
            npos++; nmask=mask^(1<<(pos+1));
            return get_id(nmask,npos);
        }
        else
        {
            npos++; if(npos==n) npos=0;
            nmask=mask^(1<<pos);
            return get_id(nmask,npos);
        }
    }
}
int main()
{
    freopen("automata.in","r",stdin);
    freopen("automata.out","w",stdout);
    scanf("%d",&n); 
    vacant=n*(1<<n)+1;
    printf("%d %d\n",vacant,1);
    printf("%d %d\n",1,1);
    for(int pos=0;pos<n;pos++)
        for(int mask=0;mask<(1<<n);mask++)
            printf("%d %d %d\n",go(mask,pos,0),go(mask,pos,1),go(mask,pos,2));
    printf("%d %d %d\n",vacant,vacant,vacant);
    return 0;
}
