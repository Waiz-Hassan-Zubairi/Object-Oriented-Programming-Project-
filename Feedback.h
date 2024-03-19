#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include "Patient.h"
using namespace std;

class feedback
{	
private:
	int nUsers;
	string writer_name;
	string feed_back;
	string* Writer_name;
	string* Feed_back;



public:
	feedback()
	{
		ifstream userFile;
		userFile.open("feedback.txt", ios::in);
		int count = 0;

		//Checking if file exists and is open
		if (userFile.is_open()) {
			string line;
			while (getline(userFile, line)) {
				if (line != "") {
					count++;
				}
			}
		}

		//Moving the file reading cursor to the start of the file (beginning)
		userFile.close();
		userFile.open("feedback.txt", ios::in);



		//Now dynamically allocating the arrays according to the users
		Writer_name = new string[count];
		Feed_back = new string[count];

		if (count != 0) {
			//cout << "Number of existing Users = " << count << endl;
			nUsers = count;

			//Now reading each line and storing the user
			string line;
			int counter_U = 0;
			while (getline(userFile, line)) {
				if (line != "") {
					stringstream ss(line);
					string TempValues[2];
					int tmp_Counter = 0;
					while (ss.good()) {
						getline(ss, TempValues[tmp_Counter], ',');
						tmp_Counter++;
					}
				    Writer_name[counter_U] = TempValues[0];
					Feed_back[counter_U] = TempValues[1];

					counter_U++;
				}
			}
		}
		else {
			//cout << "No users exists" << endl;
			nUsers = 0;
		}
		userFile.close();
		ofstream writeToFile;
		writeToFile.open("feedback.txt", ios::app);

		while (1)
		{
			if ((name_verify(writer_name) == true))
			{


				writeToFile << writer_name;
				writeToFile << ",";
				writeToFile << feed_back;
				break;
			}
		}
	}

	bool name_verify(string name) {
		Patient P1;
		if (P1.get_nUsers() > 0) {
			for (int i = 0; i < P1.get_nUsers(); i++)
			{
				if (name == P1.get_name(i))
				{
					return true;
				}
			}
		}
		return false;
	}

	string get_feedBack(int i)
	{
		return Feed_back[i];
	}
};