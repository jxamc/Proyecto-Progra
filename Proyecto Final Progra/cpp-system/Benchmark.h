// ============================
// Benchmark.h
// ============================

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "HashTable.h"
#include "AVL.h"
#include "Graph.h"

class Benchmark {

public:

    static void run(
        HashTable& hash,
        AVLTree& avl,
        Graph& graph
    );
};

#endif