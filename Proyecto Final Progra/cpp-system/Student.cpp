#include "Student.h"

Student::Student(
    int id,
    string name,
    string car,
    int sem,
    float promedio,
    int score
) {

    student_id = id;
    full_name = name;
    career = car;
    semester = sem;
    gpa = promedio;
    skill_score = score;

    nextHash = NULL;
}