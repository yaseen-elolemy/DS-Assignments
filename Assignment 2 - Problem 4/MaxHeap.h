//
// Created by Yaseen on 5/6/2025.
//

#pragma once

#ifndef DS2_MAXHEAP_H
#define DS2_MAXHEAP_H

#include <iostream>
#include <string>

using namespace std;


struct patient
{
    std::string name;
    unsigned int severity;
    unsigned int arrival_time;
};

void swap(patient *x, patient *y)
{
    patient temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap
{
private:
    int heapSize;
    int maxSize;
    patient *arr;

public:

    MaxHeap(int size) {
        heapSize = 0;
        maxSize = size;
        arr = new patient[size];
    }
    ~MaxHeap()
    {
        delete[] arr;
    }

    //saved as
    int insert(patient);    //setter

    patient extract_max();

    patient peek();

    void sort(patient x);

    void print_heap();

};




//---------------------------IMPLEMENTATION----------------------------


// Some indices


// To get parent: (i-1)/2
// Children: [(i * 2) + 1], [(i * 2) + 2]



int MaxHeap::insert(patient x)
        {
            heapSize++;
            int i = heapSize - 1;
            arr[i] = x;

            while(i != 0)
            {
                if(arr[(i-1)/2].severity < arr[i].severity)
                {swap(&arr[i], &arr[(i-1)/2]);
                i = (i-1)/2;
                }


                else if(arr[(i-1)/2].severity == arr[i].severity && arr[(i-1)/2].arrival_time > arr[i].arrival_time)        //severities are equal, but arrival of parrent is later than arrival of child, replace
                {
                    swap(&arr[i], &arr[(i-1)/2]);
                    i = (i-1)/2;

                }
                else
                    break;
            }
            return i;
        }

patient MaxHeap::extract_max() {
    patient temp = arr[0];
    arr[0] = arr[heapSize-1];
    heapSize--;
    int i = 0;
    while (true) {
        int left = (2*i) + 1;
        int right = (2*i) + 2;
        int largest = i;

        if (left < heapSize) {
            if (arr[left].severity > arr[largest].severity ||
                (arr[left].severity == arr[largest].severity && arr[left].arrival_time < arr[largest].arrival_time)) {
                largest = left;
            }
        }
        if (right < heapSize) {
            if (arr[right].severity > arr[largest].severity ||
                (arr[right].severity == arr[largest].severity && arr[right].arrival_time < arr[largest].arrival_time)) {
                largest = right;
            }
        }
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return temp;
}


void MaxHeap::sort(patient x)
{
    //TODO sort func
}

patient MaxHeap::peek()         //easiest method, implemented first
        {
            return arr[0];
        }

void MaxHeap::print_heap() {

   cout << "Displaying current full list: "<< endl;
    for(int i = 0; i < heapSize; ++i)
    {
        cout << i + 1 << ". "<< arr[i].name << " - "<< arr[i].severity << " - "<<arr[i].arrival_time << endl;
    }

}
#endif //DS2_MAXHEAP_H
