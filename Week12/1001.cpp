#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

class Priority{
public:
	void readin(){
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			string tmp;
			cin >> tmp;
			V.push_back(tmp[0]);
		}
		for(int i = 0; i < n; ++i){
			relationSheet.push_back(vector<char>());
			for(int j = 0; j < n; ++j){
				string tmp;
				cin >> tmp;
				relationSheet[i].push_back(tmp[0]);
			}
		}
	}

	void buildFunction(){
		bellGraph.resize(V.size() * 2, vector<bool>(V.size() * 2, false));
		for(int i = 0; i < V.size(); ++i){
			for(int j = 0; j < V.size(); ++j){
				if(relationSheet[i][j] == '<') bellGraph[j + V.size()][i] = true;
				else if(relationSheet[i][j] == '>') bellGraph[i][j + V.size()] = true;
				else if(relationSheet[i][j] == '=') bellGraph[i][j + V.size()] = bellGraph[j + V.size()][i] = true;
			}
		}
		for(int i = 0; i < V.size() * 2; ++i) bellGraph[i][i] = true;

		closure = warshall(bellGraph);
		for(int i = 0; i < V.size(); ++i){
			f.push_back(0);
			for(int j = 0; j < V.size() * 2; ++j)
				if(closure[i][j]) ++f[i];
		}
		for(int i = 0; i < V.size(); ++i){
			g.push_back(0);
			for(int j = 0; j < V.size() * 2; ++j)
				if(closure[i + V.size()][j]) ++g[i];
		}
	}

	void print(){
		for(int i = 0; i < V.size() * 2; ++i){
			if(i < V.size()) printf("%3d", f[i]);
			else printf("%3d", g[i - V.size()]);
			for(int j = 0; j < V.size() * 2; ++j)
				printf("%3d", closure[i][j]? 1: 0);
			printf("\n");
		}
		printf("   ");
		for(int i = 0; i < V.size(); ++i) printf("%3c", V[i]);
		printf("\n");
		printf("%3c", 'f');
		for(int i = 0; i < V.size(); ++i) printf("%3d", f[i]);
		printf("\n");
		printf("%3c", 'g');
		for(int i = 0; i < V.size(); ++i) printf("%3d", g[i]);
		printf("\n");
	}

private:
	vector<char> V;
	vector<vector<char> > relationSheet;
	vector<vector<bool> > bellGraph;
	vector<vector<bool> > closure;
	vector<int> f, g;

	vector<vector<bool> > warshall(const vector<vector<bool> > &arr){
		vector<vector<bool> > res = arr;
		
		for(int k = 0; k < arr.size(); ++k){
			for(int i = 0; i < arr.size(); ++i)
				for(int j = 0; j < arr.size(); ++j)
					res[i][j] = (res[i][k] && res[k][j]) || res[i][j];
		}
		return res;
	}
};

int main(){
	Priority g;
	g.readin();
	g.buildFunction();
	g.print();
	return 0;
}