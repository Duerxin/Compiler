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
string expression;
string allSymbol = "";

int findIndex(char tofind)
{
	for (int i = 0; i < allSymbol.length(); ++i)
		if (tofind == allSymbol[i])
			return i >= Vns.Nv ? i - Vns.Nv : i + Vts.Nt;

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

	int stateNum, actionNum, gotoNum;
	cin >> stateNum >> actionNum >> gotoNum;
	char stateChar[stateNum][actionNum];
	int stateInt[stateNum][actionNum + gotoNum];

	for (int i = 0; i < stateNum; ++i)
	{
		cin >> temp;
		for (int j = 0; j < actionNum + gotoNum; ++j)
		{
			if (j < actionNum)
			{
				cin >> stateChar[i][j] >> stateInt[i][j];
			}
			else
				cin >> stateInt[i][j];
		}
	}
	cin >> expression;

	string done = "0", nodone = expression;
	cout << "#" << done << " & " << nodone << endl;
	int iX = 0, iY = 0;
	while (1)
	{
		iX = done[done.length() - 1] - '0';
		if (done[done.length() - 2] <= '9' && done[done.length() - 2] >= '0')
			iX += 10 * (done[done.length() - 2] - '0');
		iY = findIndex(nodone[0]);
		if (stateChar[iX][iY] == 'A')
			break;
		else if (stateChar[iX][iY] == 's')
		{
			done = done + nodone[0] + to_string(stateInt[iX][iY]);
			nodone = nodone.substr(1, nodone.length());
		}
		else if (stateChar[iX][iY] == 'r')
		{
			int found = done.find(ps.PR[stateInt[iX][iY]][0]);
			done.replace(done.begin() + found, done.end(), ps.PL[stateInt[iX][iY]]);
			done = done + to_string(stateInt[done[done.length() - 2] - '0'][findIndex(done[done.length() - 1])]);
		}
		cout << "#" << done << " & " << nodone << endl;
	}
	return 0;
}