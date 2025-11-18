#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

// =========================
// main - Simple menu
// =========================
int main() {
    Library library;

    // Preload some sample data
    library.addBook(Book("Clean Code", "Robert C. Martin", "1111", 2008));
    library.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", "2222", 1999));
    library.addBook(Book("Design Patterns", "Gamma et al.", "3333", 1994));

    library.addMember(Member("Alice", "M01", 3));
    library.addMember(Member("Bob", "M02", 5));
    library.addCD(CD("Thriller", "MichaelJackson", "CD1", 1982));
    library.addCD(CD("BackInBlack", "ACDC", "CD2", 1980));


    int option;
    do {
        cout << "===== Library Menu =====" << endl;
        cout << "1. List books" << endl;
        cout << "2. List members" << endl;
        cout << "3. List all loans" << endl;
        cout << "4. List active loans" << endl;
        cout << "5. Borrow a book" << endl;
        cout << "6. Return a book" << endl;
        cout << "7. Remove a book" << endl;
        cout << "8. Remove a member" << endl;
        cout << "9. Search for a book" << endl;
        cout << "10. List CDs" << endl;
        cout << "11. Borrow a CD" << endl;
        cout << "12. Return a CD" << endl;

        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> option;

        if (option == 1) {
            library.listBooks();
        }
        else if (option == 2) {
            library.listMembers();
        }
        else if (option == 3) {
            library.listLoans(false);
        }
        else if (option == 4) {
            library.listLoans(true);
        }
        else if (option == 5) {
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 6) {
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 7) {
        string isbn;
        cout << "Enter ISBN to remove: ";
        cin >> isbn;

        if (library.removeBook(isbn))
            cout << "Book removed successfully." << endl;
        else
            cout << "Book not found." << endl;
    }
    else if (option == 8) {
        string memberId;
        cout << "Enter Member ID to remove: ";
        cin >> memberId;

        if (library.removeMember(memberId))
            cout << "Member removed successfully." << endl;
        else
            cout << "Member not found." << endl;
}
    else if (option == 9) {
        int type;
        cout << "Search by: 1) ISBN  2) Title: ";
        cin >> type;

        string query;

        if (type == 1) {
            cout << "Enter ISBN: ";
            cin >> query;        // sencillo: un solo string
            library.searchBook(query, true);
        } else {
            cout << "Enter title (no spaces): ";
            cin >> query;        // para no complicarnos con getline
            library.searchBook(query, false);
        }
}
        else if (option == 10) {
            library.listCDs();
        }
        else if (option == 11) {
            string memberId, cdId, date;
            cout << "Enter Member ID: ";
            cin >> memberId;
            cout << "Enter CD id: ";
            cin >> cdId;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowCD(memberId, cdId, date);
        }
        else if (option == 12) {
            string memberId, cdId, date;
            cout << "Enter Member ID: ";
            cin >> memberId;
            cout << "Enter CD id: ";
            cin >> cdId;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnCD(memberId, cdId, date);
        }


} while (option != 0);

cout << "Goodbye!" << endl;
return 0;
}
