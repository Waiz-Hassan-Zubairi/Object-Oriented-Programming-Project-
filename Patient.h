#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include"Doctor.h" 
using namespace std;


class Patient : public Doctor{
private:
	string Balance="3500";
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
	string* balance;

public:
	
	//Constructor
	Patient() {
		ifstream userFile;
		userFile.open("PatientData.txt", ios::in);
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
		userFile.open("PatientData.txt", ios::in);



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
		balance = new string[count];

		if (count != 0) {
			//cout << "Number of existing Users = " << count << endl;
			nUsers = count;

			//Now reading each line and storing the user
			string line;
			int counter_U = 0;
			while (getline(userFile, line)) {
				if (line != "") {
					stringstream ss(line);
					string TempValues[10];
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

					balance[counter_U] = TempValues[9];
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

	string get_name(int i)
	{
		return First_name[i];
	}
	string get_contact_no(int i)
	{
		return contact_no[i];
	}
	string get_city(int i)
	{
		return city[i];
	}
	string get_contact_no(int i)
	{
		return contact_no[i];
	}
	string get_Password(int i)
	{
		return Password[i];
	}
	bool test_Credentials(string Name, string pswd ) {
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
	bool test_Credentials(string pswd) {
		if (nUsers > 0) {
			for (int i = 0; i < nUsers; i++)
			{
				if (Password[i] == pswd)
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
	void set_balance(int BAlance)
	{
		Balance = BAlance;
	}
	string get_balance(int i)
	{
		return balance[i];
	}
	bool Update_password(string pswd,string oldPswd) {
		ofstream writeToFile;

		if (nUsers > 0) {
			writeToFile.open("PatientData.txt", ios::app);			
			for (int i = 0; i < nUsers; i++)
			{
				if (Password[i] == oldPswd && CPassword[i]==oldPswd)
				{

					ifstream userFile;
					userFile.open("PatientData.txt", ios::in|ios::out);
					Password[i] = pswd;
					CPassword[i] = pswd;
					cout << Password[i]<<endl;
					cout << CPassword[i] << endl;
					string line;
					size_t len = oldPswd.length();
					while(getline(userFile, line))
					{
						while (true)
						{
							size_t pos = line.find(oldPswd);
							if (pos != string::npos) {
								line.replace(pos, len, pswd);
								break;
							}
							else

								break;
						}

						writeToFile << line <<"\n";
					}
				}
			}
			
		}
		return false;
	}
	string Availability_S(string DOC_Name) {
		Doctor D3, D4;
		int j = D4.get_nUsers();
		if (j > 0) {
			for (int i = 0; i < j; i++)
			{
				if (DOC_Name == D3.get_name(i))
				{
					cout << "Doctor Availibility hours starts from  " << D3.get_avail_s(i)<<" pm to "<<D3.get_avail_e(i)<<" pm ." << endl;
				}
			}
		} return "0";
	}
	void Searching(int a)
	{
		int counter = 0;
		int counter_2 = 0;
		int counter_3 = 0;
		Doctor D3, D5;
		if (a == 1)
		{
			string category;

			cout << "Enter Category you want to search (ortho/Dermo/physician) : ";
			cin >> category;
			if (nUsers > 0) {
				for (int i = 0; i <= nUsers; i++)
				{


					if (category == D3.get_special(i))
					{
						counter++;
						cout << "Doctor " << D5.get_name(i) << " is avaiable as " << D3.get_special(i) << " specialist ." << endl;
					}



				}
				if (counter == 0)
				{
					cout << "No Doctor is avaiable!";
				}
			}

		}
	
		else if(a==2)
		{
			string location;

			cout << "Enter location where you want to search Doctor : ";
			cin >> location;
			if (nUsers > 0) {
				for (int i = 0; i <= nUsers; i++)
				{


					if (location == D3.get_location(i))
					{
						counter_2++;
						cout << "Doctor " << D5.get_name(i) << " is avaiable in " << D3.get_location(i) << " ." << endl;
					}



				}
				if (counter_2 == 0)
				{
					cout << "No Doctor is avaiable! ";
				}
			}
		}
		else if (a == 3)
		{
			string name;

			cout << "Enter Doctor's name : ";
			cin >> name;
			if (nUsers > 0) {
				for (int i = 0; i <= nUsers; i++)
				{


					if (name == D5.get_name(i))
					{
						counter_3++;
						cout << "Doctor " << D5.get_name(i) << " is avaiable ." << endl;
					}



				}
				if (counter_3 == 0)
				{
					cout << "No Doctor is avaiable! ";
				}
			}
		}
	}
};


