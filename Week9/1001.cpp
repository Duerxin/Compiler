#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

struct Vns_Struct { int Nv; string VN[10];} Vns;
struct Vts_Struct { int Nt; string VT[10];} Vts;
struct ps_Struct { int Np; string PL[20], PR[20];} ps;
string S;


int findIndex(string tofind)
{
	int index = 0;

	for (int i = 0; i < Vns.Nv; ++i)
	{
		if (Vns.VN[i] == tofind)
			return index;
		index++;
	}

	for (int i = 0; i < Vts.Nt; ++i)
	{
		if (Vts.VT[i] == tofind)
			return index;
		index++;
	}

	return -1;
}

int main(int argc, char const *argv[])
{

	string allSymbol = "";
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

	// First
	int first[total][total];
	memset(first, 0, sizeof(first));
	cout << "FIRST=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int i = 0; i < ps.Np; ++i)
		first[findIndex(ps.PL[i])][findIndex(ps.PR[i].substr(0, 1))] = 1;
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << first[i][j];
		cout << endl;
	}

	// Last
	int last[total][total];
	memset(last, 0, sizeof(last));
	cout << "LAST=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int i = 0; i < ps.Np; ++i)
		last[findIndex(ps.PL[i])][findIndex(ps.PR[i].substr(ps.PR[i].length() - 1, ps.PR[i].length()))] = 1;
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << last[i][j];
		cout << endl;
	}

	// First Plus
	int firstplus[total][total];
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			firstplus[i][j] = first[i][j];
	cout << "FIRST+=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int k = 0; k < total; ++k)
		for (int i = 0; i < total; ++i)
			for (int j = 0; j < total; ++j)
				firstplus[i][j] = firstplus[i][j] ? 1 : firstplus[i][k] * firstplus[k][j];
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << firstplus[i][j];
		cout << endl;
	}

	// Last Plus
	int lastplus[total][total];
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			lastplus[i][j] = last[i][j];
	cout << "LAST+=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int k = 0; k < total; ++k)
		for (int i = 0; i < total; ++i)
			for (int j = 0; j < total; ++j)
				lastplus[i][j] = lastplus[i][j] ? 1 : lastplus[i][k] * lastplus[k][j];
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << lastplus[i][j];
		cout << endl;
	}
	return 0;
}