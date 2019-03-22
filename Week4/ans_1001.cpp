#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

struct { int number; char zimu[100]; } letter = {0};                                        //字母
struct { int number; int single_state[100]; bool isstart[100]; bool isend[100]; } state = {0}; //状态表
struct { int number; int start[100]; int end[100]; char letter[100]; } map = {0};           //映射表

struct { int number; int res_state[100]; bool isstart[100]; bool isend[100]; string chuan[100]; } ressta = {0}; //确定化后的状态表
struct { int number; int start[100]; int end[100]; char letter[100]; } resmap = {0};        //确定化后的映射表

struct ss { int number; int ber[100]; bool isstart; bool isend;  };
queue<ss> temp;          //用来 缓存造表法中的元素
struct { int number; string left[100]; string right[100]; char zimu[100];} haha = {0}; //用来暂时记录string状态的映射关系
queue<int > letter_kong; //用来实现映射的 “深搜”的队列

void input();  //输入数据
void print();  //输出结果
void init();   //初始化
string int2string(int a);
string change(ss teres);
bool isexist(ss a);
bool isexist_start( ss a );
bool isexist_end(ss a);
void sort(ss a);

int main() {
	input();
	init();

	while (1) {
		ss te = temp.front();  temp.pop();

//刷整个映射表，得到确定化后的状态表 ，并将确定化后的映射记录在表中
		for (int i = 0; i < letter.number; i++ ) { //字母
			ss teres;  //用来缓存将要压入队列的状态
			teres.number = 0;

			for (int j = 0; j < te.number ; j++) {
				for (int z = 0; z < map.number ; z++) {
					if ( letter.zimu[i] == map.letter[z] && te.ber[j] == map.start[z] ) {
						bool is = 1;
						for (int q = 0; q < teres.number; q++) {
							if (map.end[z] == teres.ber[q] ) is = 0;
						}

						if (is) {
//先把确定的这个放进去
							teres.ber[teres.number ] = map.end[z];
							teres.number++;

//处理有可能是空的需要深搜的情况
							letter_kong.push( map.end[z] );
							while (1) {
								int temp = letter_kong.front(); letter_kong.pop();
								for (int r = 0; r < map.number; r++ ) {
									if (temp == map.start[r] && map.letter[r] == ‘k‘ ) {
//判断重复
										bool iss = 1;
										for (int qq = 0; qq < teres.number; qq++) {
											if (map.end[r ] == teres.ber[qq] ) is = 0;
										}

										if (iss) {
											teres.ber[teres.number ] = map.end[r];
											teres.number++;
											letter_kong.push(map.end[r]); //将新的节点放进去
										}

									}
								}

								if (letter_kong.empty()) break;
							}



//  */

						}
					}
				}
			}

//对teres中的元素按大小排序
			int tempq;
			for (int ii = 0; ii < teres.number - 1; ii++ ) {
				for (int jj = ii + 1; jj < teres.number; jj++ ) {
					if (teres.ber[jj] < teres.ber[ii] ) {

						tempq = teres.ber[ii];
						teres.ber[ii] = teres.ber[jj];
						teres.ber[jj] = tempq;
					}
				}
			}

//对teres做“确定化后状态表”处理
			if (!isexist(teres)) {
				temp.push(teres);   //压到temp里面

				ressta.res_state[ ressta.number ] = ressta.number;
				ressta.chuan[ressta.number] = change(teres);
				if ( isexist_start(teres) ) {
					ressta.isstart[ressta.number] = 1;
				}
				else {
					ressta.isstart[ressta.number] = 0;
				}

				if ( isexist_end(teres)) {
					ressta.isend[ressta.number] = 1;
				}
				else {
					ressta.isend[ressta.number] = 0;
				}

				ressta.number++;
			}

//还有映射表
			if (teres.number != 0) {
				haha.left[haha.number ] = change(te);
				haha.right[haha.number] = change(teres);
				haha.zimu[haha.number] = letter.zimu[i];
				haha.number++;
			}

		}

		if (temp.empty()) break;
	}

	for (int i = 0; i < haha.number; i++) {
		int k;
		for (k = 0; k < ressta.number && ressta.chuan[k] != haha.left[i]; k++ ) ;
		resmap.start[resmap.number] = ressta.res_state[k];

		int p;
		for (p = 0; p < ressta.number && ressta.chuan[p] != haha.right[i]; p++ );
		resmap.end[resmap.number ] = ressta.res_state[p];

		resmap.letter[resmap.number] = haha.zimu[i];

		resmap.number++;
	}

	print();
	return 0;
}

void init() {
	ressta.number = 0;

	ss first;
	first.number = 1;
	first.isstart = state.isstart[0];
	first.isend = state.isend[0];
	first.ber[0] = state.single_state[0];
	temp.push(first);

//相当于把 temp队列中的第一个元素记入 “确定化后的状态集”
	ressta.res_state[0] = state.single_state[0];
	ressta.isstart[0] = state.isstart[0];
	ressta.isend[0] = state.isend[0];
	ressta.chuan[0] = int2string( state.single_state[0] );

	ressta.number++;

	return ;
}

bool isexist_start( ss a ) {
	for (int i = 0; i < a.number; i++) {
		for (int j = 0; j < state.number; j++ ) {
			if (state.isstart[j] == 1 && a.ber[i] == state.single_state[j] ) return true;
		}
	}
	return false;
}

bool isexist_end(ss a) {
	for (int i = 0; i < a.number; i++) {
		for (int j = 0; j < state.number; j++ ) {
			if (state.isend[j] == 1 && a.ber[i] == state.single_state[j] ) return true;
		}
	}
	return false;
}

bool isexist(ss a) {
	if (a.number == 0) return 1;
	for (int i = 0; i < ressta.number; i++) {
		if (ressta.chuan[i] == change(a) ) {
			return 1;
		}
	}
	return 0;
}


string int2string(int a) {
	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	return str;
}

string  change( ss teres) {
	string res;
	for (int i = 0; i < teres.number; i++ ) {
		res = res + int2string( teres.ber[i] );
	}
	return res;
}

void input() {
	cin >> letter.number;
	for (int i = 0; i < letter.number; i++) {
		cin >> letter.zimu[i];
	}
	cin >> state.number;
	for (int i = 0; i < state.number; i++) {
		cin >> state.single_state[i] >> state.isstart[i] >> state.isend[i];
	}
	cin >> map.number;
	for (int i = 0; i < map.number; i++) {
		cin >> map.start[i] >> map.end[i] >> map.letter[i];
	}
	return ;
}

void print() {
	cout << "Determine State:" << endl;
	for (int i = 0; i < ressta.number; i++) {
		cout << ressta.res_state[i] << " " << ressta.isstart[i] << " " << ressta.isend[i] << " [" << ressta.chuan[i] << "]" << endl;
	}

	cout << "Determine Mapping:" << endl;
	for (int i = 0; i < resmap.number; i++) {
		cout << resmap.start[i] << " " << resmap.end[i] << " " << resmap.letter[i] << " (" << i << endl;
	}

	return ;
}