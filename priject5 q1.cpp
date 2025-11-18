#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class LibraryItem {
protected:
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem(const string& t, const string& a)
        : title(t), author(a), dueDate("Not checked out") {}

    // Virtual Destructor
    virtual ~LibraryItem() {}

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    // Common Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

protected:
    // Protected setter for derived classes
    void setDueDate(const string& date) {
        dueDate = date;
    }
};

#endif
