//Author:   Yaseen Mohamed Kamal El-Olemy
//ID:       20230468

#include <iostream>
#include <string>
#include "MaxHeap.h"
#include <fstream>

using namespace std;


int main() {

    ifstream File("test.txt");
    string myText;
    int size = 0;


    while(getline(File, myText))        //count number of lines to get array size;
    {
        //cout << myText << endl;
        size++;
    }
    File.close();       //close to open again to actually read, seperated by whitespace
    ifstream Fileread("test.txt");

    patient *insertArr = new patient[size];
    for(int i = 0; i<size; ++i)
    {   //for each value for i, add into patient[i].name/severity/time
        Fileread >> insertArr[i].name;
        Fileread >> insertArr[i].severity;
        Fileread >> insertArr[i].arrival_time;
    }

    MaxHeap list(size);

    for(int i = 0; i < size; ++i)
    {
        list.insert(insertArr[i]);
        //cout << i << ": " << insertArr[i].name << " - " << insertArr[i].severity << " - " << insertArr[i].arrival_time << endl;
    }


    list.print_heap();
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;
    cout << "Treating: " << list.extract_max().name << endl;

    return 0;
}
