#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

struct Information {
    string name, address, product1, product2;
    int age, prprice1, prprice2, total;
};

int main() {
    map<int, Information> data;
    int choice, id;
    Information info;

    ifstream file("userinfo.txt");
    if (file.is_open()) {
        while (file >> info.name >> info.address >> info.age >> info.product1 >> info.product2 >> info.prprice1 >> info.prprice2 >> info.total) {
            data[data.size() + 1] = info;
        }
        file.close();
    }

    while (true) {
        cout << "Do you want to (1) Save\n(2) Retrieve information\n(3) Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "****Welcome to Walmart!!****\n";
            cout << "Please enter your name: ";
            cin >> info.name;

            cin.ignore(); // To ignore the newline left by previous cin
            cout << "Please enter your address: ";
            getline(cin, info.address);

            cout << "Enter the first product of choice: ";
            cin >> info.product1;

            cout << "Enter the second product of choice: ";
            cin >> info.product2;

            cout << "Please enter your age: ";
            cin >> info.age;

            cout << "Enter the price of the first product: ";
            cin >> info.prprice1;

            cout << "Enter the price of the second product: ";
            cin >> info.prprice2;

            info.total = info.prprice1 + info.prprice2;

            data[data.size() + 1] = info;
        } 
        else if (choice == 2) {
            cout << "Enter ID: ";
            cin >> id;
            if (data.count(id)) {
                Information info = data[id];
                cout << "\n****USER DETAILS****\n";
                cout << "NAME: " << info.name << endl;
                cout << "ADDRESS: " << info.address << endl;
                cout << "AGE: " << info.age << endl;
                cout << "FIRST PRODUCT: " << info.product1 << endl;
                cout << "SECOND PRODUCT: " << info.product2 << endl;
                cout << "FIRST PRODUCT PRICE: " << info.prprice1 << endl;
                cout << "SECOND PRODUCT PRICE: " << info.prprice2 << endl;
                cout << info.name << ", your purchase of " << info.product1 << " and " << info.product2 << " gives a total of $" << info.total << endl;
            } else {
                cout << "No information found with that ID." << endl;
            }
        } 
        else if (choice == 3) {
            ofstream file("userinfo.txt");
            for (auto& entry : data) {
                file << entry.second.name << " " << entry.second.address << " " << entry.second.age << " "
                     << entry.second.product1 << " " << entry.second.product2 << " " << entry.second.prprice1 << " "
                     << entry.second.prprice2 << " " << entry.second.total << endl;
            }
            file.close();
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
