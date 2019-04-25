#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int notes[]={50000,20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1};
class NewBanknote {
	public:
    int find_ans(int val)
    {
        int ret=0;
        for(int i=0;i<15;i++)
        {
            ret+=val/notes[i];
            val-=val/notes[i]*notes[i];
        }
        return ret;
    }
	vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay) 
    {
        vector<int> v; v.clear();
        for(int i=0;i<(int)amountsToPay.size();i++)
        {
            int ans=INF;
            for(int j=0;j<50000;j++)
            {
                if(1LL*j*newBanknote>amountsToPay[i]) continue;
                ans=min(ans,find_ans(amountsToPay[i]-1LL*j*newBanknote)+j);
            }
            v.push_back(ans);
        }
		return v;
	}
};


// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]

// Powered by CodeProcessor
