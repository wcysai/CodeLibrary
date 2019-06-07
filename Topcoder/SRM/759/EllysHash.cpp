#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000000000037LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<ll> lhash,rhash;
string x,y,z;
ll get_hash(ll hsh,char ch)
{
    return (hsh*127+(int)ch)%MOD;
}
void dfs(int now,int ed,ll hsh,vector<ll> &save)
{
    if(now==ed)
    {
        save.push_back(hsh);
        return;
    }
    dfs(now+1,ed,get_hash(hsh,x[now]),save);
    dfs(now+1,ed,get_hash(hsh,y[now]),save);
    dfs(now+1,ed,get_hash(hsh,z[now]),save);
}
class EllysHash {
	public:
	long long getHash(int N, string A, string B, string C) {
        x=A; y=B; z=C;
        lhash.clear(); rhash.clear();
        dfs(0,(N+1)/2,0,lhash); 
        dfs((N+1)/2,N,0,rhash);
        sort(lhash.begin(),lhash.end()); lhash.erase(unique(lhash.begin(),lhash.end()),lhash.end());
		sort(rhash.begin(),rhash.end()); rhash.erase(unique(rhash.begin(),rhash.end()),rhash.end());
        int len=N-(N+1)/2;
        ll ans=MOD;
        for(auto x:lhash)
        {
            ll res=x;
            for(int i=0;i<len;i++) res=res*127%MOD;
            if((res+rhash[0])%MOD<ans) ans=(res+rhash[0])%MOD;
            auto it=upper_bound(rhash.begin(),rhash.end(),MOD-res);
            if(it!=rhash.end())
                if((res+*it)%MOD<ans) ans=(res+*it)%MOD;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int N                     = 4;
			string A                  = "ELLY";
			string B                  = "KRIS";
			string C                  = "STAN";
			long long expected__      = 142572564;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 11;
			string A                  = "TOPCODERSRM";
			string B                  = "INTHEMIDDLE";
			string C                  = "OFTHEDAYNOO";
			long long expected__      = 2840613885160LL;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 18;
			string A                  = "EVERYSTEPTHATITAKE";
			string B                  = "ISANOTHERMISTAKETO";
			string C                  = "YOOOOOOOOOOOOOOOOO";
			long long expected__      = 325013178;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 28;
			string A                  = "ANDNEVERMINDTHENOISEYOUHEARD";
			string B                  = "ITSJUSTTHEBEASTSUNDERYOURBED";
			string C                  = "INYOURCLOSETINYOURHEAAAAAAAD";
			long long expected__      = 745;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string A                  = ;
			string B                  = ;
			string C                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			string A                  = ;
			string B                  = ;
			string C                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string A                  = ;
			string B                  = ;
			string C                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = EllysHash().getHash(N, A, B, C);
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
