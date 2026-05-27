#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

public:

    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;

    Student* nextHash;

    Student(
        int id,
        string name,
        string car,
        int sem,
        float promedio,
        int score
    );
};

#endif