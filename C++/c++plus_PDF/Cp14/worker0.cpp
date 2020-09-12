#include "worer0.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//must implement virtual destructor, even if pure
Worker::~Worker(){}

void Worker::Set()
{
    cout << "eneter worker's name: ";
    getlin(cin, fullname);
    cout << "enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "name: " << fullname << "\n";
    cout << "employee ID: " << id "\n";
}