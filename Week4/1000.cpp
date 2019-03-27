#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int letterIndex(char letter, char letters[], int letterNum)
{
	for (int i = 0; i < letterNum; ++i)
		if (letter == letters[i])
			return i;
	return -1;
}

int main(int argc, char const *argv[])
{
	int letterNum;
	cin >> letterNum;
	char letter[letterNum];
	for (int i = 0; i < letterNum; ++i)
	{
		cin >> letter[i];
		// cout << letter[i];
	}
	int oriStateNum;
	cin >> oriStateNum;
	int beginState = -1, endState = -1;
	for (int i = 0; i < oriStateNum; ++i)
	{
		int tempState, tempBegin, tempEnd;
		cin >> tempState >> tempBegin >> tempEnd;
		if (tempBegin == 1)
			beginState = tempState;
		else if (tempEnd == 1)
			endState = tempState;
	}


	int mappingNum;
	cin >> mappingNum;
	int tranform[oriStateNum][letterNum];
	// memset(tranform, -1, sizeof(tranform));
	for (int i = 0; i < oriStateNum; ++i)
	{
		for (int j = 0; j < letterNum; ++j)
		{
			tranform[i][j] = -1;
		}
	}

	for (int i = 0; i < mappingNum; ++i)
	{
		int tempBegin, tempEnd;
		char tempLetter;
		cin >> tempBegin >> tempEnd >> tempLetter;
		tranform[tempBegin][letterIndex(tempLetter, letter, letterNum)] = tempEnd;
	}

	std::vector<vector<int> > determineState;
	std::vector<int> beginV;
	beginV.push_back(beginState);
	determineState.push_back(beginV);
	// char determineMapping[]
	for (int z = 0; z < determineState.size(); ++z)
	{
		// string thisStateVec = determineState[z];
		cout << "------" << endl;
		for (int j = 0; j < letterNum; ++j)
		{
			std::vector<int> newStateV;
			for (int i = 0; i < determineState[z].size(); ++i)
			{
				int stateIndex = determineState[z][i];
				if (tranform[stateIndex][j] != -1)
					newStateV.push_back(tranform[stateIndex][j]);
			}
			sort(newStateV.begin(), newStateV.end());
			newStateV.erase(unique(newStateV.begin(), newStateV.end()), newStateV.end());

			// string newStateString = "";
			for (int i = 0; i < newStateV.size(); ++i)
			{
				cout << newStateV[i];
				// newStateString = newStateString + char(newStateV[i]+'0');
				// cout << "Add";
				// cout << newStateString << endl;
			}
			// cout << newStateString << endl;
			// if (newStateString == "")
			// {
			// 	continue;
			// }
			// if (find(determineState.begin(), determineState.end(), newStateString) == determineState.end())
			// {
			// 	determineState.push_back(newStateV);
			// 	// cout << newStateString << endl;
			// }
			// return 0;
		}
	}

	return 0;
}