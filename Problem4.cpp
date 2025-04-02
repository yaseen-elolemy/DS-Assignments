
#include <iostream>
#include<chrono>
#include<cstring>
#include<algorithm>
#include<string>
#include <fstream> 
#include <sstream> 
#include<type_traits>
using namespace std;
template <typename T>
class SortingSystem {
private:
    bool First = true;
    int iter = 0;
    T* data;
    T*Temp;
    int size;
    void ReadDataFromFile(const string& filename, int testCaseNumber);
public:
    SortingSystem(int n);
    ~SortingSystem();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void radixSort();
    void bucketSort();
    void merge(int left, int mid, int right);
    int partition(int low, int high);
    void MergePointer();
    void QuickPointer();
    void displayData();
    void measureSortTime(void (SortingSystem::* sortFunc)());
    void showMenu();
};
template <typename T>
void SortingSystem<T>::ReadDataFromFile(const string& filename, int testCaseNumber) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file. Try again.\n";
        return;
    }
    string line;
    for (int i = 0; i < testCaseNumber; i++) {
        if (!getline(file, line)) {
            cout << "Error: Not enough test cases in the file.\n";
            return;
        }
    }
    istringstream iss(line);
    iss >> size;
    data = new T[size];
	Temp = new T[size];
    for (int i = 0; i < size; i++) {
        iss >> data[i];
		Temp[i] = data[i];
    }
    file.close();
}
template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    this->size = n;
    this->data = new T[size];
	this->Temp = new T[size];
}
template <typename T>
SortingSystem<T>::~SortingSystem() {
    cout << "\nEnding of the programm(:\n";
	delete[] data;
	delete[] Temp;
}
template <typename T>
void SortingSystem<T>::insertionSort() {
    cout << "Sorting using Insertion Sort...\n";
    cout << "Initial Data: ";
    displayData();
    for (int i = 1; i < size; i++) {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
        cout << "Iteration " << iter + 1 << ": ";
        displayData();
        iter++;
    }
   
}
template <typename T>
void SortingSystem<T>::selectionSort() {
    cout << "Sorting using Selection Sort...\n";
    cout << "Initial Data: ";
    displayData();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
        }
        cout << "Iteration " << iter + 1 << ": ";
        displayData();
		iter++;
    }  
}
template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout << "Sorting using Bubble Sort...\n";
    cout << "Initial Data: ";
    displayData();
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--)
            if (data[j - 1] > data[j])
                swap(data[j - 1], data[j]);
        cout << "Iteration " << iter + 1 << ": ";
        displayData();
        iter++;
    }
  
}
template <typename T>
void SortingSystem<T>::shellSort() {
    cout << "Sorting using Shell Sort...\n";
    cout << "Initial Data: ";
    displayData();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = data[i];
            int j = i;
            for (; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
        cout << "Iteration " << iter + 1 << ": ";
        displayData();
        iter++;
    }
   
}
template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    if (First) {
        cout << "Sorting using Merge Sort...\n";
        cout << "Initial Data: ";
        displayData();
        First = false;
    }
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort( left, mid);
        mergeSort( mid + 1, right);
        merge(left, mid, right);
        cout << "Iteration " << iter + 1 << ": ";
        displayData();
        iter++;
    }
    else return;
}
template <typename T>
void SortingSystem<T>::MergePointer() {
    mergeSort(0, size - 1);
}
template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    if (First) {
        cout << "Sorting using Quick Sort...\n";
        cout << "Initial Data: ";
        displayData();
        First = false;
    }
    if (left < right) {
        int pi = partition(left, right);
        quickSort( left, pi - 1);
        quickSort( pi + 1, right);
    }
   
   
}
template <typename T>
void SortingSystem<T>::QuickPointer() {
    quickSort(0, size - 1);
}
template <>
void SortingSystem<int>::countSort() {
    cout << "Sorting using Count Sort...\n";
    cout << "Initial Data: ";
    displayData();
    int* output = new int[size];
    int max = data[0];
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max) {
            max = data[i];
        }
    }
     
    int* count = new int[max+1]();
    for (int i = 0; i < size; i++) {
        count[data[i]] += 1;
    }
    cout << "The 1st C data: [";
    for (int i = 0; i <= max; i++)
    {
        cout << count[i];
        if (i != max)cout << ", ";
    }cout << "]\n";

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    cout << "The 2st C data: [";
    for (int i = 0; i <= max; i++)
    {
        cout << count[i];
        if (i != max)cout << ", ";
    }
    cout << "]\n";
    for (int i = size - 1; i >= 0; i--) {
        output[count[data[i]] - 1] = data[i];
        count[data[i]]--;
    }
    for (int i = 0; i < size; i++) {
        data[i] = output[i];
    }
    delete[] output;
    delete[] count;
   

}
template <>
void SortingSystem<int>::radixSort() {
    cout << "Sorting using Radix Sort...\n";
    cout << "Initial Data: ";
    displayData();
    int max = data[0];
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max) {
            max = data[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
		int *output = new int[size];
        int count[10] = { 0 };
        for (int i = 0; i < size; i++) count[(data[i] / exp) % 10]++;
        cout << "The 1st C data: [";
        for (int i = 0; i <10; i++)
        {
            cout << count[i];
            if (i != 9)cout << ", ";
        }
        cout << "]\n";

        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        cout << "The 2st C data: [";
        for (int i = 0; i < 10; i++)
        {
            cout << count[i];
            if (i != 9)cout << ", ";
        }cout << "]\n";
        for (int i = size - 1; i >= 0; i--) {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }
        for (int i = 0; i < size; i++) data[i] = output[i];
        cout << "Current State: ";
        displayData();
    }   
}
template <>
void SortingSystem<int>::bucketSort() {
    cout << "Sorting using Bucket Sort (int)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    int maxVal = *max_element(data, data + size);

    int** buckets = new int* [bucketCount];
    int* bucketSizes = new int[bucketCount] {0};
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = (data[i] * bucketCount) / (maxVal + 1);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
    }

    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (int j = 0; j < bucketSizes[i]; j++) {
            cout << buckets[i][j];
            if (j < bucketSizes[i] - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
   

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
    
        for (int j = 1; j < bucketSizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }

        for (int j = 0; j < bucketSizes[i]; j++) {
            data[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}
template <>
void SortingSystem<float>::bucketSort() {
    cout << "Sorting using Bucket Sort (float)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    float maxVal = *max_element(data, data + size);

    float** buckets = new float* [bucketCount];
    int* bucketSizes = new int[bucketCount] {0};
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new float[size];
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>((data[i] * bucketCount) / (maxVal + 1.0f));
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
    }

    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (int j = 0; j < bucketSizes[i]; j++) {
            cout << buckets[i][j];
            if (j < bucketSizes[i] - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }

        for (int j = 0; j < bucketSizes[i]; j++) {
            data[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}
template <>
void SortingSystem<double>::bucketSort() {
    cout << "Sorting using Bucket Sort (double)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    double maxVal = *max_element(data, data + size);

    double** buckets = new double* [bucketCount];
    int* bucketSizes = new int[bucketCount] {0};
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new double[size];
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>((data[i] * bucketCount) / (maxVal + 1.0));
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
    }

    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (int j = 0; j < bucketSizes[i]; j++) {
            cout << buckets[i][j];
            if (j < bucketSizes[i] - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            double key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }

        for (int j = 0; j < bucketSizes[i]; j++) {
            data[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}
template <>
void SortingSystem<char>::bucketSort() {
    cout << "Sorting using Bucket Sort (char)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 128; 
    char** buckets = new char* [bucketCount];
    int* bucketSizes = new int[bucketCount] {0};

    for (int i = 0; i < bucketCount; i++)
        buckets[i] = new char[size];

    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>(data[i]);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
    }

    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            cout << "Bucket " << char(i) << ": [";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << (j < bucketSizes[i] - 1 ? ", " : "");
            }
            cout << "]\n";
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            data[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }

    delete[] buckets;
    delete[] bucketSizes;
}
template <>
void SortingSystem<string>::bucketSort() {
    cout << "Sorting using Bucket Sort (string)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 26;
    string** buckets = new string * [bucketCount];
    int* bucketSizes = new int[bucketCount] {0};

    for (int i = 0; i < bucketCount; i++)
        buckets[i] = new string[size];

    for (int i = 0; i < size; i++) {
        int bucketIndex = tolower(data[i][0]) - 'a';
        if (bucketIndex >= 0 && bucketIndex < 26) {
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
        }
    }

    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            cout << "Bucket " << char('a' + i) << ": [";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << (j < bucketSizes[i] - 1 ? ", " : "");
            }
            cout << "]\n";
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            string key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }

        for (int j = 0; j < bucketSizes[i]; j++) {
            data[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }

    delete[] buckets;
    delete[] bucketSizes;
}
template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* L = new T[n1];
    T* R = new T[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = data[mid + 1 + i];
    }
    cout << "The 1st data: [";
    for (int i = 0; i < n1; i++) {
        cout << L[i];
        if (i != n1 - 1)cout << ", ";
    }
    cout << "]\n";
    cout << "The 2nd data: [";
    for (int i = 0; i < n2; i++) {
        cout << R[i];
        if (i != n2 - 1)cout << ", ";
    }
    cout << "]\n";
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
template <typename T>
int SortingSystem<T>::partition(int low, int high) {
    T pivot = data[high];
    cout << "Pivot: " << pivot<<"->";
    cout << "[";
    for (int i = 0; i < size; i++) {
      
         cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return i + 1;
    
}
template <typename T>
void SortingSystem<T>::displayData() {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";
}
template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::* sortFunc)()) {
    auto start = chrono::high_resolution_clock::now();
    (this->*sortFunc)();
    auto stop = chrono::high_resolution_clock::now();
    cout << "Sorted Data: ";
    displayData();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Sorting Time: " << duration.count() / 1000000.0 << " seconds\n";
}
template <typename T>
void SortingSystem<T>::showMenu() {
    ReadDataFromFile("Problem4.txt", size);
	cout << "Sorting System\n";
	cout << "----------------\n";
    int choice;
    do {
        cout << "\nInitial Data: ";
        displayData();
        cout << "\nSelect a sorting algorithm:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        if constexpr (std::is_same_v<T, int>) {
            cout << "7. Count Sort\n";
            cout << "8. Radix Sort\n";
        }
        else {
            cout << "7. Count Sort (N/A for this type)\n";
            cout << "8. Radix Sort (N/A for this type)\n";
        }
        cout << "9. Bucket Sort\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;
        switch (choice) {
        case 1:
            measureSortTime(&SortingSystem::insertionSort);
            break;
        case 2:
            measureSortTime(&SortingSystem::selectionSort);
            break;
        case 3:
            measureSortTime(&SortingSystem::bubbleSort);
            break;
        case 4:
            measureSortTime(&SortingSystem::shellSort);
            break;
        case 5:
            measureSortTime(&SortingSystem::MergePointer);
            break;
        case 6:
            measureSortTime(&SortingSystem::QuickPointer);
            break;

        case 7:
            if constexpr (std::is_same_v<T, int>) {
                measureSortTime(&SortingSystem::countSort);
            }
            else {
                cout << "Count Sort is only available for int.\n";
            }
            break;

        case 8:
            if constexpr (std::is_same_v<T, int>) {
                measureSortTime(&SortingSystem::radixSort);
            }
            else {
                cout << "Radix Sort is only available for int.\n";
            }
            break;

        case 9:
            measureSortTime(&SortingSystem::bucketSort);
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
		iter = 0;
        cout << "\nDo you want to sort another dataset? (y/n): ";
        char repeat;
        cin >> repeat;
        if (repeat == 'n' || repeat == 'N') {
            cout << "Thank you for using the sorting system! Goodbye!\n";
            break;
        }
        for (int i = 0; i < size; i++) {
            data[i] = Temp[i];
        }

    } while (true);
}
int main()
{
       string type;
        cout << "the type of the Items:\n1. Integer\n2. Float\n3. Double\n4. Char\n5. String\n";
        cout << "Enter the type of the array:  ";
        cin >> type;
        if (type == "1") {
            SortingSystem<int> sortingSystem(1);
            sortingSystem.showMenu();
        }
        else if (type == "2") {
            SortingSystem<float> sortingSystem(2);
            sortingSystem.showMenu();
        }
        else if (type == "3") {
            SortingSystem<double> sortingSystem(3);
            sortingSystem.showMenu();
        }
        else if (type == "4") {
            SortingSystem<char> sortingSystem(4);
            sortingSystem.showMenu();
        }
        else if (type == "5") {
            SortingSystem<string> sortingSystem(5);
            sortingSystem.showMenu();
        }
        else {
            cout << "Invalid type\n";
        }
    
    
} 
