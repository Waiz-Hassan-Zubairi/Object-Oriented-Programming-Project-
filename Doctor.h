#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include "Admin.h"
using namespace std;


class Doctor {
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
	string Name;
	Admin AllAdmins;
	string experience;
	string specialization;
	string hospital;
	string City;
	string Availability_starts;
	string Availability_ends;
	string In_person;
	string Online;
	string *Experience;
	string *Specialization;
	string *Hospital;
	string *CITY;
	string *availability_starts;
	string* availability_ends;
	string* in_person_charges;
	string* online_charges;

public:
	//Constructor
	Doctor() {
		ifstream userFile;
		userFile.open("DoctorData.txt", ios::in);
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
		userFile.open("DoctorData.txt", ios::in);



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
		Experience = new string[count];
		Specialization = new string[count];
		Hospital = new string[count];
		availability_starts = new string[count];
		availability_ends = new string[count];
		CITY = new string[count];
		in_person_charges = new string[count];
		online_charges = new string[count];
		if (count != 0) {
			//cout << "Number of existing Users = " << count << endl;
			nUsers = count;

			//Now reading each line and storing the user
			string line;
			int counter_U = 0;
			while (getline(userFile, line)) {
				if (line != "") {
					stringstream ss(line);
					string TempValues[17];
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
					Experience[counter_U] = TempValues[9];
					Specialization[counter_U] = TempValues[10];
					Hospital[counter_U] = TempValues[11];
					availability_starts[counter_U] = TempValues[12];
					availability_ends[counter_U] = TempValues[13];
					CITY[counter_U] = TempValues[14];
					in_person_charges[counter_U] = TempValues[15];
					online_charges[counter_U] = TempValues[16];
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
	string get_exper(int num)
	{
		return Experience[num];
	}
	string get_hospital(int num)
	{
		return Hospital[num];
	}
	string get_charges1(int num)
	{
		return in_person_charges[num];
	}
	string get_charges2(int num)
	{
		return online_charges[num];
	}
	int get_nUsers()
	{
		return nUsers;
	}
	string get_special(int no_1)
	{
		return Specialization[no_1];
	}
	string get_location(int no_1)
	{
		return CITY[no_1];
	}
	string get_name(int no)
	{
		return First_name[no];
	}
	string get_avail_s(int num)
	{
		return availability_starts[num];
	}
	string get_avail_e(int num)
	{
		return availability_ends[num];
	}
	string get_contact(int num)
	{
		return contact_no[num];
	}
	string get_city(int num)
		{
		return city[num];
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
		if (nUsers > 0) 
		{
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
	int makeNewUser(string experi, string special, string Hospital, string availability_starts, string availability_ends, string city, string in_person, string Online )
	{



			// Setting all the values
			this->experience = experi;
			this->specialization = special;
			this->hospital = Hospital;
			this->Availability_starts = availability_starts;
			this->Availability_ends = availability_ends;
			this->City = city;
			this->In_person = in_person;
			this->Online = Online;


			// Now writing the information to the file
			ofstream writeToFile;

		
				writeToFile.open("DoctorData.txt", ios::app);
			

			writeToFile << ',';
			writeToFile << experience;
			writeToFile << ',';
			writeToFile << specialization;
			writeToFile << ',';
			writeToFile << hospital;
			writeToFile << ',';
			writeToFile << Availability_starts;
			writeToFile << ',';
			writeToFile << Availability_ends;
			writeToFile << ',';
			writeToFile << City;
			writeToFile << ',';
			writeToFile << In_person;
			writeToFile << ',';
			writeToFile << Online;
			writeToFile << endl;
			writeToFile.close();

			return 1;
	}
	




};

