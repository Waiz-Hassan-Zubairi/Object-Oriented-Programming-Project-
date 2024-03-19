#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include"Patient.h"
#include"Appointment.h"

using namespace std;
class Payment : public Doctor 
{
private:
	public:
		Doctor d1;
		Patient P1;
		Appointment A1;
		string j;
		string b;
		int payment_transaction(string name)
		{
			
				if (d1.get_nUsers() > 0)
				{
					for (int i = 0; i < d1.get_nUsers(); i++)
					{
						if (name == get_name(i))
						{
						 j=	P1.get_balance(i);
						
						} 
						
						{
							b = A1.get_ways(i);
						}
						if (b == "online")
						{
							j - A1.get_charges2();
						}
					}
				}
			}
		}

};