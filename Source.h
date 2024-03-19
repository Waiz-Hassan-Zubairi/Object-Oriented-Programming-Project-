#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;






class Register
{
	private:
		string First_name;
		string end_name;
		string contact_no;
		string city;
		string DOB;
		string Cnic;
		string Password;
		string CPassword;
		string designation;
		Admin AllAdmins;
		Doctor AllDoctors;
		Patient AllPatients;

	
	public:
		int makeNewUser(string Fname, string Lname, string contactNo,string cnic, string City, string dob, string pswd, string Wpswd, string desg)
		{

			//Test CNIC before registration
			if (AllAdmins.testCNIC(cnic) == false)
			{
				return -1;
			}
			else if (AllDoctors.testCNIC(cnic) == false) {
				return -1;
			}
			else if (AllPatients.testCNIC(cnic) == false)
			{
				return -1;
			}
			else
			{


				// Setting all the values
				First_name = Fname;
				end_name = Lname;
				contact_no = contactNo;
				city = City;
				DOB = dob;
				Password = pswd;
				Cnic = cnic;
				CPassword = Wpswd;
				designation = desg;

				// Now writing the information to the file
				ofstream writeToFile;

				if (desg == "Admin")
				{
					writeToFile.open("AdminData.txt", ios::app);
				}
				else if (desg == "Patient")
				{
					writeToFile.open("PatientData.txt", ios::app);
				}
				else
				{
					writeToFile.open("DoctorData.txt", ios::app);
				}
				if (desg == "Doctor")
				{
					writeToFile << First_name;
					writeToFile << ',';
					writeToFile << end_name;
					writeToFile << ',';
					writeToFile << contact_no;
					writeToFile << ',';
					writeToFile << city;
					writeToFile << ',';
					writeToFile << DOB;
					writeToFile << ',';
					writeToFile << Password;
					writeToFile << ',';
					writeToFile << CPassword;
					writeToFile << ',';
					writeToFile << designation;
					writeToFile << ',';
					writeToFile << Cnic;
					writeToFile.close();

					return 1;
				}
				writeToFile << First_name;
				writeToFile << ',';
				writeToFile << end_name;
				writeToFile << ',';
				writeToFile << contact_no;
				writeToFile << ',';
				writeToFile << city;
				writeToFile << ',';
				writeToFile << DOB;
				writeToFile << ',';
				writeToFile << Password;
				writeToFile << ',';
				writeToFile << CPassword;
				writeToFile << ',';
				writeToFile << designation;
				writeToFile << ',';
				writeToFile << Cnic;
				writeToFile << endl;
				writeToFile.close();

				return 1;
			}
		}


};


