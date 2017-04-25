#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"program.h"

using namespace std;
string removeComment(string &str);
void removeExtraSpace(string &str,int &i);
string addSpace(string &str);
bool isSpecialCharacter(char c);
bool isInComment;
int main()
{
	isInComment = false;
	string line ;
	// Open file
	string file_name;
	vector<string>v;
	stack<int>count;
	cout << "Enter the file name" << endl;
	cin >> file_name;

	ifstream inFile(file_name.c_str());

	if (!inFile.is_open()) {

		cerr << "Error!!! Couldn't open file" << endl;
		exit(EXIT_FAILURE);

	}
	int i = 0;
	while (getline(inFile,line))
	{
			string result = removeComment(line);
			if (result != ""&&result.size() != 1)// if string is empty or string has '\t'=> therefore size is 1
			{
				i++;
				removeExtraSpace(result, i);
				string s = addSpace(result);
				if (s.size()!=1 && s!="" ) // if string is empty or string has ''=> therefore size is 1
				{
					v.push_back(s);
				}
			}
	}
	/*for (vector<string>::iterator i = v.begin();i != v.end();i++)
	{
		cout << *i << endl;
	}*/
	ofstream outFile("finalv2.txt");

	if (!outFile.is_open()) {

		cout << "Couldn't open new file to write data" << endl;

		exit(1);

	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		outFile << *it << " " << endl;
	}
	system("pause");
	return 0;
}
string removeComment(string &str)
{
		stack<int> commentIndex;
		// if the line before not close the comment, mean beginning of line is in comment.
		if (isInComment)
		{
			commentIndex.push(0);
		}
		// check in the line if there is comment tag.
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '/' && (i < (str.length() - 1)))
			{
				// if second character is / mean // detected, switch between comment mode and add to the stack to erase
				if (str[i + 1] == '/')
				{
					isInComment = !isInComment;
					if (isInComment)
					{
						commentIndex.push(i);
					}
					else
					{
						commentIndex.push(i + 1);
					}
					i++;
				}
			}
		}
		// if last character is still in comment then remove till the last character.
		if (isInComment)
		{
			commentIndex.push(str.size());
		}
		// start poping and remove character.
		int tempTail = -1;
		while (commentIndex.size() > 0)
		{
			if (tempTail == -1)
			{
				tempTail = commentIndex.top();
			}
			else
			{
				str.erase(commentIndex.top(), tempTail + 1);
				tempTail = -1;
			}
			commentIndex.pop();
			if (!commentIndex.empty())continue;
		}
		return str;
	
}
void removeExtraSpace(string &str, int &i) {
	if (i = 1) {
		str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
	}
	
	else {
		str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
	}
}
string addSpace(string &str) {
	string result = "";

		for (int i = 0; i < str.length(); i++) {
			if (isSpecialCharacter(str[i]))
				result = result + " " + str[i] + " ";
			else
				result = result + str[i];
		}
	return result;
}

bool isSpecialCharacter(char c)
{
	for (int i = 0; i < TOTAL_SPECIAL; i++)
	{
		if (Special[i] == c)
			return true;
	}
	return false;
}
