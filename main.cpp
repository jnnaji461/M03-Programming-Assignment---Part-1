/*
Program name: Personal_Computer_Inventory.cpp
Author: Judith Nnaji
Date: 11/14/2025
Purpose: This program tracks personal computer inventory for a small company.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

class PersonalComputer {
private:
    string manufacturer, formFactor, serialNumber, processor;
    int RAM;
    string storageType, storageSize;

    // Helper function to convert a string to lowercase 
    string toLowerCase(string str) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }
        return str;
    }

public:
    // Constructor with validation
    PersonalComputer(string m, string f, string s, string p, int r, string st, string ss) {
        if (m.empty() || f.empty() || s.empty() || p.empty() || st.empty() || ss.empty())
            throw invalid_argument("All fields must be filled in.");

        // Validate RAM
        if (r != 4 && r != 6 && r != 8 && r != 16 && r != 32 && r != 64)
            throw invalid_argument("Invalid RAM size. Must be 4, 6, 8, 16, 32, or 64 GB.");

        // Convert inputs to lowercase for validation
        string fLower = toLowerCase(f);
        string stLower = toLowerCase(st);
        string ssLower = toLowerCase(ss);

        // Validate form factor
        if (fLower != "laptop" && fLower != "desktop")
            throw invalid_argument("Invalid form factor. Must be 'Laptop' or 'Desktop'.");

        // Validate storage type
        if (stLower != "hdd" && stLower != "ssd" && stLower != "ufs")
            throw invalid_argument("Invalid storage type. Must be HDD, SSD, or UFS.");

        // Validate storage size
        if (ssLower != "128gb" && ssLower != "256gb" && ssLower != "512gb" &&
            ssLower != "1tb" && ssLower != "2tb")
            throw invalid_argument("Invalid storage size. Must be 128GB, 256GB, 512GB, 1TB, or 2TB.");

        // Assign values 
        manufacturer = m;
        formFactor = f;
        serialNumber = s;
        processor = p;
        RAM = r;
        storageType = st;
        storageSize = ss;
    }

    // Accessor methods
    string getManufacturer() const { return manufacturer; }
    string getFormFactor() const { return formFactor; }
    string getSerialNumber() const { return serialNumber; }
    string getProcessor() const { return processor; }
    int getRAM() const { return RAM; }
    string getStorageType() const { return storageType; }
    string getStorageSize() const { return storageSize; }

    // Mutator methods
    void setRAM(int newRAM) {
        if (newRAM != 4 && newRAM != 6 && newRAM != 8 && newRAM != 16 && newRAM != 32 && newRAM != 64)
            throw invalid_argument("Invalid RAM size. Must be 4, 6, 8, 16, 32, or 64 GB.");
        RAM = newRAM;
    }

    void setStorage(string type, string size) {
        string typeLower = toLowerCase(type);
        string sizeLower = toLowerCase(size);

        if (typeLower != "hdd" && typeLower != "ssd" && typeLower != "ufs")
            throw invalid_argument("Invalid storage type. Must be HDD, SSD, or UFS.");
        if (sizeLower != "128gb" && sizeLower != "256gb" && sizeLower != "512gb" &&
            sizeLower != "1tb" && sizeLower != "2tb")
            throw invalid_argument("Invalid storage size. Must be 128GB, 256GB, 512GB, 1TB, or 2TB.");

        storageType = type;
        storageSize = size;
    }

    // String representation
    string toString() const {
        return manufacturer + " " + formFactor + " | SN: " + serialNumber +
            " | " + processor + " | " + to_string(RAM) + "GB RAM | " +
            storageType + " " + storageSize;
    }
};

int main() {
    vector<PersonalComputer> inventory;
    char cont = 'y';

    cout << "=== Personal Computer Inventory System ===\n";

    while (tolower(cont) == 'y') {
        bool valid = false;

        while (!valid) {
            try {
                string m, f, s, p, st, ss;
                int r;

                cout << "\nManufacturer: ";
                getline(cin >> ws, m);
                cout << "Form Factor (Laptop/Desktop): ";
                getline(cin, f);
                cout << "Serial Number: ";
                getline(cin, s);
                cout << "Processor (e.g., i3, i5, i7, Ryzen 5): ";
                getline(cin, p);
                cout << "RAM (4, 6, 8, 16, 32, 64): ";
                cin >> r;
                cout << "Storage Type (HDD/SSD/UFS): ";
                getline(cin >> ws, st);
                cout << "Storage Size (128GB, 256GB, 512GB, 1TB, 2TB): ";
                getline(cin, ss);

                // Create the PC object - this validates ALL fields
                PersonalComputer pc(m, f, s, p, r, st, ss);
                inventory.push_back(pc);

                cout << "\nAdded: " << pc.toString() << endl;
                cout << "Total Computers in Inventory: " << inventory.size() << endl;
                valid = true;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
                cout << "Please re-enter this computer's details.\n";
                // Clear any potential errors in cin
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        cout << "\nAdd another? (Y/N): ";
        cin >> cont;
        cin.ignore(10000, '\n');
    }

    cout << "\n=== Complete Inventory ===\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << setw(2) << i + 1 << ". " << inventory[i].toString() << endl;
    }

    cout << "\nProgram ended successfully.\n";
    return 0;
}
