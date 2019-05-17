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


	// EQUAL
	int equal[total][total];
	memset(equal, 0, sizeof(equal));
	cout << "EQUAL=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int i = 0; i < ps.Np; ++i)
		if (ps.PR[i].length() > 1)
			for (int j = 0; j < ps.PR[i].length() - 1; ++j)
				equal[findIndex(ps.PR[i][j])][findIndex(ps.PR[i][j + 1])] = 1;
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << equal[i][j];
		cout << endl;
	}

	// First
	int first[total][total];
	memset(first, 0, sizeof(first));
	for (int i = 0; i < ps.Np; ++i)
		first[findIndex(ps.PL[i][0])][findIndex(ps.PR[i][0])] = 1;

	// First Plus
	int firstplus[total][total];
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			firstplus[i][j] = first[i][j];
	for (int k = 0; k < total; ++k)
		for (int i = 0; i < total; ++i)
			for (int j = 0; j < total; ++j)
				firstplus[i][j] = firstplus[i][j] ? 1 : firstplus[i][k] * firstplus[k][j];
	for (int i = 0; i < total; ++i)
		firstplus[i][i] = 0;

	// LEQUAL
	int lequal[total][total];
	memset(lequal, 0, sizeof(lequal));
	cout << "LEQUAL=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;

	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			for (int k = 0; k < total; ++k)
				lequal[i][j] += equal[i][k] * firstplus[k][j];
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << lequal[i][j];
		cout << endl;
	}

	// Last
	int last[total][total];
	memset(last, 0, sizeof(last));
	for (int i = 0; i < ps.Np; ++i)
		last[findIndex(ps.PL[i][0])][findIndex(ps.PR[i][ps.PR[i].length() - 1])] = 1;

	// Last Plus
	int lastplus[total][total];
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			lastplus[i][j] = last[i][j];
	for (int k = 0; k < total; ++k)
		for (int i = 0; i < total; ++i)
			for (int j = 0; j < total; ++j)
				lastplus[i][j] = lastplus[i][j] ? 1 : lastplus[i][k] * lastplus[k][j];

	// GEUQAL
	int gequal[total][total];
	memset(gequal, 0, sizeof(gequal));
	cout << "GEQUAL=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			for (int k = 0; k < total; ++k)
				gequal[i][j] += lastplus[k][i] * equal[k][j];
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << gequal[i][j];
		cout << endl;
	}


	// M[R]
	char m[total][total];
	memset(m, ' ', sizeof(m));
	cout << "M[R]=" << endl << "   ";
	for (int i = 0; i < total; ++i)
		cout << setw(3) << allSymbol[i];
	cout << endl;
	for (int i = 0; i < total; ++i)
		for (int j = 0; j < total; ++j)
			if (equal[i][j])
				m[i][j] = '=';
			else if (lequal[i][j])
				m[i][j] = '<';
			else if (gequal[i][j])
				m[i][j] = '>';
	for (int i = 0; i < total; ++i)
	{
		cout << setw(3) << allSymbol[i];
		for (int j = 0; j < total; ++j)
			cout << setw(3) << m[i][j];
		cout << endl;
	}

	return 0;
}