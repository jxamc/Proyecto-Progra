#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
using namespace std;

class Project {
public:
    int project_id;
    string title;
    string description;
    int completion_year;

    Project* next;

    Project(
        int id,
        string t,
        string d,
        int year
    );
};

#endif