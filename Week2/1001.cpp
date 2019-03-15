#include <iostream>
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
	cin >> S;

	cin >> Vns.Nv;
	string out[Vns.Nv];
	for (int i = 0; i < Vns.Nv; ++i)
	{
		cin >> Vns.VN[i];
		out[i] = "";
	}


	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];

	cin >> ps.Np;
	for (int i = 0; i < ps.Np; ++i)
	{
		cin >> ps.PL[i] >> ps.PR[i];
		int j = 0;
		for (; j < Vns.Nv; ++j)
			if (Vns.VN[j] == ps.PL[i])
				break;
		if (out[j] != "")
			out[j] += " | ";
		out[j] += ps.PR[i];

	}

	cout << "G[" << S << "]:" << endl;
	for (int i = 0; i < Vns.Nv; ++i)
		cout << Vns.VN[i] << "::=" << out[i] << endl;
	return 0;
}