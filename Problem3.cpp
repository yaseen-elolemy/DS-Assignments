#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstring>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data <= value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(int index) {
        if (head == nullptr || index < 0) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            prev = current;
            current = current->next;
            currentIndex++;
        }
        if (current == nullptr) return;
        prev->next = current->next;
        delete current;
    }

    friend ostream& operator<<(ostream& os, const SortedLinkedList& list) {
        os << "[";
        Node* current = list.head;
        while (current != nullptr) {
            os << current->data;
            if (current->next != nullptr) {
                os << ", ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }

    int operator[](int index) {
        if (index < 0) {
            throw out_of_range("Index out of bounds");
        }
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        if (current == nullptr) {
            throw out_of_range("Index out of bounds");
        }
        return current->data;
    }

    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};


int main() {
    SortedLinkedList sll;

    sll.insert(9);
    sll.insert(7);
    sll.insert(8);
    sll.insert(5);
    sll.insert(6);
    sll.insert(4);
    sll.insert(2);
    sll.insert(3);
    sll.insert(1);
    cout << "After insertions: " << sll << endl;

    try {
        cout << "Element at index 0: " << sll[0] << endl;
        cout << "Element at index 4: " << sll[4] << endl;
        cout << "Element at index 8: " << sll[8] << endl;
        cout << "Element at index 10: " << sll[10] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    sll.remove(0);
    cout << "After removing index 0: " << sll << endl;

    sll.remove(3);
    cout << "After removing index 3: " << sll << endl;

    sll.remove(10);
    cout << "After attempting to remove out-of-bounds index: " << sll << endl;

    try {
        while (sll[0]!=-1) {
            sll.remove(0);
            cout << "After removing first element: " << sll << endl;
        }
    }
    catch (const out_of_range& e) {
        cout << "List is now empty. Exception: " << e.what() << endl;
    }


    return 0;
}

