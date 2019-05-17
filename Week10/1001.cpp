#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <unistd.h>
using namespace std;

struct Vns_Struct { int Nv; string VN[10];} Vns;
struct Vts_Struct { int Nt; string VT[10];} Vts;
struct ps_Struct { int Np; string PL[20], PR[20];} ps;
string S;
string allSymbol = "";


int findIndex(char tofind)
{
	for (int i = 0; i < allSymbol.length(); ++i)
		if (tofind == allSymbol[i])
			return i;

	return -1;
}

int main(int argc, char const *argv[])
{

	// Begin Symbol
	cin >> S;

	// Begin Nonterminal
	cin >> Vns.Nv;
	std::vector<string> out[Vns.Nv];
	for (int i = 0; i < Vns.Nv; ++i)
	{
		cin >> Vns.VN[i];
		allSymbol = allSymbol + Vns.VN[i];
	}

	// Begin Terminal
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
	{
		cin >> Vts.VT[i];
		allSymbol = allSymbol + Vts.VT[i];
	}

	// Begin Production
	cin >> ps.Np;
	int temp;
	for (int i = 0; i < ps.Np; ++i)
		cin >> temp >> ps.PL[i] >> ps.PR[i];

	int total = Vns.Nv + Vts.Nt;


	// M[R]
	int m[total][total];

	cin >> temp;
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			cin >> m[i][j];

	string expression;
	cin >> expression;

	string done, nodone = expression.substr(0, expression.length() - 1);
	int pointer = 0;
	while (done != S || nodone != "")
	{
		cout << "#" << done << " & " << nodone << "#" << endl;
		if ((done.length() && m[findIndex(done[done.length() - 1])][findIndex(nodone[0])] > 2) || nodone == "")
		{
			// cout << m[findIndex(done[done.length() - 1])][findIndex(nodone[0])] << endl;
			// cout << "replace" << endl;
			string toTake = "", toTakeR = "";
			for (int i = 0; i < ps.Np; ++i)
			{
				int len = ps.PR[i].length();
				if (done.length() >= len && ps.PR[i] == done.substr(done.length() - len, done.length() ))
				{
					if (len > toTakeR.length())
					{
						toTake = ps.PL[i];
						toTakeR = ps.PR[i];
					}
				}
			}
			// cout << toTake << "  " << toTakeR <<endl;
			done.replace(done.length() - toTakeR.length(), toTakeR.length(), toTake);
		}
		else
		{
			done = done + nodone[0];
			nodone = nodone.substr(1, nodone.length());
		}
		// usleep(100000);
	}
	cout << "#" << done << " & " << nodone << "#" << endl;
	return 0;
}