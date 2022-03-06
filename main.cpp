#include <iostream>
#include <string>
#include <fstream>
//#include <cstring>
using namespace std;

string promptStr(string);
string promptCMD(string);
string toup(string);

int main()
{
	string newTraits[128];
	string usedTraits[128];

	int usedLength, newLength;
	string userPrompt;

	ifstream fin("traits.txt");
	if (!fin.is_open())
	{
		cout << "error opening traits.txt";
		system("sleep 2s");
		exit(-1);
	}
	/**format of traits.txt
	 * lines at top will be all used traits.
	 * empty line marks the end of used traits.
	 * all lines after that until eof are new traits.
	 */
	usedLength = 0;
	while(!fin.eof())
	{
		string str;
		getline(fin, str);
		if(str.length() == 0)
			break;
		usedTraits[usedLength] = str;
		usedLength++;
	}

	newLength = 0;
	while(!fin.eof())
	{
		string str;
		getline(fin, str);
		if(str.length() == 0)
			break;
		newTraits[newLength] = str;
		newLength++;
	}

	cout << "Opened traits.txt. "
		<< usedLength << " used traits "
		<< newLength << " new traits loaded. " << endl;

	for (int i = 0; i < usedLength; i++)
	{
		cout << usedTraits[i] << endl;
	}
	
	while(true)
	{
		char cmd = promptCMD("Enter Command [P]ick, [A]dd, [S]ave, [E]xit\n");
		switch (cmd)
		{
			case 'P':
				//Select three random newTraits, allow user to pick, then move
				//to used.
		}

	}
	//string test = promptCMD("Enter anything you want to be in caps");
	//cout << "we got " << test;
	//	promptStr("type exit to exit.");
	exit(0);
}

//display string, return input string from user
string promptStr(string promptMsg)
{
	string input;
	cout << promptMsg << ": ";
	getline(cin,input);
//	cin.ignore(80, '\n');
	return input;
}

char promptCMD(string promptMsg)
{
	return toup(promptStr(promptMsg))[0];
}


// Converts string to caps
string toup(string str)
{
	cout << str << " is my string" << endl;
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
		cout << str[i];
	}
	return str;
}
