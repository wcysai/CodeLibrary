#include <bits/stdc++.h>
#define rank rkrkrk
//#define _DEBUG
#define RMQ
using namespace std;
const int maxn = 5e5+100;
struct SA{
#ifndef RMQ
    struct Segment_Tree{
        int min_val[maxn*4];
        void up(int x){
            min_val[x] = min(min_val[x<<1],min_val[x<<1|1]);
        }
        void build(int x,int l,int r,int*h){
            if (l == r){
                min_val[x] = h[l];
                return;
            }
            int mid = l + r >>1;
            build(x<<1,l,mid,h);
            build(x<<1|1,mid+1,r,h);
            up(x);
        }
        int query(int x,int l,int r,int L,int R){
            if (l > R || L > r)return 0x3f3f3f3f;
            if (L<= l && r <= R)return min_val[x];
            int mid = l + r >> 1;
            return min(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
        }
    }segtree;
#else
    int st[maxn][20];
    void st_init(int n,int*h){
        for (int i=1;i<=n;i++){
            st[i][0] = h[i];
        }
        for (int j=1;(1<<j)<=n;j++){
            for (int i=1;i<=n-(1<<j)+1;i++){
                st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
#endif
    int cntA[maxn],cntB[maxn],tsa[maxn],A[maxn],B[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    void get_sa(char * ch,int n){
        ch[0] = ch[n+1] = -1;
        for (int i=0;i<=n;i++)cntA[i] = 0;
        for (int i=1;i<=n;i++)cntA[ch[i]]++;
        for (int i=1;i<maxn;i++)cntA[i] += cntA[i-1];
        for (int i=maxn-1;i>=1;i--)sa[cntA[ch[i]]--] = i;
        rank[sa[1]] = 1;
        for (int i=2;i<=n;i++){
            rank[sa[i]] = rank[sa[i-1]];
            if (ch[sa[i]] != ch[sa[i-1]])rank[sa[i]] ++;
        }
        for (int l=1;rank[sa[n]]<n;l<<=1){
            for (int i=0;i<=n;i++)cntA[i] = cntB[i] = 0;
            for (int i=1;i<=n;i++){
                cntA[A[i] = rank[i]] ++;
                cntB[B[i]=(i+l<=n)?rank[i+l]:0]++;
            }
            for (int i=1;i<=n;i++)cntB[i] += cntB[i-1];
            for (int i=n;i>=1;i--)tsa[cntB[B[i]]--] = i;
            for (int i=1;i<=n;i++)cntA[i] += cntA[i-1];
            for (int i=n;i>=1;i--)sa[cntA[A[tsa[i]]]--] = tsa[i];
            rank[sa[1]] = 1;
            for (int i=2;i<=n;i++){
                rank[sa[i]] = rank[sa[i-1]];
                if (A[sa[i]] != A[sa[i-1]] || B[sa[i]] != B[sa[i-1]])rank[sa[i]] ++;
            }
        }
    }
    void get_height(char *ch,int n){
        get_sa(ch,n);
        sa[0] = rank[0] = 0;
        for (int i=1,j=0;i<=n;i++){
            if (j) j--;
            while (ch[i+j] == ch[sa[rank[i]-1]+j])j++;
            height[rank[i]] = j;
        }
#ifdef _DEBUG
        for (int i=1;i<=n;i++){
            printf("sa[%d]=%d\n",i,sa[i]);
            printf("rank[%d]=%d\n",i,rank[i]);
//            printf("height[%d]=%d\n",i,height[i]);
        }
#endif
#ifndef RMQ
        segtree.build(1,1,n,height);
#else
        st_init(n,height);
#endif
    }
    int get_lcp(int rkx,int rky,int n){
        if (rkx>rky)swap(rkx,rky);
        rkx++;
#ifndef RMQ
        int lcp = segtree.query(1,1,n,rkx,rky);
#else
        int k = log2(rky - rkx+1);
        int lcp = min(st[rkx][k],st[rky - (1<<k)+1][k]);
#endif

#ifdef _DEBUG
        printf("[get_lcp]rkx=%d,rky=%d,lcp =%d\n",rkx,rky,lcp);
#endif
        return lcp;
    }
}sa;
char s[maxn];
int st[maxn];
int min_pos[maxn];

int main(){
    int q;
    scanf("%d",&q);
    scanf("%s",s+1);
    int LEN = strlen(s+1);
    int now = LEN + 1;
    for (int i=1;i<=q;i++){
        st[i] = now;
        scanf("%s",s + now);
        now += strlen(s + now);
    }
    st[q+1] = now;
    now --;
    //puts(s+1);
    sa.get_height(s, now);
    min_pos[now+1] = INT_MAX;

    for (int i=now;i>=1;i--){
        min_pos[i] = min(min_pos[i+1],sa.sa[i]);
    }
    for (int i=1;i<=q;i++){
        int len = st[i+1] - st[i];
        int r = now,l = sa.rank[st[i]] + 1;
        while (r-l > 1){
            int mid = l + r >> 1;
            int lcp = sa.get_lcp(sa.rank[st[i]], mid, now);
            if (lcp >= len){
                l = mid;
            }else{
                r = mid;
            }
        }
        int succ = -1;
        for (int ii=l;ii<=r;ii++){
            if (sa.get_lcp(sa.rank[st[i]], ii, now) < len){
                succ = ii;
                break;
            }
        }
       // printf("[succ]i=%d posx = %d succ=%d\n",i,sa.rank[st[i]],succ);
        if (succ == -1 || LEN - min_pos[succ] + 1< len){
            puts("-1");
        }else{
            printf("%d\n",min_pos[succ]-1);
        }
    }
        return 0;
}
