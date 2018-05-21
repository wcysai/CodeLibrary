#include<stdio.h>
typedef long long ll;
	ll gcd(ll i,ll j)
	{
		if(j==0)return i;
		return gcd(j,i%j);
	}
	void extgcd(ll a, ll b, ll& f, ll&g) 
	{               
    if (b!=0) 
     	{    
		 extgcd(b, a%b, g, f); 
         g-=(a/b)*f; 
         } 
       else 
       {     f=1; g=0;    }           
	}
	
	ll getinv(ll k, ll M)
	{
		ll p, q;
		extgcd(k, M, p, q);
		if(p < 0) p = M - ((-p) % M);
		else p = p % M;
		return p;
	}
ll x,y,m,n,l,s,a,b,c;
int main()
{	

	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	a=n-m;
	c=x-y;                                        
	if(a < 0) a = l - ((-a) % l);
	if(c < 0) c = l - ((-c) % l);
	ll g = gcd(a, l);
	if(c % g == 0){
		a /= g; c /= g; l /= g;
		ll p = getinv(a, l);
		s = (c * p) % l;
		printf("%lld\n", s);
	}else{
		printf("Impossible\n");
	}
	return 0;
}