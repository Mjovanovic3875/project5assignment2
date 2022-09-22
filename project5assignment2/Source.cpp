#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
	string first;
	string last;
};


int main()
{
	ifstream file;

	vector<STUDENT_DATA> students;

	string line;

	file.open("StudentData.txt");

	//will read all lines in file
	while(getline(file,line))
	{
		//will hold current first and last name
		string first;
		string last;

		//will put the line into istringstream object to be able to extract it with getline
		istringstream iss(line);
		//temp vector and varible for holding current student
		string substring{};
		vector<string> substrings{};

		//parcing firstname and last name from line between commas, put into the "temp" vector
		while (getline(iss, substring, ',')) 
		{
			substrings.push_back(substring);
		}

		//take firstname and lastname put into student struct
		STUDENT_DATA student{};
		student.last = substrings[0];
		student.first = substrings[1];
		#ifdef _DEBUG
		cout << "firstname: " << student.first << "\t" << "lastname: " << student.last << endl;
		#endif


		//push to students vector
		students.push_back(student);
	}

	

}