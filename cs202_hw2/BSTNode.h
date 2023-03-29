
#ifndef HW22_BSTNODE_H
#define HW22_BSTNODE_H
#include <iostream>

using namespace std;

class BSTNode{
public:
    BSTNode(){}
    BSTNode(const int& itemm, BSTNode* leftt = NULL, BSTNode* rightt = NULL):item(itemm), left(leftt), right(rightt){}
    ~BSTNode();
    int item;
    BSTNode* left;
    BSTNode* right;
    int getItem();

    friend class BST;
};
#endif //HW22_BSTNODE_H
