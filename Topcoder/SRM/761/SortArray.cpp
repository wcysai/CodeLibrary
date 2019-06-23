#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool issorted(int N,vector<int> &a)
{
    for(int i=1;i<N;i++) if(a[i]<a[i-1]) return false;
    return true;
}
bool check(int N,vector<int> a,vector<int> &commands)
{
    for(int i=0;i<(int)commands.size();i++)
    {
        int mask=commands[i];
        int cnt=0;
        for(int j=0;j<N;j++)
        {
            if(!(mask&(1<<j))) continue;
            if(!a[j]) cnt++;    
        }
        int tot=0;
        for(int j=0;j<N;j++)
        {
            if(!(mask&(1<<j))) continue;
            if(tot<cnt) a[j]=0; else a[j]=1;
            tot++;
        }
    }
    return !issorted(N,a);
}
vector<int> construct(int N,vector<int> &tmp)
{
    int cnt=0,tot=0;
    for(int i=0;i<N;i++) if(!tmp[i]) cnt++;
    vector<int> ret; ret.clear();
    for(int i=0;i<N;i++)
    {
        if(!tmp[i]) ret.push_back(tot++);
        else ret.push_back(cnt++);
    }
    return ret;
}
class SortArray {
  public:
  vector <int> verify(int N, vector <int> commands) {
      vector<int> tmp;
      for(int mask=0;mask<(1<<N);mask++)      
      {
          tmp.clear();
          for(int i=0;i<N;i++) if(mask&(1<<i)) tmp.push_back(1); else tmp.push_back(0);
          if(check(N,tmp,commands)) 
          {
              return construct(N,tmp);
          }
      }
      return vector<int>();
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
			int N                     = 7;
			int commands[]            = {127};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 8;
			int commands[]            = {85, 170};
			int expected__[]          = {0, 1, 2, 3, 4, 5, 7, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int commands[]            = {3, 5, 6};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int commands[]            = {255, 1020};
			int expected__[]          = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int N                     = 10;
			int commands[]            = {255, 1020, 255, 1020, 255, 1020, 255, 1020, 255, 1020};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int commands[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int commands[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int commands[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SortArray().verify(N, vector <int>(commands, commands + (sizeof commands / sizeof commands[0])));
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
