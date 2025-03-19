#include <iostream>
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
    if(i1 = 2)
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
    if(i1 = 2)
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
    if(i2 = 2)
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
            subArr[i] = poly1[i];           //deal with negatives in subtraction
        }
    }

    cout << "Difference of polynomials: ";
    printer(subArr, lSize);
    cout << endl;

}


int main()
{
    //taking in first poly
    unsigned int size1;
    cout << "Order of first polynomial: ";
    cin >>  size1;
    cin.ignore();
    size1+=2;
    cout << "Enter Polynomial: ";

    int *arr1 = new int[size1];
    for(int i = 0; i < size1; ++i)
    {
        cin >> arr1[i];
    }


    //Taking in 2nd poly
    int size2;
    cout << "\nOrder of second polynomial: ";
    cin >>  size2;
    cin.ignore();
    size2+=2;
    cout << "Enter Polynomial: ";

    int *arr2 = new int[size2];
    for(int i = 0; i < size2; ++i)
    {
        cin >> arr2[i];
    }

    cout << "\n\n\n";
    output(arr1, size1, arr2, size2);      //I need to remember to not overcomplicate array pointer



    delete[] arr1; delete[] arr2;
    return 0;

}