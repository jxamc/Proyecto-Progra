// ============================
// HashTable.h
// ============================

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

class HashTable {

private:

    static const int SIZE = 1009;

    Student* table[SIZE];

    int collisions;
    int totalStudents;

public:

    HashTable();

    int hashFunction(int id);

    void insert(Student* student);

    Student* search(int id);

    void remove(int id);

    void showAll();

    void stats();
};

#endif