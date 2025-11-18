#ifndef CD_H
#define CD_H

#include <string>
#include <iostream>
using namespace std;

class CD {
private:
    string title;
    string artist;
    string id;
    int year;

public:
    CD(string t, string a, string i, int y)
        : title(t), artist(a), id(i), year(y) {}

    string getId() const { return id; }
    string getTitle() const { return title; }

    void printInfo() const {
        cout << "CD: " << title << " by " << artist
             << " (" << year << "), id: " << id << endl;
    }
};

#endif
