// ============================
// AVL.cpp
// ============================

#include "AVL.h"

AVLNode::AVLNode(Student* s) {

    student = s;

    left = NULL;
    right = NULL;

    height = 1;
}

AVLTree::AVLTree() {

    root = NULL;
}

int AVLTree::getHeight(
    AVLNode* node
) {

    if(node == NULL) {

        return 0;
    }

    return node->height;
}

int AVLTree::getBalance(
    AVLNode* node
) {

    if(node == NULL) {

        return 0;
    }

    return
        getHeight(node->left)
        - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(
    AVLNode* y
) {

    AVLNode* x = y->left;

    AVLNode* T2 = x->right;

    x->right = y;

    y->left = T2;

    y->height =
        max(
            getHeight(y->left),
            getHeight(y->right)
        ) + 1;

    x->height =
        max(
            getHeight(x->left),
            getHeight(x->right)
        ) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(
    AVLNode* x
) {

    AVLNode* y = x->right;

    AVLNode* T2 = y->left;

    y->left = x;

    x->right = T2;

    x->height =
        max(
            getHeight(x->left),
            getHeight(x->right)
        ) + 1;

    y->height =
        max(
            getHeight(y->left),
            getHeight(y->right)
        ) + 1;

    return y;
}

AVLNode* AVLTree::insertNode(
    AVLNode* node,
    Student* student
) {

    if(node == NULL) {

        return new AVLNode(student);
    }

    if(student->skill_score <
       node->student->skill_score) {

        node->left =
            insertNode(
                node->left,
                student
            );
    }
    else {

        node->right =
            insertNode(
                node->right,
                student
            );
    }

    node->height =
        1 + max(
                getHeight(node->left),
                getHeight(node->right)
            );

    int balance =
        getBalance(node);

    if(balance > 1 &&
       student->skill_score <
       node->left->student->skill_score) {

        return rotateRight(node);
    }

    if(balance < -1 &&
       student->skill_score >
       node->right->student->skill_score) {

        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(
    Student* student
) {

    root =
        insertNode(root, student);
}

void AVLTree::inorderTraversal(
    AVLNode* node
) {

    if(node == NULL) {

        return;
    }

    inorderTraversal(node->left);

    cout
        << node->student->full_name
        << " Score: "
        << node->student->skill_score
        << endl;

    inorderTraversal(node->right);
}

void AVLTree::inorder() {

    inorderTraversal(root);
}

int AVLTree::treeHeight() {

    return getHeight(root);
}

AVLNode* AVLTree::minValueNode(
    AVLNode* node
) {

    AVLNode* current = node;

    while(current->left != NULL) {

        current = current->left;
    }

    return current;
}

AVLNode* AVLTree::deleteNode(
    AVLNode* root,
    int score
) {

    if(root == NULL) {

        return root;
    }

    if(score <
       root->student->skill_score) {

        root->left =
            deleteNode(
                root->left,
                score
            );
    }
    else if(score >
            root->student->skill_score) {

        root->right =
            deleteNode(
                root->right,
                score
            );
    }
    else {

        if(root->left == NULL ||
           root->right == NULL) {

            AVLNode* temp =
                root->left ?
                root->left :
                root->right;

            if(temp == NULL) {

                temp = root;

                root = NULL;
            }
            else {

                *root = *temp;
            }

            delete temp;
        }
    }

    return root;
}

void AVLTree::remove(int score) {

    root =
        deleteNode(root, score);
}