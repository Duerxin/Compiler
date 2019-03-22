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
		cin >> letter[i];
	int oriStateNum;
	cin >> oriStateNum;
	int beginState = 0, endState = 0;
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
	memset(tranform, -1, sizeof(tranform));

	for (int i = 0; i < mappingNum; ++i)
	{
		int tempBegin, tempEnd;
		char tempLetter;
		cin >> tempBegin >> tempEnd >> tempLetter;
		tranform[tempBegin][letterIndex(tempLetter, letter, letterNum)] = tempEnd;
	}

	std::vector<string> determineState;
	determineState.push_back(to_string(beginState));
	// char determineMapping[]
	for (std::vector<string>::iterator nowState = determineState.begin(); nowState != determineState.end(); nowState++)
	{
		string thisStateString = *nowState;
		cout << *nowState << endl;
		for (int j = 0; j < letterNum; ++j)
		{
			std::vector<int> newStateV;
			for (int i = 0; i < thisStateString.length(); ++i)
			{
				cout << thisStateString[i] << endl;
				if (tranform[thisStateString[i]][j] != -1)
					newStateV.push_back(tranform[thisStateString[i]][j]);
			}
			sort(newStateV.begin(), newStateV.end());
			newStateV.erase(unique(newStateV.begin(), newStateV.end()), newStateV.end());

			string newStateString = "";
			for (std::vector<int>::iterator t = newStateV.begin() ; t != newStateV.end() ; t++)
			{
				cout <<  *t << endl;
				newStateString += to_string(*t);
			}
			if (find(determineState.begin(), determineState.end(), newStateString) != determineState.end())
			{
				determineState.push_back(newStateString);
				cout << newStateString << endl;
			}
			return 0;
		}
	}

	return 0;
}