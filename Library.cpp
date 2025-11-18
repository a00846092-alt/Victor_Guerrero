#include "Library.h"
#include <iostream>

Book* Library::findBook(const string& isbn) {
    for (auto& book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

Member* Library::findMember(const string& memberId) {
    for (auto& member : members) {
        if (member.getId() == memberId) {
            return &member;
        }
    }
    return nullptr;
}

int Library::countActiveLoansForMember(const string& memberId) const {
    int count = 0;
    for (const auto& loan : loans) {
        if (loan.getMemberId() == memberId && loan.isActive()) {
            count++;
        }
    }
    return count;
}

bool Library::isBookAvailable(const string& isbn) const {
    for (const auto& loan : loans) {
        if (loan.getIsbn() == isbn && loan.isActive()) {
            return false; // there is an active loan for this book
        }
    }
    return true;
}

Loan* Library::findActiveLoan(const string& memberId, const string& isbn) {
    for (auto& loan : loans) {
        if (loan.getMemberId() == memberId &&
            loan.getIsbn() == isbn &&
            loan.isActive()) {
            return &loan;
        }
    }
    return nullptr;
}
CD* Library::findCD(const string& id) {
    for (auto& cd : cds) {
        if (cd.getId() == id) {
            return &cd;
        }
    }
    return nullptr;
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

void Library::listBooks() const {
    cout << "=== Books in library ===" << endl;
    for (const auto& book : books) {
        book.printInfo();
    }
    cout << endl;
}

void Library::listMembers() const {
    cout << "=== Members ===" << endl;
    for (const auto& member : members) {
        member.printInfo();
    }
    cout << endl;
}

void Library::listLoans(bool onlyActive) const {
    cout << (onlyActive ? "=== Active loans ===" : "=== All loans ===") << endl;
    for (const auto& loan : loans) {
        if (onlyActive && !loan.isActive()) {
            continue;
        }
        loan.printInfo();
    }
    cout << endl;
}

bool Library::borrowBook(const string& memberId, const string& isbn, const string& borrowDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Book* book = findBook(isbn);
    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }

    if (!isBookAvailable(isbn)) {
        cout << "Book is currently not available." << endl;
        return false;
    }

    int activeLoans = countActiveLoansForMember(memberId);
    if (activeLoans >= member->getMaxBooks()) {
        cout << "Member has reached the maximum number of active loans." << endl;
        return false;
    }

    // Create a new loan record
    loans.push_back(Loan(isbn, memberId, borrowDate));
    cout << "Book borrowed successfully." << endl;
    return true;
}

bool Library::returnBook(const string& memberId, const string& isbn, const string& returnDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Book* book = findBook(isbn);
    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }

    Loan* loan = findActiveLoan(memberId, isbn);
    if (!loan) {
        cout << "No active loan found for this member and book." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "Book returned successfully." << endl;
    return true;
}

bool Library::removeBook(string isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
            return true;
        }
    }
    cout << "Book not found." << endl;
    return false;
}

bool Library::removeMember(string memberId) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getId() == memberId) {
            members.erase(it);
            cout << "Member removed successfully." << endl;
            return true;
        }
    }
    cout << "Member not found." << endl;
    return false;
}

void Library::searchBook(string query, bool byIsbn) const {
    for (const auto& book : books) {
        if (byIsbn) {
            if (book.getIsbn() == query) {
                cout << "Book found (by ISBN):" << endl;
                book.printInfo();
                return;
            }
        } else {
            if (book.getTitle() == query) {
                cout << "Book found (by title):" << endl;
                book.printInfo();
                return;
            }
        }
    }
    cout << "Book not found." << endl;
}
void Library::addCD(const CD& cd) {
    cds.push_back(cd);
}

void Library::listCDs() const {
    cout << "=== CDs ===" << endl;
    for (const auto& cd : cds) {
        cd.printInfo();
    }
}

bool Library::borrowCD(const string& memberId, const string& cdId, const string& borrowDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    CD* cd = findCD(cdId);
    if (!cd) {
        cout << "CD not found." << endl;
        return false;
    }

    // Creamos un préstamo usando cdId como si fuera un "isbn"
    loans.push_back(Loan(cdId, memberId, borrowDate));
    cout << "CD borrowed successfully." << endl;
    return true;
}

bool Library::returnCD(const string& memberId, const string& cdId, const string& returnDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Loan* loan = findActiveLoan(memberId, cdId);
    if (!loan) {
        cout << "No active loan found for this member and CD." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "CD returned successfully." << endl;
    return true;
}
