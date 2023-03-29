
#include <iostream>
#include "BSTNode.h"

using namespace std;
int BSTNode::getItem(){
    return item;
}
BSTNode::~BSTNode() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}