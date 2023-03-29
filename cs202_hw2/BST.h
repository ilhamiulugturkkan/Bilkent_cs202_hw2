
#include <iostream>
#include "BSTNode.h"

using namespace std;

class BST{
public:
    BST();
    ~BST();
    void destroyTree(BSTNode *& treePtr);
    bool isEmpty();
    void insertItem(int key); // 5 points
    void deleteItem(int key); // 5 points
    int* inorderTraversal(int& length); // 5 points
    bool hasSequence(int* seq, int length);
    void printInorder(struct BSTNode* node);
    void copyTree(BSTNode *treePtr, BSTNode *& newTreePtr);

    BSTNode* root;
    int count;

};