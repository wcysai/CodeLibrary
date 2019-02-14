#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int s[MAXN][MAXM],S[MAXN][MAXM],fact[MAXM];
class CyclesNumber {
	public:
    void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
	vector <int> getExpectation(vector <int> n, vector <int> m) {
		s[0][0]=1;S[0][0]=1;fact[0]=1;
        for(int i=1;i<=301;i++) fact[i]=1LL*fact[i-1]*i%MOD;
        for(int i=1;i<=100001;i++)
            for(int j=1;j<=min(i,301);j++)
            {
                s[i][j]=s[i-1][j-1];add(s[i][j],1LL*s[i-1][j]*(i-1)%MOD);
                S[i][j]=S[i-1][j-1];add(S[i][j],1LL*S[i-1][j]*j%MOD);
            }
        vector<int> ans;
        for(int i=0;i<(int)n.size();i++) 
        {
            int res=0;
            for(int k=0;k<=m[i];k++) add(res,1LL*s[n[i]+1][k+1]*fact[k]%MOD*S[m[i]][k]%MOD);
            ans.push_back(res);
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int n[]                   = {2};
			int m[]                   = {2};
			int expected__[]          = {5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n[]                   = {3};
			int m[]                   = {0};
			int expected__[]          = {6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n[]                   = {1, 2, 3};
			int m[]                   = {1, 3, 3};
			int expected__[]          = {1, 9, 53 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n[]                   = {10, 20, 30};
			int m[]                   = {10, 20, 30};
			int expected__[]          = {586836447, 544389755, 327675273 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n[]                   = ;
			int m[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int n[]                   = ;
			int m[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int n[]                   = ;
			int m[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CyclesNumber().getExpectation(vector <int>(n, n + (sizeof n / sizeof n[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
