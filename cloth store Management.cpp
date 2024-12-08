#include <iostream>
#include <vector>
using namespace std;

class Cloth {
private:
    string item;
    int price, quantity;
    vector<Cloth> ve;

public:
    void add() {
        Cloth cloth;
        int choice = 1;
        while (choice != 0) {
            cout << "Enter name of clothing item: ";
            cin >> cloth.item;
            cout << "Enter price of clothing item: ";
            cin >> cloth.price;
            cout << "Enter quantity of clothing item: ";
            cin >> cloth.quantity;
            ve.push_back(cloth);
            cout << "Clothing item added!" << endl;
            cout << "Enter 1 to add more or 0 to exit: ";
            cin >> choice;
        }
    }

    void display() {
        if (ve.empty()) {
            cout << "No clothing items in the store!" << endl;
            return;
        }
        for (int i = 0; i < ve.size(); i++) {
            cout << "Name of clothing item: " << ve[i].item << endl;
            cout << "Price of clothing item: " << ve[i].price << endl;
            cout << "Quantity of clothing item: " << ve[i].quantity << endl << endl;
        }
    }

    void deleteCloth() {
        string n;
        cout << "Enter name of the item to delete: ";
        cin >> n;
        for (int i = 0; i < ve.size(); i++) {
            if (n == ve[i].item) {
                ve.erase(ve.begin() + i);
                cout << "Clothing item deleted!" << endl;
                return;
            }
        }
        cout << "Clothing item not found!" << endl;
    }

    void updateQuantity() {
        string n;
        int newQuantity;
        cout << "Enter name of the item to update quantity: ";
        cin >> n;
        for (int i = 0; i < ve.size(); i++) {
            if (n == ve[i].item) {
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                ve[i].quantity = newQuantity;
                cout << "Quantity updated for " << ve[i].item << "!" << endl;
                return;
            }
        }
        cout << "Clothing item not found!" << endl;
    }
};

int main() {
    Cloth cloth;
    cout << "***** Cloth Store *****" << endl << endl;
    int choice;

    while (true) {
        cout << "1. Add clothing item" << endl;
        cout << "2. Display clothing items" << endl;
        cout << "3. Delete clothing item" << endl;
        cout << "4. Update quantity of clothing item" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cloth.add();
        } else if (choice == 2) {
            cloth.display();
        } else if (choice == 3) {
            cloth.deleteCloth();
        } else if (choice == 4) {
            cloth.updateQuantity();
        } else if (choice == 0) {
            exit(0);
        } else {
            cout << "Invalid input!" << endl << endl;
        }
    }
}
