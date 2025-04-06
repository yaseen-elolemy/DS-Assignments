//By: Yaseen Mohamed Kamal
//ID: 20230468


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


void printer(int *poly1, int size1) //utilizing function overloading
{
    int i1 = size1 - 1;
    while(i1 >= 3)
    {
        if(poly1[i1] != 0)
            cout << poly1[i1] << "x^" << i1-1 << " + ";
        
            i1--;
    }
    if(i1 == 2)
    {
        if(poly1[i1] == 0 && poly1[i1-1])
            cout << poly1[i1 - 1] << " = " << poly1[0];
        else if(poly1[i1-1] == 0 && poly1[i1])
            cout << poly1[i1] << "x "<< " = " << poly1[0];
        else if(poly1[i1] == 0 && poly1[i1] == 0)
            cout << " = " << poly1[0];
        else
            cout << poly1[i1] << "x + "<< poly1[i1 - 1] << " = " << poly1[0];
    }
    else if(i1 == 1)  
        cout << poly1[i1] << " = " << poly1[0]; //here poly1[i1] must equal 1


}


void printer(int* poly1, int size1,int* poly2, int size2)
{
    int i1 = size1 - 1, i2 = size2 - 1;
    
    //printing p1
    cout << "First polynomial: ";
    
    while(i1 >= 3)
    {
        if(poly1[i1] != 0)
            cout << poly1[i1] << "x^" << i1-1 << " + ";
        
            i1--;
    }
    if(i1 == 2)
    {
        if(poly1[i1] == 0 && poly1[i1-1])
            cout << poly1[i1 - 1] << " = " << poly1[0];
        else if(poly1[i1-1] == 0 && poly1[i1])
            cout << poly1[i1] << "x "<< " = " << poly1[0];
        else if(poly1[i1] == 0 && poly1[i1] == 0)
            cout << " = " << poly1[0];
        else
            cout << poly1[i1] << "x + "<< poly1[i1 - 1] << " = " << poly1[0];
    }
    else if(i1 == 1)  
        cout << poly1[i1] << " = " << poly1[0]; //here poly1[i1] must equal 1



    //printing p2

    cout << "\nSecond polynomial: ";
    
    while(i2 >= 3)
    {
        if(poly2[i2] != 0)
            cout << poly2[i2] << "x^" << i2-1 << " + ";
        
        i2--;
    }
    if(i2 == 2)
    {
        if(poly2[i2] == 0 && poly2[i2-1])
            cout << poly2[i2 - 1] << " = " << poly2[0];
        else if(poly2[i2-1] == 0 && poly2[i2])
            cout << poly2[i2] << "x "<< " = " << poly2[0];
        else if(poly2[i2] == 0 && poly2[i2] == 0)
            cout << " = " << poly2[0];
        else
            cout << poly2[i2] << "x + "<< poly2[i2 - 1] << " = " << poly2[0];
    }
    else if(i2 == 1)  
        cout << poly2[i2] << " = " << poly2[0]; //here poly1[i1] must equal 1

}


void output(int* poly1, int size1,int* poly2, int size2)    //args: each array and its size
{

    int lSize = (size1 >= size2) ? size1 : size2;
    int *addArr = new int[lSize];
    int *subArr = new int[lSize];
    printer(poly1, size1, poly2, size2);
    //--------------------------START ADDITION------------------------------------------

    for(int i = 0; i<lSize; ++i)
    {
        if(i < size1 && i < size2)
        {
            addArr[i] = poly1[i] + poly2[i];
        }
        else if(i >= size1)
        {
            addArr[i] = poly2[i];
        }
        else if(i >= size2)
        {
            addArr[i] = poly1[i];
        }
    }
    cout << "\nSum of polynomials: ";
    printer(addArr, lSize);
    cout << endl;
    //--------------------------START SUBTRACTION----------------------------------------

    for(int i = 0; i<lSize; ++i)
    {
        if(i < size1 && i < size2)
        {
            subArr[i] = poly2[i] - poly1[i];
        }
        else if(i >= size1)
        {
            subArr[i] = poly2[i];
        }
        else if(i >= size2)
        {
            subArr[i] = poly1[i];
            subArr[i] *= -1;           //deal with negatives in subtraction
        }
    }

    cout << "Difference of polynomials: ";
    printer(subArr, lSize);
    cout << endl;

}


int main()
{
    int choice;
    cout << "Would you like to take input from File[0] or Standard input[1]?\n-> ";
    cin >> choice;

    if (choice == 0)
    {
        string fname;
        cout << "Enter file name: ";
        cin >> fname;
        ifstream readfile(fname);

        if (!readfile.is_open())
        {
            cout << "Error: Could not open file.\n";
            return 1;
        }

        int testCases;
        readfile >> testCases; // Read the number of test cases

        for (int t = 0; t < testCases; ++t)
        {
            int size1, size2;
            int *arr1, *arr2;

            // Read first polynomial
            readfile >> size1;
            size1 += 2;
            arr1 = new int[size1];
            for (int i = 0; i < size1; ++i)
            {
                readfile >> arr1[i];
            }

            // Read second polynomial
            readfile >> size2;
            size2 += 2;
            arr2 = new int[size2];
            for (int i = 0; i < size2; ++i)
            {
                readfile >> arr2[i];
            }

            cout << "\nTest Case #" << t + 1 << ":\n";
            output(arr1, size1, arr2, size2);

            delete[] arr1;
            delete[] arr2;
        }

        readfile.close();
    }
    else if (choice == 1)
    {
        int size1, size2;
        int *arr1, *arr2;

        cout << "Order of first polynomial: ";
        cin >> size1;
        cin.ignore();
        size1 += 2;
        cout << "Enter Polynomial: ";
        arr1 = new int[size1];
        for (int i = 0; i < size1; ++i)
        {
            cin >> arr1[i];
        }

        cout << "\nOrder of second polynomial: ";
        cin >> size2;
        cin.ignore();
        size2 += 2;
        cout << "Enter Polynomial: ";
        arr2 = new int[size2];
        for (int i = 0; i < size2; ++i)
        {
            cin >> arr2[i];
        }

        cout << endl << endl;
        output(arr1, size1, arr2, size2);

        delete[] arr1;
        delete[] arr2;
    }
    else
    {
        cout << "Error: wrong choice, please try again...";
    }

    return 0;
}
