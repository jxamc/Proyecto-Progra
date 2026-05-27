// ============================
// AVL.h
// ============================

#ifndef AVL_H
#define AVL_H

#include "Student.h"

class AVLNode {

public:

    Student* student;

    AVLNode* left;
    AVLNode* right;

    int height;

    AVLNode(Student* s);
};

class AVLTree {

private:

    AVLNode* root;

    int getHeight(AVLNode* node);

    int getBalance(AVLNode* node);

    AVLNode* rotateRight(AVLNode* y);

    AVLNode* rotateLeft(AVLNode* x);

    AVLNode* insertNode(
        AVLNode* node,
        Student* student
    );

    void inorderTraversal(
        AVLNode* node
    );

    AVLNode* minValueNode(
        AVLNode* node
    );

    AVLNode* deleteNode(
        AVLNode* root,
        int score
    );

public:

    AVLTree();

    void insert(Student* student);

    void inorder();

    int treeHeight();

    void remove(int score);
};

#endif