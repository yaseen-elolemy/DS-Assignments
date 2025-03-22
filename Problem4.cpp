
#include <iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<string>
#include<type_traits>
using namespace std;
//Problem 4
template <typename T>
class SortingSystem {
private:
    bool First = true;
    int iter = 0;
    T* data;
    int size;

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
SortingSystem<T>::SortingSystem(int n) {
    this->size = n;
    this->data = new T[size];
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    cout << "\nEnding of the programm(:\n";
}

template <typename T>
void SortingSystem<T>::insertionSort() {
   
    cout << "Sorting using Insertion Sort...\n";
    cout << "Initial Data: ";
    displayData();
    int iter = 0;
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
        cout << "Iteration " << i + 1 << ": ";
        displayData();
    }  
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
  
    cout << "Sorting using Bubble Sort...\n";
    cout << "Initial Data: ";
    displayData();
    int iter = 0;
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
    int iter = 0;
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
        vector<int> output(size);
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
template <typename T>
void SortingSystem<T>::bucketSort() {
    cout << "Bucket sort is NOT supported for this type.\n";
}
// Specialization for int
template <>
void SortingSystem<int>::bucketSort() {
    cout << "Sorting using Bucket Sort (int)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    vector<int> Temp(data, data + size);
    vector<vector<int>> buckets(bucketCount);
    int maxVal = *max_element(Temp.begin(), Temp.end());

    for (int num : Temp) {
        int bucketIndex = ((num * bucketCount) / (maxVal + 1));
        buckets[bucketIndex].push_back(num);
    }
    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (size_t j = 0; j < buckets[i].size(); j++) {
            cout << buckets[i][j];
            if (j < buckets[i].size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    Temp.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        Temp.insert(Temp.end(), bucket.begin(), bucket.end());
    }
    for (int i = 0; i < size; i++) {
        data[i] = Temp[i];
    }
}

// Specialization for float
template <>
void SortingSystem<float>::bucketSort() {
    cout << "Sorting using Bucket Sort (float)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    vector<float> Temp(data, data + size);
    vector<vector<float>> buckets(bucketCount);
    float maxVal = *max_element(Temp.begin(), Temp.end());

    for (float num : Temp) {
        // For floats, we assume numbers are non-negative.
        int bucketIndex = static_cast<int>((num * bucketCount) / (maxVal + 1.0f));
        buckets[bucketIndex].push_back(num);
    }
    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (size_t j = 0; j < buckets[i].size(); j++) {
            cout << buckets[i][j];
            if (j < buckets[i].size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    Temp.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        Temp.insert(Temp.end(), bucket.begin(), bucket.end());
    }
    for (int i = 0; i < size; i++) {
        data[i] = Temp[i];
    }
}

// Specialization for double
template <>
void SortingSystem<double>::bucketSort() {
    cout << "Sorting using Bucket Sort (double)..." << "\n";
    cout << "Initial Data: ";
    displayData();

    int bucketCount = 10;
    vector<double> Temp(data, data + size);
    vector<vector<double>> buckets(bucketCount);
    double maxVal = *max_element(Temp.begin(), Temp.end());

    for (double num : Temp) {
        // For doubles, we assume numbers are non-negative.
        int bucketIndex = static_cast<int>((num * bucketCount) / (maxVal + 1.0));
        buckets[bucketIndex].push_back(num);
    }
    cout << "Current buckets:\n";
    for (int i = 0; i < bucketCount; i++) {
        cout << "Bucket " << i << ": [";
        for (size_t j = 0; j < buckets[i].size(); j++) {
            cout << buckets[i][j];
            if (j < buckets[i].size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    Temp.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        Temp.insert(Temp.end(), bucket.begin(), bucket.end());
    }
    for (int i = 0; i < size; i++) {
        data[i] = Temp[i];
    }
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
    vector<T> Temp(size);

    // Gather input
    for (int i = 0; i < size; i++) {
        cout << "Enter data " << i + 1 << ": ";
        cin >> data[i];
        Temp[i] = data[i];
    }

    int choice;
    do {
        cout << "\nSelect a sorting algorithm:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";

        // Only show valid Count/ Radix for int:
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

        cout << "\nDo you want to sort another dataset? (y/n): ";
        char repeat;
        cin >> repeat;
        if (repeat == 'n' || repeat == 'N') {
            cout << "Thank you for using the sorting system! Goodbye!\n";
            break;
        }

        // Reset data to original for next iteration
        for (int i = 0; i < size; i++) {
            data[i] = Temp[i];
        }

    } while (true);
}



int main()
{
    int size;
    cout << "Enter the number of items to sort: ";
    cin >> size;
    cout << "the type of the Items:\n1. Integer\n2. Float\n3. Double\n4. Char\n5. String";
    cout << "Enter the type of the array:  ";
    string type;
    cin >> type;
	if (type == "1") {
		SortingSystem<int> sortingSystem(size);
		sortingSystem.showMenu();
	}
	else if (type == "2") {
		SortingSystem<float> sortingSystem(size);
		sortingSystem.showMenu();
	}
	else if (type == "3") {
		SortingSystem<double> sortingSystem(size);
		sortingSystem.showMenu();
	}
	else if (type == "4") {
		SortingSystem<char> sortingSystem(size);
		sortingSystem.showMenu();
	}
	else if (type == "5") {
		SortingSystem<string> sortingSystem(size);
		sortingSystem.showMenu();
	}
	else {
		cout << "Invalid type\n";
	}
    
} 
