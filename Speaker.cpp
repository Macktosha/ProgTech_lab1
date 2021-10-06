#include "Speaker.h"

void Speaker::set_Company(string comp) {
	this->company = comp;
}

void Speaker::set_Annot(string annot) {
	this->annotation = annot;
}

string Speaker::get_Annot() {
	return this->annotation;
}

string Speaker::get_Company() {
	return this->company;
}

string Speaker::entire_info() {
	string str = this->get_Name() + ","
		+ this->get_Topic() + ","
		+ this->company + ","
		+ this->annotation;

	return str;
}