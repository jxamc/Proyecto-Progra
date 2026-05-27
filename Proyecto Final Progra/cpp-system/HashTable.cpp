// ============================
// HashTable.cpp
// ============================

#include "HashTable.h"

HashTable::HashTable() {

    collisions = 0;
    totalStudents = 0;

    for(int i = 0; i < SIZE; i++) {

        table[i] = NULL;
    }
}

int HashTable::hashFunction(int id) {

    return id % SIZE;
}

Student* HashTable::search(int id) {

    int index = hashFunction(id);

    Student* temp = table[index];

    while(temp != NULL) {

        if(temp->student_id == id) {

            return temp;
        }

        temp = temp->nextHash;
    }

    return NULL;
}

void HashTable::insert(Student* student) {

    if(search(student->student_id)
       != NULL) {

        cout << "ID duplicado\n";

        return;
    }

    int index =
        hashFunction(
            student->student_id
        );

    if(table[index] != NULL) {

        collisions++;
    }

    student->nextHash =
        table[index];

    table[index] = student;

    totalStudents++;
}

void HashTable::showAll() {

    for(int i = 0; i < SIZE; i++) {

        Student* temp = table[i];

        while(temp != NULL) {

            cout
                << temp->student_id
                << " - "
                << temp->full_name
                << endl;

            temp = temp->nextHash;
        }
    }
}

void HashTable::remove(int id) {

    int index =
        hashFunction(id);

    Student* temp =
        table[index];

    if(temp == NULL) {

        return;
    }

    if(temp->student_id == id) {

        table[index] =
            temp->nextHash;

        delete temp;

        totalStudents--;

        return;
    }

    while(temp->nextHash != NULL) {

        if(temp->nextHash->student_id
           == id) {

            Student* borrar =
                temp->nextHash;

            temp->nextHash =
                borrar->nextHash;

            delete borrar;

            totalStudents--;

            return;
        }

        temp = temp->nextHash;
    }
}

void HashTable::stats() {

    cout
        << "Total estudiantes: "
        << totalStudents
        << endl;

    cout
        << "Colisiones: "
        << collisions
        << endl;

    float factor =
        (float)totalStudents
        / SIZE;

    cout
        << "Factor carga: "
        << factor
        << endl;
}