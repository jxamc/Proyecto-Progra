// ============================
// CSVLoader.h
// ============================

#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <fstream>
#include <sstream>

#include "HashTable.h"
#include "AVL.h"

class CSVLoader {

public:

    static void loadCSV(
        string filename,
        HashTable& hash,
        AVLTree& avl
    );
};

#endif