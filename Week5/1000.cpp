#include <iostream>
using namespace std;

struct { int number; string str[10]; } keywords = {3, "int", "main", "return"} ; //关键词
struct { int number; string str[10]; } operators = {5, "+", "*", "=", "+=", "*="}; //运算符
struct { int number; string str[10]; } boundaries = {6, "(", ")", "{", "}", ",", ";"} ; //分界符
struct { int number; string str[100];} identifieres = {0}; //标识符
struct { int number; string str[100];} Unsigned_integer = {0}; //无符号整数

void Process(string inString, int inType)
{
	for (int i = 0; i < keywords.number; ++i)
	{
		if (inString == keywords.str[i])
		{
			printf("<%d,%d>", 1, i);
			return;
		}
	}
	for (int i = 0; i < operators.number; ++i)
	{
		if (inString == operators.str[i])
		{
			printf("<%d,%d>", 2, i);
			return;
		}
	}
	for (int i = 0; i < boundaries.number; ++i)
	{
		if (inString == boundaries.str[i])
		{
			printf("<%d,%d>", 3, i);
			return;
		}
	}

	// undifined
	if (inType == 4)
	{
		bool exitFlag = 0;
		for (int i = 0; i < Unsigned_integer.number; ++i)
		{
			if (inString == Unsigned_integer.str[i])
			{
				printf("<%d,%d>", 5, i);
				exitFlag = 1;
				return;
			}
		}
		if (!exitFlag)
		{
			Unsigned_integer.str[Unsigned_integer.number] = inString;
			printf("<%d,%d>", 5, Unsigned_integer.number);
			Unsigned_integer.number ++;
			return;
		}
	}
	else
	{
		bool exitFlag = 0;
		for (int i = 0; i < identifieres.number; ++i)
		{
			if (inString == identifieres.str[i])
			{
				printf("<%d,%d>", 4, i);
				exitFlag = 1;
				return;
			}
		}
		if (!exitFlag)
		{
			identifieres.str[identifieres.number] = inString;
			printf("<%d,%d>", 4, identifieres.number);
			identifieres.number ++;
			return;
		}
	}

}

int main(int argc, char const *argv[])
{
	char inChar;
	string lassString = "";
	int thisType = 0, lassType = 0; // 0 blank, 1 letter, 2 operator, 3 bound, 4 integer
	while (1)
	{
		inChar = getchar();
		if (inChar == '#')
		{
			Process(lassString, lassType);
			// return 0;
			break;
		}
		if (inChar == '\n')
			continue;
		else if ((inChar >= 'a' && inChar <= 'z') || (inChar >= 'A' && inChar <= 'Z'))
			thisType = 1;
		else if (inChar == '+' || inChar == '*' || inChar == '=')
			thisType = 2;
		else if (inChar >= '0' && inChar <= '9')
			thisType = 4;
		else if (inChar == ' ')
			thisType = 0;
		else
			thisType = 3;
		// cout << inChar << " " << thisType << endl;
		if (thisType == 3)
		{
			Process(lassString, lassType);
			lassString = string(1, inChar);
		}
		else if (thisType == 0)
		{
			if (lassType != 0)
				Process(lassString, lassType);
			lassString = "";
		}
		else if (lassType == 0 || thisType == lassType)
		{
			lassString = lassString + inChar;
		}
		else
		{
			// cout << inChar << "1111" << endl;
			Process(lassString, lassType);
			lassString = string(1, inChar);
		}
		lassType = thisType;
	}
	cout << "\nidentifieres:";
	for (int i = 0; i < identifieres.number; ++i)
	{
		cout << identifieres.str[i];
		if (i != identifieres.number - 1)
			 cout << " ";
	}
	cout << "\nUnsigned_integer:";
	for (int i = 0; i < Unsigned_integer.number; ++i)
	{
		cout << Unsigned_integer.str[i];
		if (i != Unsigned_integer.number - 1)
			 cout << " ";
	}
	return 0;
}