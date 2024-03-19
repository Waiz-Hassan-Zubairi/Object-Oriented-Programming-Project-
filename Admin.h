#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
using namespace std;


class Admin {
private:
	string* First_name;
	string* end_name;
	string* contact_no;
	string* city;
	string* DOB;
	string* Cnic;
	string* Password;
	string* CPassword;
	string* designation;
	int nUsers;

public:
	//Constructor
	Admin() {
		ifstream userFile;
		userFile.open("AdminData.txt", ios::in);
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
		userFile.open("AdminData.txt", ios::in);



		//Now dynamically allocating the arrays according to the users
		First_name = new string[count];
		end_name = new string[count];
		contact_no = new string[count];
		city = new string[count];
		Password = new string[count];
		CPassword = new string[count];
		DOB = new string[count];
		designation = new string[count];
		Cnic = new string[count];

		if (count != 0) {
			//cout << "Number of existing Users = " << count << endl;
			nUsers = count;

			//Now reading each line and storing the user
			string line;
			int counter_U = 0;
			while (getline(userFile, line)) {
				if (line != "") {
					stringstream ss(line);
					string TempValues[9];
					int tmp_Counter = 0;
					while (ss.good()) {
						getline(ss, TempValues[tmp_Counter], ',');
						tmp_Counter++;
					}
					First_name[counter_U] = TempValues[0];
					end_name[counter_U] = TempValues[1];
					contact_no[counter_U] = TempValues[2];
					city[counter_U] = TempValues[3];
					DOB[counter_U] = TempValues[4];
					Password[counter_U] = TempValues[5];
					CPassword[counter_U] = TempValues[6];
					designation[counter_U] = TempValues[7];
					Cnic[counter_U] = TempValues[8];
					counter_U++;
				}
			}
		}
		else {
			//cout << "No users exists" << endl;
			nUsers = 0;
		}
		userFile.close();

	}
	bool test_Credentials(string Name, string pswd) {
		if (nUsers > 0) {
			for (int i = 0; i < nUsers; i++)
			{
				if (First_name[i] == Name && Password[i] == pswd)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool testCNIC(string newCnic) {
		bool cnicExists = false;
		if (nUsers > 0) {
			for (int i = 0; i < nUsers; i++)
			{
				if (newCnic == Cnic[i])
				{
					return false;
				}
			}
		}
		return true;
	}

};

