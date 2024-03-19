#include<iostream>
#include<fstream>
#include<string.h>
#include"Source.h"
#include"Patient.h"
#include"Login.h"
#include"Appointment.h"
#include"Profile.h"
using namespace std;

int main()
{
	Patient P1,P2,P3;
	
		
	string userDesg = "";
	while (1)
	{
		int tmpInputSec=-1;

		while (1)
		{
			cout << "------------------------------WElCOME TO OLADOC------------------------------"<<endl;
			cout << "Enter 2 for Doctor" << endl;
			cout << "Enter 3 for Patient" << endl;
			cout << "Enter 0 for Exit" << endl;
			cin >> tmpInputSec;

			if (tmpInputSec == 1)
			{
				userDesg = "Admin";
				break;
			}
			else if (tmpInputSec == 2)
			{
				userDesg = "Doctor";
				break;
			}
			else if (tmpInputSec == 3)
			{
				userDesg = "Patient";
				break;
			}
			else if (tmpInputSec == 0)
			{
				cout << "Goodbye!" << endl;
				return 0;
			}
			else {

				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid select again";
			}
		}

		//Admin login
		if (tmpInputSec == 1)
		{
			cout << "WELCOME TO Admin Panel" << endl;

			int userInput = 0;
			//Infinite loop to always show menu until exit
			while (1)
			{
				Register R1;
				Login L1;

				cout << "For Admin Registeration enter 1. \nFor Admin Login enter 2. \nFor Panel selection enter 0. \n: ";
				cin >> userInput;
				if (userInput == 1)
				{

					string first_name, last_name, no, cnic, citi, pasword, Cpasword, dob, desg;
					cout << "Enter your First Name : ";
					cin >> first_name;
					cout << "Enter your Last Name : ";
					cin >> last_name;
					cout << "Enter your Contact Number : ";
					cin >> no;

					bool noCheck = false;
					while (1) {
						for (int i = 0; i < no.length(); i++)
						{
							if (no[i] >= '0' && no[i] <= '9')
							{
								noCheck = true;
							}
							else {
								noCheck = false;
								break;
							}
						}
						if (noCheck == false) {
							cout << "Contact number must only contain numbers!" << endl;
							cout << "Enter contact again: ";
							no = "";
							cin >> no;
						}
						else {
							break;
						}
					}

					cout << "Enter your City : ";
					cin >> citi;
					cout << "Enter your DOB : ";
					cin >> dob;
					pasword = "";
					cout << "Enter your Password : ";
					cin >> pasword;
					int n = 0;
					n = pasword.length();
					bool passwordCheck = false;
					bool passwordCheck2 = false;
					bool passwordCheck3 = false;
					bool passwordCheck4 = false;
					bool passwordCheck5 = false;
					while (1)
					{

						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'a' && pasword[i] <= 'z') {
								passwordCheck = true;
								break;
							}
							else
							{
								passwordCheck = false;
							}
						}
						if (passwordCheck == false) {
							cout << "Password doesn't contain lower case letter" << endl;
						}
						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'A' && pasword[i] <= 'Z') {
								passwordCheck2 = true;
								break;
							}
							else
							{
								passwordCheck2 = false;
							}
						}
						if (passwordCheck2 == false) {
							cout << "Password doesn't contain Upper case letter" << endl;
						}

						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= 32 && pasword[i] <= 47) || (pasword[i] >= 58 && pasword[i] <= 64) || (pasword[i] >= 91 && pasword[i] <= 96) || (pasword[i] >= 123 && pasword[i] <= 126)) {
								passwordCheck3 = true;
								break;
							}
							else
							{
								passwordCheck3 = false;
							}
						}
						if (passwordCheck3 == false) {
							cout << "Password doesn't contain Special Character" << endl;
						}
						//Checking length of the password
						if (n >= 8)
						{
							passwordCheck4 = true;
						}
						else
						{
							passwordCheck4 = false;
							cout << "   Password should be of 8 characters atleast ! ";
						}
						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= '0' && pasword[i] <= '9'))
							{
								passwordCheck5 = true;
								break;
							}
							else
							{
								passwordCheck5 = false;

							}
						}
						if (passwordCheck5 == false) {
							cout << "Password should contain atleast one number" << endl;
						}
						if (passwordCheck && passwordCheck2 && passwordCheck3 && passwordCheck4 && passwordCheck5) {
							cout << endl << """Password is Valid""" << endl << endl;
						}
						else {
							pasword = "";
							cout << endl << "---------------------------------------Password invalid!-----------------------------------------\nPassword must be 8 characters long and\n the use of a minimum of one special character,\n uppercase, lowercase, and the numeric digit is a must." << endl;
							cout << "Enter your Password Again : ";
							cin >> pasword;
						}



						cout << "Confirm Password : ";
						cin >> Cpasword;
						if (Cpasword != pasword)
						{
							while (pasword != Cpasword)
							{
								cout << "Password not matched type again : ";
								cin >> Cpasword;
							}
						}
						if (pasword == Cpasword)
						{
							break;
						}

					}

					cin.clear();
					cin.ignore(100, '\n');

					cout << "Enter 13 digit CNIC: ";
					cin >> cnic;
					while (true) {
						if (cnic.length() == 13)
							break;
						else
							cout << "CNIC must be 13 digits" << endl;
						cout << "Enter again: ";
						cnic = "";
						cin >> cnic;
					}
					int tmpOutput = R1.makeNewUser(first_name, last_name, no, cnic, citi, dob, pasword, Cpasword, userDesg);
					if (tmpOutput == 1)
					{
						cout << "------------------------------------""Admin Registered Successfully""-------------------------------------------" << endl;
					}
					else
					{
						cout << endl << "CNIC already exists, registration failed, returning to Main Menu" << endl << endl;
					}

				}
				else if (userInput == 2)
				{
					cout << "Now Login Admin :" << endl;
					while (1)
					{
						int m = 0;
						int A_Option;
						string user_Name, user_Pswd, user_desg, CNIC;
						cout << "Enter your First Name : ";
						cin >> user_Name;
						cout << "Enter your Password : ";
						cin >> user_Pswd;


						if (L1.loginUser(user_Name, user_Pswd) == true) {
							cout << endl << "Login Successlly!!" << endl << endl;

							// What user does after login
							while (1)
							{
								cout << "Welcome Admin " << user_Name << endl;
								cout << "-------------------------MENU---------------------------";
								cout << "Press 1 for Doctor's Data : \nPress 2 for Patient's Data : \nPress 3 for Managing Doctor's Availability : \nPress 4 for Managing Doctor's Appointments : " << endl;
								break;
							}
						}
						else {
							cout << endl;
							cout << "Username/Password doesn't exist in the system" << endl;
							cout << "Returning to main menu " << endl << endl;;

						}
					}
				}
				else if (userInput == 0)
				{
					cout << endl;
					cout << "Allah Hafiz Dear Admin!" << endl;
					cout << endl << endl;
					break;
				}
				else {
					cout << endl;
					cout << "Invalid value entered" << endl;
					cout << endl << endl;
				}
			}
		}

		// Doctor's Panel
		else if (tmpInputSec == 2)
		{
			cout << "WELCOME To DOCTOR Panel" << endl;

			int userInput = 0;
			string Experience;
			string specialization;
			string hospital_name;
			string availability_starts;
			string availability_ends;
			string city;
			string in_person_charges;
			string online_charges;

			//Infinite loop to always show menu until exit
			while (1)
			{
				Register R1;
				Doctor d1;
				Login L1,L2;

				cout << "For Doctor Registeration enter 1. \nFor Doctor Login enter 2. \nFor Panel selection enter 0. \n: ";
				cin >> userInput;
				if (userInput == 1)
				{

					string first_name, last_name, no, cnic, citi, pasword, Cpasword, dob, desg;
					cout << "Enter your First Name : ";
					cin >> first_name;
					cout << "Enter your Last Name : ";
					cin >> last_name;
					cout << "Enter your Contact Number : ";
					cin >> no;

					bool noCheck = false;
					while (1) {
						for (int i = 0; i < no.length(); i++)
						{
							if (no[i] >= '0' && no[i] <= '9')
							{
								noCheck = true;
							}
							else {
								noCheck = false;
								break;
							}
						}
						if (noCheck == false) {
							cout << "Contact number must only contain numbers!" << endl;
							cout << "Enter contact again: ";
							no = "";
							cin >> no;
						}
						else {
							break;
						}
					}

					cout << "Enter your City : ";
					cin >> citi;
					cout << "Enter your DOB : ";
					cin >> dob;
					pasword = "";
					cout << "Enter your Password : ";
					cin >> pasword;
					int n = 0;
					n = pasword.length();
					bool passwordCheck = false;
					bool passwordCheck2 = false;
					bool passwordCheck3 = false;
					bool passwordCheck4 = false;
					bool passwordCheck5 = false;
					while (1)
					{

						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'a' && pasword[i] <= 'z') {
								passwordCheck = true;
								break;
							}
							else
							{
								passwordCheck = false;
							}
						}
						if (passwordCheck == false) {
							cout << "Password doesn't contain lower case letter" << endl;
						}
						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'A' && pasword[i] <= 'Z') {
								passwordCheck2 = true;
								break;
							}
							else
							{
								passwordCheck2 = false;
							}
						}
						if (passwordCheck2 == false) {
							cout << "Password doesn't contain Upper case letter" << endl;
						}

						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= 32 && pasword[i] <= 47) || (pasword[i] >= 58 && pasword[i] <= 64) || (pasword[i] >= 91 && pasword[i] <= 96) || (pasword[i] >= 123 && pasword[i] <= 126)) {
								passwordCheck3 = true;
								break;
							}
							else
							{
								passwordCheck3 = false;
							}
						}
						if (passwordCheck3 == false) {
							cout << "Password doesn't contain Special Character" << endl;
						}
						//Checking length of the password
						if (n >= 8)
						{
							passwordCheck4 = true;
						}
						else
						{
							passwordCheck4 = false;
							cout << "   Password should be of 8 characters atleast ! ";
						}
						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= '0' && pasword[i] <= '9'))
							{
								passwordCheck5 = true;
								break;
							}
							else
							{
								passwordCheck5 = false;

							}
						}
						if (passwordCheck5 == false) {
							cout << "Password should contain atleast one number" << endl;
						}
						if (passwordCheck && passwordCheck2 && passwordCheck3 && passwordCheck4 && passwordCheck5) {
							cout << endl << """Password is Valid""" << endl << endl;
						}
						else {
							pasword = "";
							cout << endl << "---------------------------------------Password invalid!-----------------------------------------\nPassword must be 8 characters long and\n the use of a minimum of one special character,\n uppercase, lowercase, and the numeric digit is a must." << endl;
							cout << "Enter your Password Again : ";
							cin >> pasword;
						}



						cout << "Confirm Password : ";
						cin >> Cpasword;
						if (Cpasword != pasword)
						{
							while (pasword != Cpasword)
							{
								cout << "Password not matched type again : ";
								cin >> Cpasword;
							}
						}
						if (pasword == Cpasword)
						{
							break;
						}

					}

					cin.clear();
					cin.ignore(100, '\n');

					cout << "Enter 13 digit CNIC: ";
					cin >> cnic;
					while (true) {
						if (cnic.length() == 13)
							break;
						else
							cout << "CNIC must be 13 digits" << endl;
						cout << "Enter again: ";
						cnic = "";
						cin >> cnic;
					}
					int tmpOutput = R1.makeNewUser(first_name, last_name, no, cnic, citi, dob, pasword, Cpasword, userDesg);
					if (tmpOutput == 1)
					{
						cout << "--------------------------------""Doctor Registered Successfully""----------------------------------" << endl;
						cout << "Enter your Years of Experience : ";
						cin >> Experience;
						cout << "Enter your Specialization (ortho/Dermo/physician) : ";
						cin >> specialization;
						cout << "Enter your Hospital name : ";
						cin >> hospital_name;
						cout << "Enter your availability hours Starting Time : ";
						cin >> availability_starts;
						cout << "Enter your availability hours Ending Time : ";
						cin >> availability_ends;
						cout << "Enter charges of one in Person Appointment : ";
						cin >> in_person_charges;
						cout << "Enter charges of online checkups : ";
						cin >> online_charges;
						d1.makeNewUser(Experience, specialization, hospital_name, availability_starts,availability_ends, city,in_person_charges,online_charges);
					}
					else
					{
						cout << endl << "CNIC already exists, registration failed, returning to Main Menu" << endl << endl;
					}

				}
				else if (userInput == 2)
				{
					cout << "Now Login Doctor :" << endl;
					while (1)
					{
						Patient P1;
						int d_Option;
						int m = 0;
						string user_Name, user_Pswd,CNIC,your_name;
						cout << "Enter your First Name : ";
						cin >> user_Name;
						cout << "Enter your Password : ";
						cin >> user_Pswd;

						if (L1.loginUser(user_Name, user_Pswd) == true) {
							cout << endl << "Login Successlly!!" << endl << endl;

							// What user does after login
							while (1)
							{
								cout << "Welcome Doctor " << user_Name << endl;
								cout << "-------------------------MENU---------------------------"<<endl;
								cout << "Press 1 for checking your Appoinments : \nPress 2 for patients Details : \nPress 3 for Appointments cacellation : \nPress 4 for checking profile : \nPress 0 to go back" << endl;;
								cin >> d_Option;
								if (d_Option == 1)
								{
									

								}
								if (d_Option == 2)
								{

								}
								if (d_Option == 3)
								{

									Appointment A1;
									string name;
									cout << "Enter your name : ";
									cin >> name;
									A1.Appoint_cacelation_d(name);
									break;
								}
								if (d_Option == 4)
								{
									Profile P1;
									string NAME;
									cout << "Enter your name : ";
									cin >> NAME;
									P1.V_doctor(NAME);
								}
								if (d_Option == 0)
								{
									break;
								}
								break;
							}
						}
						else {
							cout << endl;
							cout << "Username/Password doesn't exist in the system" << endl;
							cout << "Returning to main menu " << endl << endl;;

						}
					}
				}
				else if (userInput == 0)
				{
					cout << endl;
					cout << "Allah Hafiz Respected Doctor!" << endl;
					cout << endl << endl;
					break;
				}
				else {
					cout << endl;
					cout << "Invalid value entered" << endl;
					cout << endl << endl;
				}
			}
		}

		//Patient Panel
		else if (tmpInputSec == 3)
		{
			cout << "WELCOME To Patient Panel" << endl;

			int userInput = 0;
			//Infinite loop to always show menu until exit
			while (1)
			{
				Register R1;
				Login L1,L2;

				cout << "For Patient Registeration enter 1. \nFor Patient Login enter 2. \nFor Panel selection enter 0. \n: ";
				cin >> userInput;
				if (userInput == 1)
				{

					string first_name, last_name, no, cnic, citi, pasword, Cpasword, dob, desg;
					cout << "Enter your First Name : ";
					cin >> first_name;
					cout << "Enter your Last Name : ";
					cin >> last_name;
					cout << "Enter your Contact Number : ";
					cin >> no;

					bool noCheck = false;
					while (1) {
						for (int i = 0; i < no.length(); i++)
						{
							if (no[i] >= '0' && no[i] <= '9')
							{
								noCheck = true;
							}
							else {
								noCheck = false;
								break;
							}
						}
						if (noCheck == false) {
							cout << "Contact number must only contain numbers!" << endl;
							cout << "Enter contact again: ";
							no = "";
							cin >> no;
						}
						else {
							break;
						}
					}

					cout << "Enter your City : ";
					cin >> citi;
					cout << "Enter your DOB : ";
					cin >> dob;
					pasword = "";
					cout << "Enter your Password : ";
					cin >> pasword;
					int n = 0;
					n = pasword.length();
					bool passwordCheck = false;
					bool passwordCheck2 = false;
					bool passwordCheck3 = false;
					bool passwordCheck4 = false;
					bool passwordCheck5 = false;
					while (1)
					{

						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'a' && pasword[i] <= 'z') {
								passwordCheck = true;
								break;
							}
							else
							{
								passwordCheck = false;
							}
						}
						if (passwordCheck == false) {
							cout << "Password doesn't contain lower case letter" << endl;
						}
						for (int i = 0; i < n; i++)
						{
							if (pasword[i] >= 'A' && pasword[i] <= 'Z') {
								passwordCheck2 = true;
								break;
							}
							else
							{
								passwordCheck2 = false;
							}
						}
						if (passwordCheck2 == false) {
							cout << "Password doesn't contain Upper case letter" << endl;
						}

						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= 32 && pasword[i] <= 47) || (pasword[i] >= 58 && pasword[i] <= 64) || (pasword[i] >= 91 && pasword[i] <= 96) || (pasword[i] >= 123 && pasword[i] <= 126)) {
								passwordCheck3 = true;
								break;
							}
							else
							{
								passwordCheck3 = false;
							}
						}
						if (passwordCheck3 == false) {
							cout << "Password doesn't contain Special Character" << endl;
						}
						//Checking length of the password
						if (n >= 8)
						{
							passwordCheck4 = true;
						}
						else
						{
							passwordCheck4 = false;
							cout << "Password should be of 8 characters atleast ! ";
						}
						for (int i = 0; i < n; i++)
						{
							if ((pasword[i] >= '0' && pasword[i] <= '9'))
							{
								passwordCheck5 = true;
								break;
							}
							else
							{
								passwordCheck5 = false;

							}
						}
						if (passwordCheck5 == false) {
							cout << "Password should contain atleast one number" << endl;
						}
						if (passwordCheck && passwordCheck2 && passwordCheck3 && passwordCheck4 && passwordCheck5) {
						}
						else {
							pasword = "";
							cout << endl << "--------------------------------------Password invalid!-----------------------------------------\n                             Password must be 8 characters long and                            \n the use of a minimum of one special character,                                  \n uppercase, lowercase, and the numeric digit is a must." << endl;
							cout << "Enter your Password Again : ";
							cin >> pasword;
						}



						cout << "Confirm Password : ";
						cin >> Cpasword;
						if (Cpasword != pasword)
						{
							while (pasword != Cpasword)
							{
								cout << "Password not matched type again : ";
								cin >> Cpasword;
							}
						}
						if (pasword == Cpasword)
						{
							break;
						}

					}

					cin.clear();
					cin.ignore(100, '\n');

					cout << "Enter 13 digit CNIC: ";
					cin >> cnic;
					while (true) {
						if (cnic.length() == 13)
						{
							int tmpOutput = R1.makeNewUser(first_name, last_name, no, cnic, citi, dob, pasword, Cpasword, userDesg);
							if (tmpOutput == 1)
							{
								cout << "---------------------------------------""Patient Registered Successfully""-------------------------------------------------" << endl;
								break;
							}
							else
							{
								cout << endl << "CNIC already exists, registration failed" << endl << endl;
							}
						}
						else
							cout << "CNIC must be 13 digits" << endl;
						cout << "Enter again: ";
						cnic = "";
						cin >> cnic;
					}


				}
				else if (userInput == 2)
				{

				string rst_password;
				string Crst_password;
				string cnic;
					cout << "Now Login Patient :" << endl;
					while (1)
					{
						int m = 0;
						string user_Name, user_Pswd,user_pwsd_rst;
						cout << "Enter your First Name : ";
						cin >> user_Name;
						cout << "Enter your Password : ";
						cin >> user_Pswd;
						if (L1.loginUser(user_Name, user_Pswd) == true) {
							cout << endl << "Login Successlly!!" << endl << endl;
							while (1)
							{
								// What user does after login
								while (1)
								{
									int option;
									cout << "Welcome Patient " << user_Name << endl;
									cout << "-------------------------- MENU-------------------------- - " << endl;
									cout << "For checking Balance press 1 :\nFor reseting password press 2 :\nFor searching Doctor press 3 :\nFor checking Doctor's availability hours press 4 :\nFor Booking appointment press 5 :\nFor Canceling appointment press 6 :\nFor Upadting appointment press 7 :\nFor Profile Details press 8 :\nFor Checking scheduled appointments press 9 :\nFor Account Recharge press 10 :\nFor going back press 0 : " << endl;;
									cout << "Press number according to your need : ";
									cin >> option;
									cout << endl << endl;
									if (option == 1)
									{
										cout << "Your balance is Rs " << P1.get_balance() << ".";
										break;
									}
									else if (option == 2)
									{
										cout << "Enter current password : ";
										cin >> user_pwsd_rst;
										if (L2.loginUser(user_pwsd_rst) == true)
										{
											cout << "Password matched successfully.\nEnter new Password";
											cin >> rst_password;

											int n = 0;
											n = rst_password.length();
											bool passwordCheck = false;
											bool passwordCheck2 = false;
											bool passwordCheck3 = false;
											bool passwordCheck4 = false;
											bool passwordCheck5 = false;
											while (1)
											{

												for (int i = 0; i < n; i++)
												{
													if (rst_password[i] >= 'a' && rst_password[i] <= 'z') {
														passwordCheck = true;
														break;
													}
													else
													{
														passwordCheck = false;
													}
												}
												if (passwordCheck == false) {
													cout << "Password doesn't contain lower case letter" << endl;
												}
												for (int i = 0; i < n; i++)
												{
													if (rst_password[i] >= 'A' && rst_password[i] <= 'Z') {
														passwordCheck2 = true;
														break;
													}
													else
													{
														passwordCheck2 = false;
													}
												}
												if (passwordCheck2 == false) {
													cout << "Password doesn't contain Upper case letter" << endl;
												}

												for (int i = 0; i < n; i++)
												{
													if ((rst_password[i] >= 32 && rst_password[i] <= 47) || (rst_password[i] >= 58 && rst_password[i] <= 64) || (rst_password[i] >= 91 && rst_password[i] <= 96) || (rst_password[i] >= 123 && rst_password[i] <= 126)) {
														passwordCheck3 = true;
														break;
													}
													else
													{
														passwordCheck3 = false;
													}
												}
												if (passwordCheck3 == false) {
													cout << "Password doesn't contain Special Character" << endl;
												}
												//Checking length of the password
												if (n >= 8)
												{
													passwordCheck4 = true;
												}
												else
												{
													passwordCheck4 = false;
													cout << "   Password should be of 8 characters atleast ! ";
												}
												for (int i = 0; i < n; i++)
												{
													if ((rst_password[i] >= '0' && rst_password[i] <= '9'))
													{
														passwordCheck5 = true;
														break;
													}
													else
													{
														passwordCheck5 = false;

													}
												}
												if (passwordCheck5 == false) {
													cout << "Password should contain atleast one number" << endl;
												}
												if (passwordCheck && passwordCheck2 && passwordCheck3 && passwordCheck4 && passwordCheck5) {
													cout << endl << """Password is Valid""" << endl << endl;
												}
												else {
													rst_password = "";
													cout << endl << "--------------------------------Password invalid!-----------------------------------------\nPassword must be 8 characters long and\n the use of a minimum of one special character,\n uppercase, lowercase, and the numeric digit is a must." << endl;
													cout << "Enter your Password Again : ";
													cin >> rst_password;
												}



												cout << "Confirm Password : ";
												cin >> Crst_password;

												while (rst_password != Crst_password)
												{
													cout << "Password not matched type again : ";
													cin >> Crst_password;
												}

												if (rst_password == Crst_password)
												{
													P2.Update_password(rst_password, user_Pswd);
													break;
												}

											}
										}
										
										break;
									}
									else if (option == 3)
									{

										int Selection;
										cout << "-------------------Sub-Menu--------------------" << endl;
										cout << "Want to search Category wise : Press 1. " << endl;
										cout << "Want to search Location wise : Press 2. " << endl;
										cout << "Want to search Doctor's name wise : Press 3. " << endl;
										cin >> Selection;
										P3.Searching(Selection);
										break;
									}
									else if (option == 4)
									{
										string your_name;
										cout << "Enter Doctor's name please : ";
										cin >> your_name;
										P1.Availability_S(your_name);

										break;
									}
									else if (option == 5)
									{
										Appointment A1;
										cout << "---------------- Booking Appointment -----------------------" << endl;

										A1.Booking();

										break;
									}
									else if (option == 6)
									{
									Appointment A1;
									string name;
									cout << "Enter your name : ";
									cin >> name;
									A1.Appoint_cacelation_p(name);
										break;
									}
									else if (option == 7)
									{

										break;
									}
									else if (option == 8)
									{
									Profile P1;
									string NAME;
									cout << "Enter your name please : ";
									cin >> NAME;
									P1.V_Patient(NAME);

										break;
									}
									else if (option == 9)
									{

										break;
									}
									else if (option == 10)
									{
									
										break;
									}
									else if (option == 0)
									{
									break;
 }
								}
								char feedback;
								cout << "Want to give feedback ? (Y/N). ";
								cin >> feedback;

							}
						}
						else {
							cout << endl;
							cout << "Username/Password doesn't exist in the system" << endl;
							cout << "Returning to main menu " << endl << endl;;

						}

						break;
					}
				}
				else if (userInput == 0)
				{
					cout << endl;
					cout << "Allah Hafiz Beloved Patient!" << endl;
					cout << endl << endl;
					break;
				}
				else {
					cout << endl;
					cout << "Invalid value entered" << endl;
					cout << endl << endl;
				}
			}

		 }
		
	}
	return 0;
}
