﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Conf.h"
#include"Speaker.h"
#include"Admin.h" 
#include "Sched.h"
#include "C_List.h"
using namespace std;

int main()
{
	/*struct test
	{
		Conf* T;

	}test[3];

	Sched* S = new Sched;
	S->set_Date("today");
	S->set_Ttable("blah");

	test[0].T=S;

	cout << test[0].T->entire_info();
	delete S;*/
	List lst;
	lst.read_Speaker();
	   
		lst.Print_list();
				
 		return 0;
}

