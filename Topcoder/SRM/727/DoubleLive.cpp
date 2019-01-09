#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int inv[MAXN],dp[6005][2005][1][2];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}

class DoubleLive 
{
    public:
    int findEV(int B, int H, int T) 
    {
        for(int i=1;i<=B+H;i++) inv[i]=pow_mod(i,MOD-2);
        memset(dp,0,sizeof(dp));
        int sum=2*B+H;
        dp[H][B][0][1]=1;
        for(int i=0;i<T;i++)
        {
            int cursum=sum-i;
            for(int j=0;2*j<=cursum;j++)
            {
                int k=cursum-2*j;
                if(dp[k][j][0][1])
                {
                    int res=dp[k][j][0][1];
                    if(k>0) add(dp[k-1][j][0][1],1LL*res*(k-1)%MOD*inv[j+k]%MOD);
                    if(j>0) 
                    {
                        add(dp[k+1][j-1][0][1],1LL*res*(j-1)%MOD*inv[j+k]%MOD);
                        add(dp[k+1][j-1][0][0],1LL*res*inv[j+k]%MOD);
                    }
                }
                if(dp[k][j][0][0])
                {
                    int res=dp[k][j][0][0];
                    if(k>1) add(dp[k-1][j][0][0],1LL*res*(k-2)%MOD*inv[j+k]%MOD);
                    if(j>0) add(dp[k+1][j-1][0][0],1LL*res*j%MOD*inv[j+k]%MOD);
                }
            }
        }
        int ans=0;
        for(int i=0;2*i<=2*B+H-T;i++)
        {
            int j=2*B+H-T-2*i;
            add(ans,1LL*(i+j)*dp[j][i][0][0]%MOD);
            add(ans,1LL*(i+j)*dp[j][i][0][1]%MOD);
        }
        ans=1LL*ans*B%MOD*H%MOD;
        return ans;
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
			int B                     = 4;
			int H                     = 3;
			int T                     = 1;
			int expected__            = 571428644;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int B                     = 3;
			int H                     = 10;
			int T                     = 0;
			int expected__            = 390;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int B                     = 1;
			int H                     = 2;
			int T                     = 2;
			int expected__            = 111111113;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int B                     = 1;
			int H                     = 1;
			int T                     = 1;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int B                     = 1;
			int H                     = 1;
			int T                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int B                     = 3;
			int H                     = 10;
			int T                     = 16;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int B                     = 5;
			int H                     = 2;
			int T                     = 5;
			int expected__            = 519487272;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int B                     = 1807;
			int H                     = 1234;
			int T                     = 4040;
			int expected__            = 373880953;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int B                     = ;
			int H                     = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int B                     = ;
			int H                     = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int B                     = ;
			int H                     = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DoubleLive().findEV(B, H, T);
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
