#include "Admin.h"

void Admin::set_Position(string pos) {
	this->position = pos;
}

void Admin::set_Respons(string resp) {
	this->respons = resp;
}

string Admin::get_Position() {
	return this->position;
} 

string Admin::get_Respons() {
	return this->respons;
}

string Admin::entire_info() {

	string str = this->get_Name() + ","
		+ this->position + ","
		+ this->respons;

	return str;
}