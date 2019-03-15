#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Vns_Struct { int Nv; string VN[10];} ;
struct Vts_Struct { int Nt; string VT[10];} ;
struct ps_Struct { int Np; string PL[20], PR[20];} ;
string S;

int main(int argc, char const *argv[])
{
	Vns_Struct Vns;
	Vts_Struct Vts;
	ps_Struct ps;
	std::vector<string> reached;

	// Begin Symbol
	cin >> S;
	reached.push_back(S); 

	// Begin Nonterminal
	cin >> Vns.Nv;
	std::vector<string> out[Vns.Nv];
	for (int i = 0; i < Vns.Nv; ++i)
		cin >> Vns.VN[i];

	// Begin Terminal
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];

	// Input Productions
	// And delete self production
	cin >> ps.Np;
	for (int i = 0; i < ps.Np; ++i)
	{
		cin >> ps.PL[i] >> ps.PR[i];
		reached.push_back(ps.PR[i]);
		if (ps.PL[i] == ps.PR[i])
			cout << "delete self production:" << ps.PL[i] << "::=" << ps.PR[i] << endl;
		else
		{
			int j = 0;
			for (; j < Vns.Nv; ++j)
				if (Vns.VN[j] == ps.PL[i])
					break;
			out[j].push_back(ps.PR[i]);
		}

	}

	// Find the unreached Vn
	// And delete production and VN

	for (int i = 0; i < Vns.Nv; ++i)
	{
		vector<string>::iterator find_unreached;
		find_unreached = std::find(reached.begin(), reached.end(), Vns.VN[i]);
		if (find_unreached == reached.end())
		{
			cout << "unreached Vn:" << Vns.VN[i] << endl;
			int j = 0;
			for (; j < Vns.Nv; ++j)
				if (Vns.VN[j] == Vns.VN[i])
					break;
			for (vector<string>::iterator iter_i = out[j].begin(); iter_i != out[j].end(); ++iter_i)
				cout << "delete production:" << Vns.VN[i] << "::=" << *iter_i << endl;
			cout << "delete VN:" << Vns.VN[i] << endl;
			out[j].clear();
		}
	}

	// Begin  Print Productions
	cout << "G[" << S << "]:" << endl;

	for (int i = 0; i < Vns.Nv; ++i)
	{
		if (out[i].empty())
			continue;
		cout << Vns.VN[i] << "::=";
		for (vector<string>::iterator iter_i = out[i].begin(); iter_i != out[i].end(); ++iter_i)
		{
			cout << *iter_i;
			if (iter_i+1 == out[i].end())
				cout << endl;
			else
				cout << " | ";
		}

	}
	return 0;
}