#pragma once
#include "Conf.h"
using namespace std;
class Sched :
    public Conf
{
private:
    string date;
    string time_table;
public:
    Sched(){}

    Sched(string date, string time_table) {
        this->date = date;
        this->time_table = time_table;
    }

    ~Sched(){}

    void set_Date(string date);
    void set_Ttable(string ttable);

    string get_Date();
    string get_Ttable();

    virtual string entire_info() override;
};

