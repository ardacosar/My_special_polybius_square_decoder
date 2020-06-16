
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

char key[8][10]{ // key[x][9] = \0 | key[x][8] = Last char
{"abcdefghi"},
{"jklmnopqr"},
{"stuvwxyz "},
{"ABCDEFGHI"},
{"JKLMNOPQR"},
{"STUVWXYZ."},
{",':;()!?0"},
{"123456789"}
};


string encryption(string code)
{
	string newCode = "";
	for (int i = 0; i < code.length(); i++) // Letter by letter
	{
		for (int j = 0; j < 8; j++) // Row
		{
			for (int k = 0; k < 9; k++) // Column
			{
				if (code[i] == key[j][k])
				{
					newCode += to_string(j + 1) + to_string(rand() % 10) + to_string(k + 1); // Row + Random Number + Column
					j = 8; k = 9; // Ending search					
				}
			}
		}
	}
	return newCode;
}

string decryption(string code)
{
	string newCode = "";
	for (int i = 0; i < code.length(); i += 3) // Control every three digit
	{
		for (int j = 0; j < 8; j++) // Row
		{
			for (int k = 0; k < 9; k++) // Column
			{
				if (code.substr(i, 1) == to_string(j + 1) && code.substr(i + 2, 1) == to_string(k + 1)) // code.substr(i + 1, 1) is random digit, it is not important.
				{
					newCode += key[j][k];
					j = 8; k = 9; // Ending search					
				}
			}
		}
	}
	return newCode;
}

int main()
{
	srand(time(NULL));

	string myCode;
	int c;
	do {
		do {
			cout << endl;
			cout << " 1 : Encryption \n 2 : Decryption \n 3 : Exit \n                   ";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);

		getchar();
		switch (c)
		{
		case 1:                   //Encryption			
			cout << "Code: ";
			getline(cin, myCode);
			myCode = encryption(myCode);
			break;
		case 2:                   //Decryption
			do {
				cout << "Code: ";
				getline(cin, myCode);
			} while (myCode.length() % 3 != 0);  // Decrypted string's length must be multiples of 3
			myCode = decryption(myCode);
			break;
		case 3:
			return 0;             //Exit
			break;
		}
		cout << myCode << endl;
	} while (true);

}

