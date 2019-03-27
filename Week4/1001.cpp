#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

struct
{
	int num;
	char c[100];
} alpha = {0};

struct
{
	int num;
	int single_state[100];
	bool isStart[100];
	bool isEnd[100];
} state = {0};

struct
{
	int num;
	int start[100];
	int end[100];
	char c[100];
} map = {0};

struct
{
	int num;
	int res_state[100];
	bool isStart[100];
	bool isEnd[100];
	string subSet[100];
} newState = {0};

struct
{
	int num;
	int start[100];
	int end[100];
	char c[100];
} newMap = {0};

struct ns
{
	int num;
	int sub[100];
	bool isStart;
	bool isEnd;
};

queue<ns> temp;

struct
{
	int num;
	string left[100];
	string right[100];
	char c[100];
} haha = {0};

queue<int> c_kong;

void input();
void output();
void init();
string intToStr(int a);
string arrToStr(ns teres);
bool isExist(ns a);
bool isExistStart( ns a );
bool isExistEnd(ns a);
void sort(ns a);

void init() {
	newState.num = 0;
	ns first;
	first.num = 1;
	first.isStart = state.isStart[0];
	first.isEnd = state.isEnd[0];
	first.sub[0] = state.single_state[0];
	temp.push(first);

	newState.res_state[0] = state.single_state[0];
	newState.isStart[0] = state.isStart[0];
	newState.isEnd[0] = state.isEnd[0];
	newState.subSet[0] = intToStr( state.single_state[0] );

	newState.num++;
}

void input() {
	cin >> alpha.num;
	for (int i = 0; i < alpha.num; i++) {
		cin >> alpha.c[i];
	}
	cin >> state.num;
	for (int i = 0; i < state.num; i++) {
		cin >> state.single_state[i] >> state.isStart[i] >> state.isEnd[i];
	}
	cin >> map.num;
	for (int i = 0; i < map.num; i++) {
		cin >> map.start[i] >> map.end[i] >> map.c[i];
	}
}

void output() {
	cout << "Determine State:" << endl;
	for (int i = 0; i < newState.num; i++) {
		cout << newState.res_state[i] << " " << newState.isStart[i] << " " << newState.isEnd[i] << " [" << newState.subSet[i] << "]" << endl;
	}

	cout << "Determine Mapping:" << endl;
	for (int i = 0; i < newMap.num; i++) {
		cout << newMap.start[i] << " " << newMap.end[i] << " " << newMap.c[i] << " (" << i << endl;
	}
}

bool isExistStart( ns a ) {
	for (int i = 0; i < a.num; i++) {
		for (int j = 0; j < state.num; j++ ) {
			if (state.isStart[j] == 1 && a.sub[i] == state.single_state[j] ) return true;
		}
	}
	return false;
}

bool isExistEnd(ns a) {
	for (int i = 0; i < a.num; i++) {
		for (int j = 0; j < state.num; j++ ) {
			if (state.isEnd[j] == 1 && a.sub[i] == state.single_state[j] ) return true;
		}
	}
	return false;
}

bool isExist(ns a) {
	if (a.num == 0) return 1;
	for (int i = 0; i < newState.num; i++) {
		if (newState.subSet[i] == arrToStr(a) ) {
			return 1;
		}
	}
	return 0;
}


string intToStr(int n) {
	string res = "";
	res = res + char(n + '0');
	return res;
}

string  arrToStr( ns a) {
	string res = "";
	for (int i = 0; i < a.num; ++i)
		res = res + intToStr(a.sub[i]);
	return res;
}

int main() {
	input();
	init();

	while (1) {
		ns te = temp.front();  temp.pop();

		for (int i = 0; i < state.num; i++ ) {
			ns teres;
			teres.num = 0;

			for (int j = 0; j < te.num ; j++) {
				for (int z = 0; z < map.num ; z++) {
					if ( alpha.c[i] == map.c[z] && te.sub[j] == map.start[z] ) {
						bool is = 1;
						for (int q = 0; q < teres.num; q++) {
							if (map.end[z] == teres.sub[q] ) is = 0;
						}

						if (is) {
							teres.sub[teres.num ] = map.end[z];
							teres.num++;

							c_kong.push( map.end[z] );
							while (1) {
								int temp = c_kong.front(); c_kong.pop();
								for (int r = 0; r < map.num; r++ ) {
									if (temp == map.start[r] && map.c[r] == 'k' ) {
										bool iss = 1;
										for (int qq = 0; qq < teres.num; qq++) {
											if (map.end[r ] == teres.sub[qq] ) is = 0;
										}

										if (iss) {
											teres.sub[teres.num ] = map.end[r];
											teres.num++;
											c_kong.push(map.end[r]);
										}

									}
								}

								if (c_kong.empty()) break;
							}

						}
					}
				}
			}

			int tempq;
			for (int ii = 0; ii < teres.num - 1; ii++ ) {
				for (int jj = ii + 1; jj < teres.num; jj++ ) {
					if (teres.sub[jj] < teres.sub[ii] ) {
						tempq = teres.sub[ii];
						teres.sub[ii] = teres.sub[jj];
						teres.sub[jj] = tempq;
					}
				}
			}

			if (!isExist(teres)) {
				temp.push(teres);

				newState.res_state[ newState.num ] = newState.num;
				newState.subSet[newState.num] = arrToStr(teres);
				if ( isExistStart(teres) ) {
					newState.isStart[newState.num] = 1;
				}
				else {
					newState.isStart[newState.num] = 0;
				}

				if ( isExistEnd(teres)) {
					newState.isEnd[newState.num] = 1;
				}
				else {
					newState.isEnd[newState.num] = 0;
				}

				newState.num++;
			}


			if (teres.num != 0) {
				haha.left[haha.num ] = arrToStr(te);
				haha.right[haha.num] = arrToStr(teres);
				haha.c[haha.num] = alpha.c[i];
				haha.num++;
			}

		}

		if (temp.empty()) break;
	}

	for (int i = 0; i < haha.num; i++) {
		int k;
		for (k = 0; k < newState.num && newState.subSet[k] != haha.left[i]; k++ ) ;
		newMap.start[newMap.num] = newState.res_state[k];

		int p;
		for (p = 0; p < newState.num && newState.subSet[p] != haha.right[i]; p++ );
		newMap.end[newMap.num ] = newState.res_state[p];

		newMap.c[newMap.num] = haha.c[i];

		newMap.num++;
	}

	output();
	return 0;
}

