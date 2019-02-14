#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int f[MAXN],g[MAXN];
int S[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
class CountTables {
	public:
	int howMany(int N, int M, int C) 
    {
        memset(S,0,sizeof(S));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
		S[0][0]=1;
        for(int i=1;i<=M;i++)
            for(int j=1;j<=i;j++)
            {
                S[i][j]=S[i-1][j-1];
                add(S[i][j],1LL*S[i-1][j]*j%MOD);
            }
        for(int i=1;i<=M;i++)
        {
            int s=pow_mod(C,i);
            f[i]=1;
            for(int j=1;j<=N;j++)
            {
                f[i]=1LL*f[i]*s%MOD;
                dec(s,1);
            }
        }
        for(int i=1;i<=M;i++)
        {
            g[i]=f[i];
            for(int j=1;j<i;j++) dec(g[i],1LL*S[i][j]*g[j]%MOD);
        }
        return g[M];
	}
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 2;
			int M                     = 2;
			int C                     = 2;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1;
			int M                     = 1;
			int C                     = 4000;
			int expected__            = 4000;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int M                     = 3;
			int C                     = 5;
			int expected__            = 13740;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 4000;
			int M                     = 1;
			int C                     = 4000;
			int expected__            = 593395757;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 5;
			int M                     = 5;
			int C                     = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 4000;
			int M                     = 4000;
			int C                     = 4000;
			int expected__            = 237003303;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			int C                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int C                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int C                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountTables().howMany(N, M, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
