#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include "Admin.h"
#include "Patient.h"
using namespace std;

class Appointment : public Doctor
{
	int nUsers;
	string doctor_name;
	string ways;
	string Name;
	string time;
	string* name;
	string* Doctor_name;
	string* Ways;
	string* Time;
public:
	Appointment()
	{
		ifstream userFile;
		userFile.open("appointmentData.txt", ios::in);
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
		userFile.open("appointment.txt", ios::in);



		//Now dynamically allocating the arrays according to the users
		Doctor_name = new string[count];
		Ways = new string[count];
		Time = new string[count];

		if (count != 0) {
			//cout << "Number of existing Users = " << count << endl;
			nUsers = count;

			//Now reading each line and storing the user
			string line;
			int counter_U = 0;
			while (getline(userFile, line)) {
				if (line != "") {
					stringstream ss(line);
					string TempValues[4];
					int tmp_Counter = 0;
					while (ss.good()) {
						getline(ss, TempValues[tmp_Counter], ',');
						tmp_Counter++;
					}
					name[counter_U] = TempValues[0];
					Doctor_name[counter_U] = TempValues[1];
					Ways[counter_U] = TempValues[2];
					Time[counter_U] = TempValues[3];
					
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
	void Booking()
	{

		for (int i = 0; i < get_nUsers(); i++)
		{
			cout << endl << endl;
			cout << "Doctor number " << i << endl;
			cout << "Doctor name : " << get_name(i) << endl;
			cout << "Doctor's contact no. " << get_contact(i) << endl;
			cout << "Residenial city : " << get_city(i) << endl;
			cout << "Hospital city : " << get_location(i) << endl;
			cout << "Doctor's experience : " << get_exper(i) << endl;
			cout << "Doctor's specialization : " << get_special(i) << endl;
			cout << "Doctor's availbility hours : " << get_avail_s(i) << "pm to " << get_avail_e(i) << "pm ." << endl;
			cout << "Booked Appointments at : " << time[i] << "pm " << ways[i];
			cout << "Face-to-Face Checkup charges : Rs" << get_charges1(i) << "/-" << endl;
			cout << "Online Checkup charges : Rs" << get_charges2(i) << "/-" << endl << endl;

		}
		cout << "Enter your name : ";
		cin >> Name;
		cout << "Enter doctor name you like to have appointment : ";
		cin >> doctor_name;
		cout << "Enter your checkup way (online/face-to-face) : ";
		cin >> ways;
		cout << "Enter time : ";
		cin >> time;
		ofstream writeToFile;
		writeToFile.open("appointmentData.txt", ios::app);
		while (1)
		{
			if ((name_verify(doctor_name) == true))
			{
				writeToFile << Name;
				writeToFile << ",";
				writeToFile << doctor_name;
				writeToFile << ",";
				writeToFile << ways;
				writeToFile << ",";
				cout << "Booking successfull!"<<endl;
				payment_transaction(doctor_name);
				break;
			}
			else
			{
				cout << "Invalid name !Can't book your appointment. Sorry !\nEnter name again : ";
				cin >> doctor_name;
			}
		}
		while (1)
		{
			if ((time_verify(time) == true))
			{
				writeToFile << time;
				writeToFile << endl;
				break;
			}
			else
			{
				cout << "Invalid Time ! Can't book your appointment. Sorry !\nEnter Time again : ";
				cin >> time;
			}
		}
	}

	bool time_verify(string time) {
		if (get_nUsers() > 0) {
			for (int i = 0; i < get_nUsers(); i++)
			{
				if (time > get_avail_s(i) && time < get_avail_e(i))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool name_verify(string name) {
		if (get_nUsers() > 0) {
			for (int i = 0; i < get_nUsers(); i++)
			{
				if (name == get_name(i))
				{
					return true;
				}
			}
		}
		return false;
	}
	void Appoint_cacelation_p(string name)
	{
		Patient P1;
		int j = 0;
		ofstream writeToFile;
		writeToFile.open("PatientData.txt", ios::app);
		if (P1.get_nUsers() > 0) {
			for (int i = 0; i < P1.get_nUsers(); i++)
			{
				if (Name ==P1.get_name(i))
				{
					j = i;
				}
				ifstream userFile;
				userFile.open("PatientData.txt", ios::in | ios::out);
				Name[j] = '\0';
				doctor_name[j] = '\0';
				ways[j] = '\0';
				time[j] = '\0';
					writeToFile<< Name[j];
					writeToFile << doctor_name[j];
					writeToFile << ways[j] ;
					writeToFile << time[j] ;

				
			}
		}
	}
	void Appoint_cacelation_d(string name)
	{
		Doctor D1;
		int j = 0;
		ofstream writeToFile;
		writeToFile.open("PatientData.txt", ios::app);
		if (D1.get_nUsers() > 0) {
			for (int i = 0; i < D1.get_nUsers(); i++)
			{
				if (Name == D1.get_name(i))
				{
					j = i;
				}
				ifstream userFile;
				userFile.open("PatientData.txt", ios::in | ios::out);
				Name[j] = '\0';
				doctor_name[j] = '\0';
				ways[j] = '\0';
				time[j] = '\0';
				writeToFile << Name[j];
				writeToFile << doctor_name[j];
				writeToFile << ways[j];
				writeToFile << time[j];


			}
		}
	}
	int get_Name(int i)
	{
		return Name[i];
	}
	int get_doctor(int i)
	{
		return doctor_name[i];
	}
	int get_ways(int i)
	{
		return ways[i];
	}
	int get_time(int i)
	{
		return time[i];
	}
};