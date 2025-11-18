#include <iostream>
using namespace std;

// ---- Include your base and derived classes here ----
// #include "LibraryItem.h"
// #include "Book.h"
// #include "DVD.h"
// #include "Magazine.h"

// For demonstration, assume MAX_ITEMS is:
#define MAX_ITEMS 5

int main() {
    LibraryItem* libraryItems[MAX_ITEMS];

    // Populate array with different derived objects
    libraryItems[0] = new Book("The Hobbit", "J.R.R. Tolkien", 300);
    libraryItems[1] = new DVD("Inception", "Christopher Nolan", 148.5);
    libraryItems[2] = new Magazine("National Geographic", "NatGeo", 202);
    libraryItems[3] = new Book("1984", "George Orwell", 328);
    libraryItems[4] = new DVD("Avatar", "James Cameron", 162);

    // Demonstrate Polymorphism
    cout << "----- Checking Out Items -----\n";
    for (int i = 0; i < MAX_ITEMS; i++) {
        libraryItems[i]->checkOut();       // Polymorphic call
    }

    cout << "\n----- Displaying Details -----\n";
    for (int i = 0; i < MAX_ITEMS; i++) {
        libraryItems[i]->displayDetails(); // Polymorphic call
    }

    cout << "----- Returning Items -----\n";
    for (int i = 0; i < MAX_ITEMS; i++) {
        libraryItems[i]->returnItem();     // Polymorphic call
    }

    // Cleanup
    for (int i = 0; i < MAX_ITEMS; i++) {
        delete libraryItems[i];
    }

    return 0;
}
