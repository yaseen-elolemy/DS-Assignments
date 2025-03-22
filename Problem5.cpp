#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
string type(T) {
    return "Unknown";
}

template <typename T>
class StatisticalCalculation {
    
private:
    T* data;
    int size;

public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();
    void Sort();
    double findMedian();
    T findMax();
    T findMin();
    double findMean();
    T findSummation();
    void inputData();
    void displayArray();
    void StatisticsMenue();
};

template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int size) {
    this->size = size;
    data = new T[size];
}

template <typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data;
    cout << "Ending(:";
}

template <typename T>
void StatisticalCalculation<T>::Sort() {
    for (int i = 1; i < size; i++) {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

template <typename T>
void StatisticalCalculation<T>::inputData() {
    for (int i = 0; i < size; i++) {
        cout << "Input element " << i + 1 << ": ";
        cin >> data[i];
    }
}

template <typename T>
void StatisticalCalculation<T>::displayArray() {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";
}

template <typename T>
double StatisticalCalculation<T>::findMean() {
    double Mean = data[0];
    for (int i = 1; i < size; i++) {
        Mean += data[i];
    }
    Mean = Mean / size;
    return Mean;
}

template <typename T>
T StatisticalCalculation<T>::findMax() {
    T Max = data[0];
    for (int i = 1; i < size; i++) {
        if (Max < data[i]) Max = data[i];
    }
    return Max;
}

template <typename T>
double StatisticalCalculation<T>::findMedian() {
    Sort();
    cout << "Sorted Elements :";
    displayArray();
    double Median;
    if (size % 2 != 0) {
        Median = static_cast<double>(data[size / 2]);
    } else {
        Median = (static_cast<double>(data[size / 2]) + static_cast<double>(data[size / 2 - 1])) / 2.0;
    }
    return Median;
}

template <typename T>
T StatisticalCalculation<T>::findMin() {
    T min = data[0];
    for (int i = 1; i < size; i++) {
        if (min > data[i]) min = data[i];
    }
    return min;
}

template <typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = data[0];
    for (int i = 1; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

template <typename T>
void StatisticalCalculation<T>::StatisticsMenue() {
    inputData();
    int choice;
    do {
        cout << "\nSelect a sorting algorithm:\n";
        cout << "1. Find Minimum\n";
        cout << "2. Find Maximum\n";
        cout << "3. Find Summation\n";
        cout << "4. Find Median\n";
        cout << "5. Find Mean\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
        case 4: cout << "Median: " << findMedian(); break;
        case 1: cout << "Minimum: " << findMin(); break;
        case 2: cout << "Maximum: " << findMax(); break;
        case 3: cout << "Summation: " << findSummation(); break;
        case 5: cout << "Mean: " << findMean(); break;
        default: cout << "Invalid choice. Try again.\n"; break;
        }
        cout << "\nDo you want to Find another Statistical Method? (y/n): ";
        char repeat;
        cin >> repeat;
        if (repeat == 'n' || repeat == 'N') {
            cout << "Thank you for using the StatisticalCalculation! Goodbye!\n";
            break;
        }
    } while (true);
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "the type of the array:\n1. Integer\n2. Float\n3. Double\n";
    cout << "Enter the type of the array:  ";
    string type;
    cin >> type;
    if (type == "1") {
        StatisticalCalculation<int> obj(size);
        obj.StatisticsMenue();
    } else if (type == "2") {
        StatisticalCalculation<float> obj(size);
        obj.StatisticsMenue();
    }
    else if (type == "3") {
        StatisticalCalculation<double> obj(size);
        obj.StatisticsMenue();
    }
    else {
        cout << "Invalid type. Try again.\n";
    }
    return 0;
}
