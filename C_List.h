#pragma once
#include <iostream>
#include <fstream>
#include "Conf.h"

using namespace std;

#pragma once 


typedef struct Element
{
	Conf* data;
	Element* pNext;
}Element;

class List
{
public:
	List();
	~List();

	// (��������� �������� �������)
	void Del_head();
	// �������� ����� ������
	void DelAll();

	List& operator++();//���������� � ����� �������

	friend List& operator--(List& L1);//������� �������� �� ����� 

	friend List& operator++(List& L2, int);//���������� � ������ ��������

	List& operator--(int);//�������� �� ������ ��������

	void Print_list();//������ ������

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();

	List& read_Speaker();

	

	

private:
	Element* Head;
	Element* Tail;
	

	
	int count;
	int cnt_sp, cnt_sc, cnt_ad;



};





