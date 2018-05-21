#include<bits/stdc++.h>
#define MAXN 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int b[8400000];
struct SplitMix64 
{
    unsigned long long nextInt() 
    {
        unsigned long long z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }
    
    int random() {
        return 1 + (nextInt() >> 33);
    }
    
    unsigned long long x;
};
int N, M, Q,h,len; 


void init(const vector< vector<int> >& A) 
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            b[i|j]^=A[i][j];
    len=0;
    h=1; while(h<((N-1)|(M-1))) h*=2,len++;
    for(int i=1;i<=len;i++)
    {
        int s=1<<i;
        for(int j=0;j<h/s;j++)
            for(int k=0;k<s/2;k++)
                b[j*s+k+s/2]^=b[j*s+k];
    }
}
int query(int K,const vector< vector<int> >& A) 
{
    return b[K%h];
}

int main() {
    SplitMix64 rng;
    
    cin >> N >> M >> Q >> rng.x;

    
    vector< vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rng.random();
        }
    }
    init(A);
    unsigned long long hashSol = 0;
    
    for (int i = 1; i <= Q; i++) {
        hashSol ^= (unsigned long long)i * query(rng.random(),A);
    }
    
    cout << hashSol << endl;
}