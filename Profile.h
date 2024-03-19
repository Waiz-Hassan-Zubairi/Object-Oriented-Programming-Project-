#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include "Patient.h"
#include"Appointment.h"
#include"Feedback.h"
using namespace std;
class Profile : public Doctor
{
public:
	int j = 0;
	Appointment A1;
	Doctor d1;
	Patient p1;
	void V_doctor(string Name)
	{


		if (d1.get_nUsers() > 0) {
			for (int i = 0; i < d1.get_nUsers(); i++)
			{
				if (Name == d1.get_name(i))
				{
					j = i;
				}
			}
			cout << endl << endl;
			cout << "Doctor name : " << d1.get_name(j) << endl;
			cout << "Doctor's contact no. " << d1.get_contact(j) << endl;
			cout << "Residenial city : " << d1.get_city(j) << endl;
			cout << "Hospital city : " << d1.get_location(j) << endl;
			cout << "Doctor's experience : " << d1.get_exper(j) << endl;
			cout << "Doctor's specialization : " << d1.get_special(j) << endl;
			cout << "Doctor's availbility hours : " << d1.get_avail_s(j) << "pm to " << d1.get_avail_e(j) << "pm ." << endl;
			cout << "Booked Appointments at : " << A1.get_time(j) << "pm " << A1.get_ways(j);
			cout << "Face-to-Face Checkup charges : Rs" << d1.get_charges1(j) << "/-" << endl;
			cout << "Online Checkup charges : Rs" << d1.get_charges2(j) << "/-" << endl << endl;
		}
		if (d1.get_nUsers() > 0) {
			feedback f1;
			Patient P1;
			for (int i = 0; i < P1.get_nUsers(); i++)
			{
				if (Name == P1.get_name(i))
				{
					j = i;
				}
			}

			cout << "Recent Feedbacks : " << f1.get_feedBack(j) << endl;
		}
	}

	void V_Patient(string Name)
	{


		if (d1.get_nUsers() > 0) {
			for (int i = 0; i < d1.get_nUsers(); i++)
			{
				if (Name == p1.get_name(i))
				{
					j = i;
				}
			}
			cout << endl << endl;
			cout << "Doctor name : " << p1.get_name(j) << endl;
			cout << "Doctor's contact no. " << p1.get_contact(j) << endl;
			cout << "Residenial city : " << p1.get_city(j) << endl;
			cout << "Your password : " << p1.get_Password(j) << endl;
			cout << "Booked Appointments at : " << A1.get_time(j) << "pm " << A1.get_ways(j);
		}

	}

};