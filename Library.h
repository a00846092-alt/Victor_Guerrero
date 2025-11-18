#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "CD.h"


using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;
    vector<CD> cds;


    Book* findBook(const string& isbn);
    Member* findMember(const string& memberId);
    int countActiveLoansForMember(const string& memberId) const;
    bool isBookAvailable(const string& isbn) const;
    Loan* findActiveLoan(const string& memberId, const string& isbn);
    CD* findCD(const string& id);


public:
    void addBook(const Book& book);
    void addMember(const Member& member);
    void listBooks() const;
    void listMembers() const;
    void listLoans(bool onlyActive = false) const;
    bool borrowBook(const string& memberId, const string& isbn, const string& borrowDate);
    bool returnBook(const string& memberId, const string& isbn, const string& returnDate);
    bool removeBook(string isbn);
    bool removeMember(string memberId);
    void searchBook(string query, bool byIsbn) const;
    void addCD(const CD& cd);
    void listCDs() const;
    bool borrowCD(const string& memberId, const string& cdId, const string& borrowDate);
    bool returnCD(const string& memberId, const string& cdId, const string& returnDate);




};

#endif // LIBRARY_H

