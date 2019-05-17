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
	cout << "# & (x+(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#( & x+(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(x & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(D & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(F & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(T & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(A & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E & +(y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+ & (y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+( & y-x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(y & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(D & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(F & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(T & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(A & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E & -x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E- & x*z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-x & *z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-D & *z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F & *z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F* & z)*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F*z & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F*D & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F*F & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-F*T & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E-T & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(E & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(B & )*(y+x*z))+x/z#" << endl;
	cout << "#(E+(B) & *(y+x*z))+x/z#" << endl;
	cout << "#(E+F & *(y+x*z))+x/z#" << endl;
	cout << "#(E+F* & (y+x*z))+x/z#" << endl;
	cout << "#(E+F*( & y+x*z))+x/z#" << endl;
	cout << "#(E+F*(y & +x*z))+x/z#" << endl;
	cout << "#(E+F*(D & +x*z))+x/z#" << endl;
	cout << "#(E+F*(F & +x*z))+x/z#" << endl;
	cout << "#(E+F*(T & +x*z))+x/z#" << endl;
	cout << "#(E+F*(A & +x*z))+x/z#" << endl;
	cout << "#(E+F*(E & +x*z))+x/z#" << endl;
	cout << "#(E+F*(E+ & x*z))+x/z#" << endl;
	cout << "#(E+F*(E+x & *z))+x/z#" << endl;
	cout << "#(E+F*(E+D & *z))+x/z#" << endl;
	cout << "#(E+F*(E+F & *z))+x/z#" << endl;
	cout << "#(E+F*(E+F* & z))+x/z#" << endl;
	cout << "#(E+F*(E+F*z & ))+x/z#" << endl;
	cout << "#(E+F*(E+F*D & ))+x/z#" << endl;
	cout << "#(E+F*(E+F*F & ))+x/z#" << endl;
	cout << "#(E+F*(E+F*T & ))+x/z#" << endl;
	cout << "#(E+F*(E+T & ))+x/z#" << endl;
	cout << "#(E+F*(E & ))+x/z#" << endl;
	cout << "#(E+F*(B & ))+x/z#" << endl;
	cout << "#(E+F*(B) & )+x/z#" << endl;
	cout << "#(E+F*F & )+x/z#" << endl;
	cout << "#(E+F*T & )+x/z#" << endl;
	cout << "#(E+T & )+x/z#" << endl;
	cout << "#(E & )+x/z#" << endl;
	cout << "#(B & )+x/z#" << endl;
	cout << "#(B) & +x/z#" << endl;
	cout << "#F & +x/z#" << endl;
	cout << "#T & +x/z#" << endl;
	cout << "#A & +x/z#" << endl;
	cout << "#E & +x/z#" << endl;
	cout << "#E+ & x/z#" << endl;
	cout << "#E+x & /z#" << endl;
	cout << "#E+D & /z#" << endl;
	cout << "#E+F & /z#" << endl;
	cout << "#E+F/ & z#" << endl;
	cout << "#E+F/z & #" << endl;
	cout << "#E+F/D & #" << endl;
	cout << "#E+F/F & #" << endl;
	cout << "#E+F/T & #" << endl;
	cout << "#E+T & #" << endl;
	cout << "#E & #" << endl;
	return 0;
}