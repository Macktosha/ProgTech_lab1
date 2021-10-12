#define _CRT_SECURE_NO_WARNINGS
#include "C_List.h"
#include "Conf.h"
#include "Sched.h"
#include "Admin.h"
#include "Speaker.h"
#include <string>

#include <iostream>


List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    count = 0;
    cnt_sp = cnt_ad = cnt_sc = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    return count;
}

List& List::operator++()//���������� � ����� �������
{
    string buffer;
    int choice = 0;
    cout << "Adding to the end\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    
    if (choice == 1) {
        Speaker* my_data = new Speaker;
        fstream f_speak;
        f_speak.open("speakers.csv", ios::out | ( cnt_sp ? ios::app : ios::trunc));


//���������� ������ �������
       
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter topic theme: ";
        cin >> buffer;
        my_data->set_Topic(buffer);

        cout << "\nEnter organization name: ";
        cin >> buffer;
        my_data->set_Company(buffer);

        cout << "\nEnter annotation: ";
        cin >> buffer;
        my_data->set_Annot(buffer);

        temp->data = my_data;

        f_speak << my_data->entire_info() << endl;
        f_speak.close();
        my_data->lines++;
        cnt_sp++;
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;
        fstream f_adm;
        f_adm.open("admins.csv", ios::out | (cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);


        cout << "\nEnter position: ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter responsibilities: ";
        cin >> buffer;
        my_data->set_Respons(buffer);

        temp->data = my_data;

        f_adm << my_data->entire_info() << endl;
        f_adm.close();
        my_data->lines++;
        cnt_ad++;
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;
        fstream f_sched;
        f_sched.open("schedule.csv", ios::out | (cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
        f_sched << my_data->entire_info() << endl;
        f_sched.close();
        my_data->lines++;
        cnt_sc++;
    }
    
    
    // �������� ������ ��������
    

    // ���������� �������
   // temp->data = my_data;
    // ��������� ������� �����������
    temp->pNext = NULL;

    if (count == 0)
    {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;

        while (p->pNext != NULL)
            p = p->pNext;

        p->pNext = temp;
    }
    count++;
    return *this;
}

List& operator--(List& L1) {//�������� �� ����� ������� �����

    if (L1.count == 0) {
        cout << "List is empty" << endl;
        return L1;
    }

    else if (L1.count == 1)
    {
        Element* temp = L1.Head;
        delete temp;
        L1.Head = L1.Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {

        Element* one = L1.Head;
        Element* two = L1.Head->pNext;
        while (two->pNext != NULL) {
            two = two->pNext;
            one = one->pNext;
        }
        one->pNext = NULL;
        delete two;
    }
    L1.count--;
    return L1;
}

List& List::operator--(int) {//�������� �� ������ ��������

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

    count--;

    return *this;
}

List& operator++(List& L2, int)//���������� � ������ �������� �����
{
    string buffer;
    int choice = 0;
    cout << "Adding to the head\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    if (choice == 1) {
        Speaker* my_data = new Speaker;
        fstream f_speak;
        f_speak.open("speakers.csv", ios::out | (L2.cnt_sp ? ios::app : ios::trunc));
        //���������� ������ �������

        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter topic theme: ";
        cin >> buffer;
        my_data->set_Topic(buffer);

        cout << "\nEnter organization name: ";
        cin >> buffer;
        my_data->set_Company(buffer);

        cout << "\nEnter annotation: ";
        cin >> buffer;
        my_data->set_Annot(buffer);

        temp->data = my_data;

        f_speak << my_data->entire_info() << endl;
        f_speak.close();
        my_data->lines++;
        L2.cnt_sp++;
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;
        fstream f_adm;
        f_adm.open("admins.csv", ios::out | (L2.cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);


        cout << "\nEnter position: ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter responsibilities: ";
        cin >> buffer;
        my_data->set_Respons(buffer);

        temp->data = my_data;

        f_adm << my_data->entire_info() << endl;
        f_adm.close();
        my_data->lines++;
        L2.cnt_ad++;
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;
        fstream f_sched;
        f_sched.open("schedule.csv", ios::out | (L2.cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
        f_sched << my_data->entire_info() << endl;
        f_sched.close();
        my_data->lines++;
        L2.cnt_sc++;
    }
    


    if (L2.Head == NULL)
    {
        temp->pNext = NULL;
        L2.Head = L2.Tail = temp;
    }
    else  if (L2.Head != NULL)
    {
        temp->pNext = L2.Head;
        L2.Head = temp;
    }
    L2.count++;
    return L2;
}

void List::Del_head()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del_head();
}

void List::Print_list()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;

    while (temp != 0)
    {
        // ������� ������
        cout << temp->data->entire_info() << " " << endl;;
        // ��������� �� ��������� �������
        temp = temp->pNext;

    }

    cout << "Tail of the list\n\n" << endl;
}

List& List::read_Speaker() {

   
    fstream f_sp;
    f_sp.open("speakers.csv", ios::in);
    string line1;
   
    char* words;
    //��������� ������ 
    while (getline(f_sp, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 1];
        string *sp_info = new string[4];

         strcpy(s_data, line1.c_str());


        //����� ���� ����� ������� � ��������� ������ ��� ���������� � ���� �������
        words = strtok(s_data, ",");
        int i = 0;
        while (words != NULL) {
            sp_info[i] = string(words);
            words = strtok(NULL, ",");
            i++;
        }
        Speaker* speak_f = new Speaker;
        speak_f->set_Name(sp_info[0]);
        speak_f->set_Topic(sp_info[1]);
        speak_f->set_Company(sp_info[2]);
        speak_f->set_Annot(sp_info[3]);

        speak_f->lines++;

        //���������� � ������ 
        Element* temp = new Element;

        temp->data = speak_f;
        temp->pNext = NULL;

        if (count == 0)
        {
            temp->pNext = nullptr;
            Head = Tail = temp;
        }
        else {
            Element* p = Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        count++;
        cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }
   
    
   
    
    f_sp.close();
    return *this;
  

}
