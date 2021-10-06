#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Conf.h"
#include"Speaker.h"
using namespace std;

int main()
{
    vector<Conf> v1;

    Speaker S("Anton","Space","SUAI","qqqqqq");
    v1.push_back(S);
 		return 0;
}

