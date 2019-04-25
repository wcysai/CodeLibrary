#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define BASE 19260817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<string >se;
class CrazyCrazy {
	public:
	string possible(string song) {
        int n=(int)song.size();
        for(int mask=0;mask<(1<<(n/2));mask++)
        {
            string s="",t="";
            for(int i=0;i<n/2;i++)
            {
                if(mask&(1<<i)) s+=song[i];
                    else t+=song[i];
            }
            if(s.size()<t.size()) continue;
            int szs=(int)s.size(),szt=(int)t.size();
            if(s.substr(0,szt)!=t) continue;
            se.insert(s.substr(szt,szs-szt));
        }
        for(int mask=0;mask<(1<<(n/2));mask++)
        {
            string s="",t="";
            for(int i=n/2;i<n;i++)
            {
                if(mask&(1<<(i-n/2))) s+=song[i];
                    else t+=song[i];
            }
            if(s.size()<t.size()) continue;
            int szs=(int)s.size(),szt=(int)t.size();
            if(s.substr(szs-szt,szt)!=t) continue;
            string need=s.substr(0,szs-szt);
            if(se.count(need)) return "possible";
        }
        return "impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string song               = "aabb" ;
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string song               = "abba" ;
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string song               = "verylazyverylazy" ;
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string song               = "arqmpfvvbtltlhufznkldkurrazmgebfxeamrewn" ;
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string song               = "aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll" ;
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string song               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string song               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string song               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CrazyCrazy().possible(song);
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
