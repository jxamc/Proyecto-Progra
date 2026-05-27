#include "CSVLoader.h"

void CSVLoader::loadCSV(
    string filename,
    HashTable& hash,
    AVLTree& avl
) {

    ifstream file(filename);

    if(!file.is_open()) {

        cout << "No se pudo abrir CSV\n";

        return;
    }

    string line;

    getline(file, line);

    while(getline(file, line)) {

        stringstream ss(line);

        string token;

        getline(ss, token, ',');
        int id = stoi(token);

        getline(ss, token, ',');
        string name = token;

        getline(ss, token, ',');
        string career = token;

        getline(ss, token, ',');
        int semester = stoi(token);

        getline(ss, token, ',');
        float gpa = stof(token);

        getline(ss, token, ',');
        int skill = stoi(token);

        Student* student =
            new Student(
                id,
                name,
                career,
                semester,
                gpa,
                skill
            );

        hash.insert(student);

        avl.insert(student);
    }

    file.close();

    cout << "CSV cargado\n";
}