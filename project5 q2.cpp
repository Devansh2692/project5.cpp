#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Function to validate book quantity
void validateQuantity(int quantity) {
    if (quantity < 0) {
        throw invalid_argument("Error: Quantity cannot be negative.");
    }
}

// Function to validate ISBN format (simple check: must be 10 or 13 digits long)
void validateISBN(const string& isbn) {
    if (!(isbn.length() == 10 || isbn.length() == 13)) {
        throw invalid_argument("Error: ISBN must be 10 or 13 characters long.");
    }
    for (char c : isbn) {
        if (!isdigit(c)) {
            throw invalid_argument("Error: ISBN must contain only digits.");
        }
    }
}

int main() {
    try {
        int quantity;
        string isbn;

        cout << "Enter book quantity: ";
        cin >> quantity;

        validateQuantity(quantity);

        cout << "Enter ISBN: ";
        cin >> isbn;

        validateISBN(isbn);

        cout << "Book added successfully!\n";
        cout << "Quantity: " << quantity << ", ISBN: " << isbn << endl;

    }
    catch (const invalid_argument& e) {
        // Specific exception type for invalid inputs
        cout << e.what() << endl;
    }
    catch (const exception& e) {
        // General exception handler
        cout << "An unexpected error occurred: " << e.what() << endl;
    }
    catch (...) {
        // Catch-all for any other unknown exceptions
        cout << "Unknown exception occurred!" << endl;
    }

    return 0;
}
