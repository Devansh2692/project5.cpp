#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =============================
// Base Class
// =============================
class LibraryItem {
protected:
    string title;
    bool isCheckedOut;

public:
    LibraryItem(string t) : title(t), isCheckedOut(false) {}
    virtual void display() = 0;
    virtual string getTitle() { return title; }

    bool getStatus() { return isCheckedOut; }

    void checkoutItem() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    virtual ~LibraryItem() {}
};

// =============================
// Book Class
// =============================
class Book : public LibraryItem {
    string author;
public:
    Book(string title, string author) : LibraryItem(title), author(author) {}

    void display() override {
        cout << "Book | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

// =============================
// DVD Class
// =============================
class DVD : public LibraryItem {
    int duration;
public:
    DVD(string title, int duration) : LibraryItem(title), duration(duration) {}

    void display() override {
        cout << "DVD  | Title: " << title
             << " | Duration: " << duration << " mins"
             << " | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

// =============================
// Library Catalog
// =============================
class LibraryCatalog {
private:
    vector<LibraryItem*> items;

public:
    void addItem(LibraryItem* item) {
        items.push_back(item);
    }

    void showCatalog() {
        cout << "\n----- Library Catalog -----\n";
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". ";
            items[i]->display();
        }
    }

    int searchItem(string keyword) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i]->getTitle() == keyword)
                return i;
        }
        return -1;
    }

    void checkoutItem(int index) {
        if (index >= 0 && index < items.size())
            items[index]->checkoutItem();
        else
            cout << "Invalid item.\n";
    }

    void returnItem(int index) {
        if (index >= 0 && index < items.size())
            items[index]->returnItem();
        else
            cout << "Invalid item.\n";
    }

    ~LibraryCatalog() {
        for (auto item : items)
            delete item;  // Free memory
    }
};

// =============================
// Main Menu
// =============================
int main() {
    LibraryCatalog catalog;
    int choice;

    // Add sample items
    catalog.addItem(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
    catalog.addItem(new DVD("Inception", 148));
    catalog.addItem(new Book("1984", "George Orwell"));

    do {
        cout << "\n===== Library Management System =====";
        cout << "\n1. Show Catalog";
        cout << "\n2. Search Item";
        cout << "\n3. Check Out Item";
        cout << "\n4. Return Item";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            catalog.showCatalog();
        }

        else if (choice == 2) {
            string title;
            cout << "Enter title to search: ";
            cin.ignore();
            getline(cin, title);

            int index = catalog.searchItem(title);
            if (index != -1)
                cout << "Item found:\n", catalog.checkoutItem(index);
            else
                cout << "Item not found.\n";
        }

        else if (choice == 3) {
            string title;
            cout << "Enter title to check out: ";
            cin.ignore();
            getline(cin, title);

            int index = catalog.searchItem(title);
            if (index != -1)
                catalog.checkoutItem(index);
            else
                cout << "Item not found.\n";
        }

        else if (choice == 4) {
            string title;
            cout << "Enter title to return: ";
            cin.ignore();
            getline(cin, title);

            int index = catalog.searchItem(title);
            if (index != -1)
                catalog.returnItem(index);
            else
                cout << "Item not found.\n";
        }

        else if (choice == 5) {
            cout << "Exiting system...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
