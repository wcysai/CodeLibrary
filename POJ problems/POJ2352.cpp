#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 32005;

int c[MAXN],level[MAXN],n;

int lowbit(int x){return x & (-x);}

// 求前n项的和
int sum(int n){
    int sum = 0;
    while(n > 0){
        sum += c[n];
        n -= lowbit(n);
    }
    return sum;
}
// 增加某个元素的大小
void add(int x){
    while(x <= MAXN){
        ++c[x];
        x += lowbit(x);
    }
}

int main(){
    int n,x,y;
    while(~scanf("%d",&n)){
        memset(level, 0, sizeof(level));
        memset(c, 0, sizeof(c));
        for(int i=0; i<n; ++i) {
            scanf("%d%d",&x,&y);
            ++x;
            level[sum(x)]++;
            add(x);
        }
        for(int i=0; i<n; ++i)
            printf("%d\n",level[i]);
    }
    return 0;
}