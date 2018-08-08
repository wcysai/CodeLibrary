//
// Created by calabash_boy on 18-8-8.
//
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5+100;
LL a[maxn],b[maxn*3];
#define FI(n) FastIO::read(n)
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;
 
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};
int T,n,L;
LL calc(int st){
    LL ret =0;
    for (int i=1;i<=n;i++){
        ret +=max(a[i]-b[st+i-1],b[st+i-1]-a[i]);
    }
    return ret;
}
LL x;
void solve(){
    FI(n);FI(L);
    for (int i=1;i<=n;i++)
    {
        FI(x);
        a[i]=x;
    }
    // sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        FI(x); 
        FI(b[n+i]);
    }
    // sort(b+n+1,b+n+n+1);
    for (int i=1;i<=n;i++){
        b[i] = b[n+i]-L;
        b[2*n+i] = b[n+i]+ L;
    }
    int l = 1,r = 2*n+1;
    while (r-l>=3){
        int lmid = l+(r-l)/3;
        int rmid = r-(r-l)/3;
        LL ansl = calc(lmid);
        LL ansr = calc(rmid);
        if (ansl<ansr){
            r = rmid;
        }else{
            l = lmid;
        }
    }
    LL ans = 0x3f3f3f3f3f3f3f3fLL;
    for (int i=l;i<=r;i++){
        ans = min(ans,calc(i));
    }
    printf("%lld\n",ans);
}
int main(){
    for (T = read();T;T--){
        solve();
    }
    return 0;
}
