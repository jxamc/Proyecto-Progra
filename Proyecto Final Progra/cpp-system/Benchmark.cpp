// ============================
// Benchmark.cpp
// ============================

#include "Benchmark.h"

#include <fstream>
#include <chrono>

using namespace chrono;

void Benchmark::run(
    HashTable& hash,
    AVLTree& avl,
    Graph& graph
) {

    ofstream out(
        "cpp_results.csv"
    );

    out
    << "language,operation,structure,records,time_ms\n";

    const int RECORDS = 10000;

    Student* students[RECORDS];

    for(int i = 0; i < RECORDS; i++) {

        students[i] =
            new Student(
                50000 + i,
                "Benchmark",
                "Systems",
                5,
                80,
                i
            );
    }

    auto start1 =
        high_resolution_clock::now();

    for(int i = 0; i < RECORDS; i++) {

        hash.insert(students[i]);
    }

    auto end1 =
        high_resolution_clock::now();

    double hashInsert =
        duration<double, milli>(
            end1 - start1
        ).count();

    out
    << "C++,insert,HashTable,"
    << RECORDS
    << ","
    << hashInsert
    << "\n";

    auto start2 =
        high_resolution_clock::now();

    for(int i = 0; i < RECORDS; i++) {

        hash.search(50000 + i);
    }

    auto end2 =
        high_resolution_clock::now();

    double hashSearch =
        duration<double, milli>(
            end2 - start2
        ).count();

    out
    << "C++,search,HashTable,"
    << RECORDS
    << ","
    << hashSearch
    << "\n";

    auto start3 =
        high_resolution_clock::now();

    for(int i = 0; i < RECORDS; i++) {

        avl.insert(students[i]);
    }

    auto end3 =
        high_resolution_clock::now();

    double avlInsert =
        duration<double, milli>(
            end3 - start3
        ).count();

    out
    << "C++,insert,AVL,"
    << RECORDS
    << ","
    << avlInsert
    << "\n";

    auto start4 =
        high_resolution_clock::now();

    avl.inorder();

    auto end4 =
        high_resolution_clock::now();

    double avlTraversal =
        duration<double, milli>(
            end4 - start4
        ).count();

    out
    << "C++,traversal,AVL,"
    << RECORDS
    << ","
    << avlTraversal
    << "\n";

    for(int i = 0; i < RECORDS - 1; i++) {

        graph.addConnection(
            i,
            i + 1
        );
    }

    auto start5 =
        high_resolution_clock::now();

    graph.BFS(0);

    auto end5 =
        high_resolution_clock::now();

    double bfsTime =
        duration<double, milli>(
            end5 - start5
        ).count();

    out
    << "C++,bfs,Graph,"
    << RECORDS
    << ","
    << bfsTime
    << "\n";

    auto start6 =
        high_resolution_clock::now();

    graph.DFS(0);

    auto end6 =
        high_resolution_clock::now();

    double dfsTime =
        duration<double, milli>(
            end6 - start6
        ).count();

    out
    << "C++,dfs,Graph,"
    << RECORDS
    << ","
    << dfsTime
    << "\n";

    out.close();

    cout
        << "cpp_results.csv generado\n";
}