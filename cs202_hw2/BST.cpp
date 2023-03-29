
#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
    count = 0;
}

BST::~BST()
{
    destroyTree(root);
}

void BST::destroyTree(BSTNode *&treePtr)
{

    if (treePtr != NULL)
    {
        destroyTree(treePtr->left);
        destroyTree(treePtr->right);
        delete treePtr;
        treePtr = NULL;
    }
}

bool BST::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}

// INSERTION
void insertHelpItem(BSTNode *&ptr, const int &item)
{
    if (ptr == NULL)
    {
        ptr = new BSTNode(item, NULL, NULL);
    }
    else if (item < ptr->getItem())
    {
        insertHelpItem(ptr->left, item);
    }
    else
        insertHelpItem(ptr->right, item);
}

void BST::insertItem(int key)
{
    insertHelpItem(root, key);
    count++;
}

// DELETION
void delHelperMethod(BSTNode *&ptr, int &item)
{
    if (ptr->left == NULL)
    {
        item = ptr->getItem();
        BSTNode *del = ptr;
        ptr = ptr->right;
        del->right = NULL;
        delete del;
    }
    else
    {
        delHelperMethod(ptr->left, item);
    }
}
void deleteHelpItem(BSTNode *&ptr, int item)
{
    if (ptr == NULL)
    {
        cout << "This BST does not include "<< item << endl;
    }
    else if (ptr->getItem() == item)
    { // Item found! 3 Posibilities
        // No children
        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            ptr = NULL;
        }
        else if (ptr->left == NULL)
        { // NO LEFT CHILD
            BSTNode *temp;
            temp = ptr;
            ptr = ptr->right;
            temp->right = NULL;
            delete temp;
        }
        else if (ptr->right == NULL)
        { // NO RIGHT CHILD
            BSTNode *temp;
            temp = ptr;
            ptr = ptr->left;
            temp->left = NULL;
            delete temp;
        }
        else{
            int rep;
            delHelperMethod(ptr->right, rep);
            ptr->item = rep;
        }
    }
    else if (item < ptr->getItem())
    {
        deleteHelpItem(ptr->left, item);
    }
    else
    {
        deleteHelpItem(ptr->right, item);
    }
}

void BST::deleteItem(int key)
{

    deleteHelpItem(root, key);
    count--;
}

void BST::printInorder(struct BSTNode *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->getItem() << " ";

    /* now recur on right child */
    printInorder(node->right);
}

void BST::copyTree(BSTNode *treePtr, BSTNode *&newTreePtr) //COUNT OLAYINI ÇÖZMEK LAZIM
{

    if (treePtr != NULL)
    { // copy node
        newTreePtr = new BSTNode(treePtr->getItem(), NULL, NULL);
        copyTree(treePtr->left, newTreePtr->left);
        copyTree(treePtr->right, newTreePtr->right);
    }
    else
        newTreePtr = NULL; // copy empty tree
}

int findMin(BSTNode *n)
{
    BSTNode *cur = n;
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur->getItem();
}

int* BST::inorderTraversal(int &length)
{
    int *arr = new int[count];
    int n = 0;
    BST *thing = new BST();
    copyTree(root, thing->root);
    while (n < count)
    {
        int i = findMin(thing->root);
        arr[n] = i;
        n++;
        thing->deleteItem(findMin(thing->root));
    }
    length = count;
    delete thing;
    return arr;
}

/*bool hasSequenceHelper(int *seq, int length, BSTNode *ptr)
{
    bool exists = false;
    bool arrGreat = true;
    bool arrLess = true;
    for (int i = 0; i < length; i++)
    {
        if (seq[i] == ptr->getItem())
        {
            exists = true;
        }
        if(seq[i] < ptr->getItem()){
            arrGreat = false;
        }
        if(seq[i] > ptr->getItem()){
            arrLess = false;
        }
    }
    if(exists){
        BST* temp = new BST();
        temp->copyTree(ptr,temp->root);
        //if(length != temp->count){return false;}
        for(int i = 0; i < length; i++){
            if(seq[i] != findMin(temp->root) || temp->root == NULL){
                delete temp;
                return false;
            }
            else{
                temp->deleteItem(seq[i]);
            }
        }
        if(temp->root == NULL) {
            delete temp;
            return true;
        }
        else{
            delete temp;
            return false;
        }
    }
    else if(arrGreat == true){
        return hasSequenceHelper(seq, length, ptr->right);
    }
    else if(arrLess == true){
        return hasSequenceHelper(seq, length, ptr->left);
    }
    else{
        return false;
    }
}*/
bool doesExists(int n,  BSTNode* ptr){
    if(n == ptr->getItem()){
        return true;
    }
    else if(ptr->right == nullptr && ptr->left == nullptr){
        return false;
    }
    else if(n < ptr->getItem() && ptr->left == nullptr){
        return false;
    }
    else if(n < ptr->getItem()){
        return doesExists(n, ptr->left);
    }
    else if(n > ptr->getItem() && ptr->right == nullptr){
        return false;
    }
    else if(n > ptr->getItem()){
        return doesExists(n, ptr->right);
    }
    else{
        return false;
    }
}
bool doesCons(int a, int b, BSTNode* ptr){//(arr[i],arr[i+1],ptr)
    if(b == a || ::abs(b-a) == 1){
        return true;
    }
    else{
        if(b-a < 0){ // means a > b
            for(int i = 1; i < a - b; i++){
                if(doesExists(b+i,ptr)){
                    return false;
                }
            }
        }
        else{
            for(int i = 1; i < b - a; i++){
                if(doesExists(a+i,ptr)){
                    return false;
                }
            }
        }
        return true;
    }
}
bool hasSequenceHelper(int *seq, int length, BSTNode *ptr){
    for(int i = 0; i < length-1;i++){
        if(!doesCons(seq[i],seq[i+1],ptr))
            return false;
    }
    for(int i = 0; i < length; i++){
        if(!doesExists(seq[i],ptr)){
            return false;
        }
    }
    return true;
}
bool BST::hasSequence(int *seq, int length)
{
    return hasSequenceHelper(seq,length,root);
}



