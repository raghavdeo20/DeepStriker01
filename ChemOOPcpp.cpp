#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>

using namespace std;

class Experiment {
public:
    void addExperiment() {
        string description, chemicals, date;
        string experiment_id = generateUUID();
        cin.ignore();
        cout << "Enter experiment description: ";
        getline(cin, description);
        cout << "Enter the chemicals used (comma-separated): ";
        getline(cin, chemicals);
        cout << "Enter the date (DD-MM-YYYY): ";
        getline(cin, date);
        ofstream file("experiments.csv", ios::app);
        file << experiment_id << "," << date << "," << description << "," << chemicals << "\n";
        file.close();
        cout << "Experiment added successfully!\n";
    }

    void viewExperiments() {
        ifstream file("experiments.csv");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, date, desc, chems;
            getline(ss, id, ',');
            getline(ss, date, ',');
            getline(ss, desc, ',');
            getline(ss, chems);
            cout << "Experiment ID: " << id << "\nDate: " << date << "\nDescription: " << desc << "\nChemicals: " << chems << "\n-----------------------------\n";
        }
        file.close();
    }
};

class Chemical {
public:
    void addChemical() {
        string name, expiry_date, usage_percentage;
        string chemical_id = generateUUID();
        cin.ignore();
        cout << "Enter the chemical name: ";
        getline(cin, name);
        cout << "Enter the expiry date (DD-MM-YYYY): ";
        getline(cin, expiry_date);
        cout << "Enter the usage percentage: ";
        getline(cin, usage_percentage);
        ofstream file("chemical_inventory.csv", ios::app);
        file << chemical_id << "," << name << "," << expiry_date << "," << usage_percentage << "\n";
        file.close();
        cout << "Chemical added successfully!\n";
    }

    void viewChemicals() {
        ifstream file("chemical_inventory.csv");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, expiry, usage;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, expiry, ',');
            getline(ss, usage);
            cout << "Chemical ID: " << id << "\nName: " << name << "\nExpiry Date: " << expiry << "\nUsage Percentage: " << usage << "\n-----------------------------\n";
        }
        file.close();
    }
};

class Apparatus {
public:
    void addApparatus() {
        string name, quantity;
        string apparatus_id = generateUUID();
        cin.ignore();
        cout << "Enter the apparatus name: ";
        getline(cin, name);
        cout << "Enter the quantity: ";
        getline(cin, quantity);
        ofstream file("apparatus_inventory.csv", ios::app);
        file << apparatus_id << "," << name << "," << quantity << "\n";
        file.close();
        cout << "Apparatus added successfully!\n";
    }

    void viewApparatus() {
        ifstream file("apparatus_inventory.csv");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, qty;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, qty);
            cout << "Apparatus ID: " << id << "\nName: " << name << "\nQuantity: " << qty << "\n-----------------------------\n";
        }
        file.close();
    }
};

class SearchSystem {
public:
    void search(string keyword) {
        ifstream file;
        string line;

        cout << "Experiments:\n";
        file.open("experiments.csv");
        while (getline(file, line)) {
            stringstream ss(line);
            string id, date, desc, chems;
            getline(ss, id, ',');
            getline(ss, date, ',');
            getline(ss, desc, ',');
            getline(ss, chems);
            if (desc.find(keyword) != string::npos || date == keyword)
                cout << "Experiment ID: " << id << "\nDate: " << date << "\nDescription: " << desc << "\nChemicals: " << chems << "\n-----------------------------\n";
        }
        file.close();

        cout << "Chemicals:\n";
        file.open("chemical_inventory.csv");
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, expiry, usage;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, expiry, ',');
            getline(ss, usage);
            if (name.find(keyword) != string::npos || expiry == keyword)
                cout << "Chemical ID: " << id << "\nName: " << name << "\nExpiry Date: " << expiry << "\nUsage Percentage: " << usage << "\n-----------------------------\n";
        }
        file.close();

        cout << "Apparatus:\n";
        file.open("apparatus_inventory.csv");
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, qty;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, qty);
            if (name.find(keyword) != string::npos)
                cout << "Apparatus ID: " << id << "\nName: " << name << "\nQuantity: " << qty << "\n-----------------------------\n";
        }
        file.close();
    }
};

string generateUUID() {
    string uuid = "";
    string chars = "0123456789abcdef";
    for (int i = 0; i < 8; i++) uuid += chars[rand() % chars.size()];
    uuid += "-";
    for (int i = 0; i < 4; i++) uuid += chars[rand() % chars.size()];
    uuid += "-4";
    for (int i = 0; i < 3; i++) uuid += chars[rand() % chars.size()];
    uuid += "-";
    uuid += "a";
    for (int i = 0; i < 3; i++) uuid += chars[rand() % chars.size()];
    uuid += "-";
    for (int i = 0; i < 12; i++) uuid += chars[rand() % chars.size()];
    return uuid;
}

void clearScreen() {
    system("clear");
}

void codeRain() {
    clearScreen();
    cout << "Initializing Chemistry Lab Management System...\n\n";
    sleep(2);
    cout << "Booting up...\n\n";
    sleep(2);
    cout << "Loading modules...\n\n";
    sleep(2);
    cout << "Establishing connection...\n\n";
    sleep(2);
    cout << "System ready!\n\n";
}

int main() {
    srand(time(0));
    Experiment experiment;
    Chemical chemical;
    Apparatus apparatus;
    SearchSystem searchSystem;

    codeRain();

    while (true) {
        cout << "-------- Chemistry Lab Management System --------\n";
        cout << "1. Add Experiment\n2. View Experiments\n3. Add Chemical\n4. Add Apparatus\n5. View Chemical Inventory\n6. View Apparatus Inventory\n7. Search Experiments\n8. Search Chemicals\n9. Search Apparatus\n10. Exit\n";
        cout << "Enter your choice (1-10): ";
        string choice;
        cin >> choice;
        clearScreen();

        if (choice == "1") experiment.addExperiment();
        else if (choice == "2") experiment.viewExperiments();
        else if (choice == "3") chemical.addChemical();
        else if (choice == "4") apparatus.addApparatus();
        else if (choice == "5") chemical.viewChemicals();
        else if (choice == "6") apparatus.viewApparatus();
        else if (choice == "7" || choice == "8" || choice == "9") {
            cout << "Enter a keyword: ";
            string keyword;
            cin.ignore();
            getline(cin, keyword);
            searchSystem.search(keyword);
        } else if (choice == "10") {
            cout << "Exiting the program...\n";
            sleep(2);
            clearScreen();
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
