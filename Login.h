#pragma once
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
class Login
{
private:

	Admin AllAdmins;
	Doctor AllDoctors;
	Patient AllPatients;
public:
	//Function to test wether login credentials entered are correct or not
	bool loginUser(string Fname, string pswd)
	{
		if (AllAdmins.test_Credentials(Fname, pswd) == true)
		{
			return true;
		}
		if (AllDoctors.test_Credentials(Fname, pswd) == true)
		{
			return true;
		}
		if (AllPatients.test_Credentials(Fname, pswd) == true)
		{
			return true;
		}


		return false;
	}
	bool loginUser(string pswd)
	{
		if (AllPatients.test_Credentials(pswd) == true)
		{
			return true;
		}
	}


};