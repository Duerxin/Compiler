#include <iostream>
#include <iomanip>
using namespace std;

struct Vns_Struct { int Nv; string VN[10];} ;
struct Vts_Struct { int Nt; string VT[10];} ;
struct ps_Struct { int Np; string PL[20], PR[20];} ;
struct llps_Struct { int Np; string PL[30], PR[30]; int psNum[30];} ;
string S;

int main(int argc, char const *argv[])
{

	Vns_Struct Vns;
	Vts_Struct Vts;
	ps_Struct ps;
	llps_Struct llps;

	cin >> S;
	cin >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i)
	{
		cin >> Vns.VN[i];
	}
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
	{
		cin >> Vts.VT[i];
	}
	cin >> ps.Np;
	for (int i = 0; i < ps.Np; ++i)
	{
		int num;
		cin >> num >> ps.PL[i] >> ps.PR[i];
	}
	cin >> llps.Np;
	for (int i = 0; i < llps.Np; ++i)
	{
		int num;
		cin >> num >> llps.PL[i] >> llps.PR[i] >> llps.psNum[i];
	}

	// middel process
	Vts.VT[Vts.Nt++] = "#";

	// output
	cout << setw(5) << " ";
	for (int i = 0; i < Vts.Nt; ++i)
		cout  << setw(5) << Vts.VT[i];
	cout << endl;
	for (int i = 0; i < Vns.Nv; ++i)
	{
		cout  << setw(5) << Vns.VN[i];
		for (int z = 0; z < Vts.Nt; ++z)
		{

			bool flag = true;
			for (int j = 0; j < llps.Np; ++j)
			{
				if (llps.PL[j] == Vns.VN[i] && llps.PR[j] == Vts.VT[z])
				{
					flag = false;
					cout << setw(5) << ps.PR[llps.psNum[j] - 1];
				}
			}
			if (flag)
			{
				cout << setw(5) << " ";
			}
		}
		cout << endl;
	}


	return 0;
}