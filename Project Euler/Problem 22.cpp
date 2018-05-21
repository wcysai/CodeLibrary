#include <algorithm>

using namespace std;
using namespace boost;

int worth(string tmp)
{
	int worthOfString =0;
	for(int i=0; i<tmp.length(); i++)
		worthOfString +=int(tmp[i]-64);
	return worthOfString;
}

int main()
{
	int sum =0; 
	vector<string> names;
	vector<string>::iterator iter;
	fstream file("names.txt",ios::in);
	string s;
	getline(file,s);
	file.close();
	tokenizer<> tok(s);
	for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end(); ++beg)
		names.push_back(*beg);
	sort(names.begin(),names.end());
	for(int i=0;i<names.size();i++)
		sum += (i+1)*worth(names[i]);
	cout << sum << endl;
	return0;
}