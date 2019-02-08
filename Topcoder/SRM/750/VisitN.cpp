#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 30
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class VisitN {
    public:
    bool vis[MAXN][MAXN];
    int rr,cc,cnt;
    string str;
    void go(int dir)
    {
        if(dir==0) {rr++; str+="N";}
        else if(dir==1) {rr--; str+="S";}
        else if(dir==2) {cc++; str+="E";}
        else {cc--; str+="W";}
        if(!vis[rr][cc]) cnt++;
        vis[rr][cc]=true;
    }
	string visit(int n, int r, int c) 
    {
        memset(vis,false,sizeof(vis));
        rr=r;cc=c;
        vis[rr][cc]=true;
	    cnt=1;
        str="";
        bool f=false;
        while(cnt<n)
        {
            if(rr==0&&cc==0) f=true;
            if(!f)
            {
                if(rr>0) go(1);
                else go(3);
            }
            else
            {
                if(rr%2==0)
                {
                    if(cc==29) go(0);
                    else go(2);
                }
                else
                {
                    if(cc==0) go(0);
                    else go(3);
                }
            }
        }
        return str;
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
			int n                     = 1;
			int r                     = 4;
			int c                     = 7;
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int r                     = 4;
			int c                     = 7;
			string expected__         = "N";

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 2;
			int r                     = 0;
			int c                     = 17;
			string expected__         = "W";

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 4;
			int r                     = 1;
			int c                     = 1;
			string expected__         = "NWEE";

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 10;
			int r                     = 5;
			int c                     = 13;
			string expected__         = "NWSSEENNSSWS";

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int r                     = ;
			int c                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int r                     = ;
			int c                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int r                     = ;
			int c                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = VisitN().visit(n, r, c);
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
