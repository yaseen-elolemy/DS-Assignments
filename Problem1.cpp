#include <iostream>

using namespace std;

class Guest {
private:
    string name;
    string contact;
    string iftar_date;

public:
    Guest(string n, string c, string d)  {
        name = n;
        contact = c;
        iftar_date = d;
    }

    string getName() const {
        return name;
    }

    string getContact() const {
        return contact;
    }

    string getIftarDate() const {
        return iftar_date;
    }

    void display_guest() const {
        cout << "Guest: " << name << ", Contact: " << contact
             << ", Iftar Date: " << iftar_date << endl;
    }

    void update_invitation(const string& new_date) {
        iftar_date = new_date;
    }
};


class IftarManager {
private:
    int size;
    int capacity;
    Guest** guest_list;

public:
    IftarManager(int initial_capacity = 100) {
        size = 0;
        capacity = initial_capacity;

        if (capacity <= 0) {
            capacity = 100;
        }
        guest_list = new Guest*[capacity];
    }

    ~IftarManager() {
        for (int i = 0; i < size; ++i) {
            delete guest_list[i];
        }
        delete[] guest_list;
    }

    void add_guest(Guest* guest) {
        if (size < capacity) {
            guest_list[size] = guest;
            size++;
        } else {
            cout << "Error: Guest list is full" << endl;
            delete guest;
        }
    }

    void display_all_guests() const {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size; i++) {
            guest_list[i]->display_guest();
        }
    }

    void update_guest_invitation(const string& name, const string& new_date) {
        cout << "Updating invitation for" << name << "..." << endl;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (guest_list[i]->getName() == name) {
                guest_list[i]->update_invitation(new_date);
                found = true;
                return;
            }
        }
        if (!found) {
            cout << "Guest not found!" << endl;
        }
    }
    void send_reminders(const string& date) const {
        cout << "Sending reminders for date: " << date << "..." << endl;
        bool reminder_sent = false;
        for (int i = 0; i < size; i++) {
            if (guest_list[i]->getIftarDate() == date) {
                cout << "Reminder sent to " << guest_list[i]->getName()
                     << ": Your Iftar invitation is on "
                     << guest_list[i]->getIftarDate() << "!" << endl;
                reminder_sent = true;
            }
        }
        if (!reminder_sent) {
            cout << "No guests found with an invitation for " << date << "." << endl;
        }
    }
    void sort_guest_list() {
        if (size < 2) return;

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (guest_list[j]->getIftarDate() > guest_list[j + 1]->getIftarDate()) {
                    Guest* temp = guest_list[j];
                    guest_list[j] = guest_list[j + 1];
                    guest_list[j + 1] = temp;
                }
            }
        }
    }
};
int main() {

    IftarManager manager;

    manager.add_guest(new Guest("Aisha", "aisha@gmail.com", "2025-03-15"));
    manager.add_guest(new Guest("Omar", "omark2@gmail.com", "2025-03-18"));
    manager.add_guest(new Guest("Zainab", "zainabha2@gmail.com", "2025-03-20"));

    cout << "Current Guest List" << endl;
    manager.display_all_guests();
    cout << endl;

    manager.update_guest_invitation("Omar", "2025-03-15");
    cout << endl;

    cout << "Updated Guest List" << endl;
    manager.display_all_guests();
    cout << endl;

    cout << "Sending Reminders" << endl;
    manager.send_reminders("2025-03-15");
    cout << endl;

    cout << "Sorting Guest List" << endl;

    manager.sort_guest_list();

    cout << "\nGuest list after sort by date:" << endl;
    manager.display_all_guests();
    cout << endl;

}
