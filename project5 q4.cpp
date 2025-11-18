#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(const string& t, const string& a)
        : title(t), author(a), dueDate("Not checked out") {}

    virtual ~LibraryItem() {}

    // ----- Getters -----
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    // ----- Setters -----
    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setDueDate(const string& newDueDate) { dueDate = newDueDate; }

    // ----- Pure Virtual Functions -----
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

#endif
