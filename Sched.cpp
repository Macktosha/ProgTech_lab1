#include "Sched.h"

void Sched::set_Date(string date) {
	this->date = date;
}

void Sched::set_Ttable(string ttable) {
	this->time_table = ttable;
}

string Sched::get_Date() {
	return this->date;
}

string Sched::get_Ttable() {
	return this->time_table;
}

string Sched::entire_info() {

	string str = this->date + ","
		+ this->time_table;

	return str;
}