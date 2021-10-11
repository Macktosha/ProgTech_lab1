#include "C_List.h"
#include "Conf.h"
#include "Sched.h"
#include "Admin.h"
#include "Speaker.h"

#include <iostream>


List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    return count;
}

List& List::operator++()//добавление в конец префикс
{
    string buffer;
    int choice = 0;
    cout << "Adding to the end\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    
    if (choice == 1) {
        Speaker* my_data = new Speaker;
        fstream fspeak;
        fspeak.open("speakers.csv", ios::out | ( my_data->lines ? ios::app : ios::trunc));
//заполнение нового объекта
       
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

        fspeak << my_data->entire_info() << endl;
        fspeak.close();
        my_data->lines++;
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;

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
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;

        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
    }
    
    
    // создание нового элемента
    

    // заполнение данными
   // temp->data = my_data;
    // следующий элемент отсутствует
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

List& operator--(List& L1) {//удаление из конца префикс френд

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

List& List::operator--(int) {//удаление из начала постфикс

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

    count--;

    return *this;
}

List& operator++(List& L2, int)//добавление в начало постфикс френд
{
    string buffer;
    int choice = 0;
    cout << "Adding to the head\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    if (choice == 1) {
        Speaker* my_data = new Speaker;
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
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;

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
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;

        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
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
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del_head();
}

void List::Print_list()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;

    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data->entire_info() << " " << endl;;
        // Переходим на следующий элемент
        temp = temp->pNext;

    }

    cout << "Tail of the list\n\n" << endl;
}
