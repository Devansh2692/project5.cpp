#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class
class LibraryItem {
protected:
    string title;
public:
    LibraryItem(string t) : title(t) {}
    virtual void display() = 0;      // Pure virtual function
    virtual ~LibraryItem() {}        // Virtual destructor
};

// Derived Class - Book
class Book : public LibraryItem {
    string author;
public:
    Book(string t, string a) : LibraryItem(t), author(a) {}
    void display() override {
        cout << "Book: " << title << " | Author: " << author << endl;
    }
};

// Derived Class - DVD
class DVD : public LibraryItem {
    int duration;
public:
    DVD(string t, int d) : LibraryItem(t), duration(d) {}
    void display() override {
        cout << "DVD: " << title << " | Duration: " << duration << " mins" << endl;
    }
};

// Library Catalog that uses pointers
class LibraryCatalog {
private:
    vector<LibraryItem*> items;  // stores pointers to dynamically allocated objects

public:
    // Add new item
    void addItem(LibraryItem* item) {
        items.push_back(item);
    }

    // Remove item at index
    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            delete items[index];                // free memory
            items.erase(items.begin() + index); // remove pointer
        }
    }

    // Display all items
    void showCatalog() {
        cout << "\n--- Library Catalog ---\n";
        for (auto item : items)
            item->display();
    }

    // Destructor → delete all pointers
    ~LibraryCatalog() {
        for (auto item : items)
            delete item;   // free memory
        items.clear();
    }
};

int main() {
    LibraryCatalog catalog;

    // Adding items using dynamic memory allocation
    catalog.addItem(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
    catalog.addItem(new DVD("Inception", 148));

    catalog.showCatalog();

    // Remove first item
    cout << "\nRemoving first item...\n";
    catalog.removeItem(0);

    catalog.showCatalog();

    return 0;
}
