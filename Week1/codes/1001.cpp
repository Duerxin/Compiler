#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int testCase;
	cin >> testCase;
	set<string> outSet;
	for (int i = 0; i < testCase; ++i)
	{
		set<char> v;
		string in;
		cin >> in;
		for (int i = 0; i < in.size(); ++i)
			v.insert(in[i]);
		string outString = "";
		for (set<char>::iterator iter = v.begin(); iter != v.end(); iter++)
			outString +=  *iter;
		if (! outSet.count(outString))
		{
			if (! outSet.empty())
				cout << endl;
			cout << outString;
			outSet.insert(outString);
		}
	}
	return 0;
}