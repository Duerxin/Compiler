#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	set<char> v;
	string in;
	cin >> in;
	for (int i = 0; i < in.size(); ++i)
	{
		v.insert(in[i]);
	}
	for (set<char>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
	return 0;
}