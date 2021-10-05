#pragma once
#include <string>


using namespace std;

class Conf {
private:
	string naming;
	string topic;
public:
	
	void set_Name(string to_name);
	void set_Topic(string ttopic);

	string get_Name();
	string get_Topic();

	Conf() {}

	virtual ~Conf() = default; 

	Conf(string naming, string topic)
	{
		this->naming = naming;
		this->topic = topic;
	}

	virtual string entire_info() = 0;

};
