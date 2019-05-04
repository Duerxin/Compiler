#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	int mat[num][num];
	for (int i = 0; i < num; ++i)
		for (int j = 0; j < num; ++j)
			cin >> mat[i][j];

	for (int k = 0; k < num; ++k)
		for (int i = 0; i < num; ++i)
			for (int j = 0; j < num; ++j)
				mat[i][j] = mat[i][j] ? 1 : mat[i][k] * mat[k][j];
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
			cout << setw(3) << mat[i][j];
		cout << endl;
	}
	return 0;
}