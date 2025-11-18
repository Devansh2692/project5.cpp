#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
private:
    // Encapsulated private data members
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem(const string& t = "", const string& a = "", const string& d = "Not checked out")
        : title(t), author(a), dueDate(d) {}

    // ----- Getters -----
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getDueDate() const {
        return dueDate;
    }

    // ----- Setters -----
    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const string& newAuthor) {
        author = newAuthor;
    }

    void setDueDate(const string& newDueDate) {
        dueDate = newDueDate;
    }
};

#endif
