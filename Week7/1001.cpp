#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
using namespace std;

struct Vns_Struct { int Nv; string VN[10];} ;
struct Vts_Struct { int Nt; string VT[10];} ;
struct ps_Struct { int Np; string PL[20], PR[20];} ;
struct llps_Struct { int Np; string PL[30], PR[30]; int psNum[30];} ;

string S;
string expression;

int main(int argc, char const *argv[])
{

	Vns_Struct Vns;
	Vts_Struct Vts;
	ps_Struct ps;
	llps_Struct llps;

	string VnsString = "", VtsString = "";
	cin >> S;
	cin >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i)
	{
		cin >> Vns.VN[i];
		VnsString = VnsString + Vns.VN[i];
	}
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
	{
		cin >> Vts.VT[i];
		VtsString = VtsString + Vts.VT[i];
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
	cin >> expression;

	// middel process
	Vts.VT[Vts.Nt++] = "#";
	string processString[Vns.Nv][20];
	for (int i = 0; i < Vns.Nv; ++i)
		for (int z = 0; z < Vts.Nt; ++z)
			for (int j = 0; j < llps.Np; ++j)
				if (llps.PL[j] == Vns.VN[i] && llps.PR[j] == Vts.VT[z])
					processString[i][z] = ps.PR[llps.psNum[j] - 1];


	string done, nodone = S;
	int pointer = 0;
	while (nodone != "")
	{
		cout << "#" << done << " & " << nodone << "#" << endl;
		int found = VtsString.find(nodone[0]);
		if (found != std::string::npos)
		{
			done += nodone[0];
			nodone = nodone.substr(1, nodone.length());
			pointer++;
		}
		else
		{
			int VnsIndex = VnsString.find(nodone[0]);
			int VtsIndex = VtsString.find(expression[pointer]);
			string toString = processString[VnsIndex][VtsIndex];
			nodone.replace(nodone.begin(), nodone.begin() + 1, toString);
		}
		while (nodone[0] == 'k')
			nodone = nodone.substr(1, nodone.length());
	}
	cout << "#" << done << " & " << nodone << "#" << endl;


	return 0;
}