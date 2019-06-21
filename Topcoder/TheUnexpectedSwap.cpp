#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int A[MAXN],N[MAXN];
int res[MAXN],sum;
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
class TheUnexpectedSwap {
	public:
	int findExpectedResult(int digits, string prefN, int seed) {
        int preflen=(int)prefN.size();
		A[0]=seed;
        for(int i=1;i<digits;i++) A[i]=(1009LL*A[i-1]+10009)%100019;
        for(int i=0;i<preflen;i++) N[i]=prefN[i]-'0';
        for(int i=preflen;i<digits;i++) N[i]=N[A[i]%i];
        res[0]=1;
        sum=N[0];
        for(int i=1;i<digits;i++)
        {
            res[i]=10LL*res[i-1]%MOD;
            add(sum,N[i]);
        }
        int ans=0;
        for(int i=0;i<digits;i++)
        {
            int ret=1LL*(digits-1)*(digits-2)%MOD*N[digits-1-i]%MOD*res[i]%MOD;
            add(ans,ret);
            int val=sum; dec(val,N[digits-1-i]);
            ret=2LL*res[i]*val%MOD;
            add(ans,ret);
        }
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
			int digits                = 2;
			string prefN              = "32";
			int seed                  = 0;
			int expected__            = 46;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int digits                = 2;
			string prefN              = "60";
			int seed                  = 0;
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int digits                = 10;
			string prefN              = "1";
			int seed                  = 0;
			int expected__            = 999999297;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int digits                = 6;
			string prefN              = "123";
			int seed                  = 47;
			int expected__            = 5331084;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int digits                = ;
			string prefN              = ;
			int seed                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int digits                = ;
			string prefN              = ;
			int seed                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int digits                = ;
			string prefN              = ;
			int seed                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheUnexpectedSwap().findExpectedResult(digits, prefN, seed);
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
