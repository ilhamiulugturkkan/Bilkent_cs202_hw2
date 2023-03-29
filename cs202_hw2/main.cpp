
#include <iostream>
#include "analysis.h"

using namespace std;

BST* merge(const BST& tree1, const BST& tree2){
    BST* result = new BST();
    BST* t1 = new BST();
    BST* t2 = new BST();
    t1->count = tree1.count;
    t1->copyTree(tree1.root, t1->root);
    int k;
    int* arr = t1->inorderTraversal(k);
    for(int i = 0; i < k; i++){
        result->insertItem(arr[i]);
    }
    delete[]arr;
    t2->count = tree2.count;
    t2->copyTree(tree2.root, t2->root);
    arr = t2->inorderTraversal(k);
    for(int i = 0; i < k; i++){
        result->insertItem(arr[i]);
    }
    delete[]arr;
    delete t1;
    delete t2;
    return result;
}

void timeAnalysis(){
    int length = 15000;
    int timePeriod = 1500;
    analysis* aga = new analysis();
    (*aga).printTheResults(length,timePeriod);
    delete aga;
}

int main()
{

    //IsEmpty, printInOrder, Insertion, and Deletion Control
    BST *zort = new BST();
    cout << "Is bst empty?: "<<(*zort).isEmpty() << endl;
    (*zort).insertItem(8);
    (*zort).insertItem(4);
    cout <<"Is bst empty?: "<< (*zort).isEmpty() << endl;
    (*zort).insertItem(6);
    (*zort).insertItem(5);
    (*zort).insertItem(3);
    (*zort).insertItem(1);
    (*zort).insertItem(2);
    (*zort).insertItem(13);
    (*zort).insertItem(12);
    (*zort).insertItem(10);
    (*zort).insertItem(15);
    (*zort).insertItem(14);
    cout<<endl;
    cout<<"Inorder traverse control:"<<endl<<endl;

    //InOrderTraversal Control
    int l;
    cout<< "Length of the array: ";
    int *arr = zort->inorderTraversal(l);
    cout << l << endl;
    cout<<"BST's elements in order: ";
    for (int i = 0; i < zort->count; i++)
        cout << arr[i] << ", ";
    cout<<endl;
    delete[]arr;


    //HasSequence Control
    int *arrr= new int[4];arrr[0]=6;arrr[1]=8;arrr[2]=10;arrr[3]=12;//arrr[4]=15;
    cout<<endl;
    cout<<"Does this BST has sequence of "<<arrr[0]<<", "<<arrr[1]<<", "<<arrr[2]<<", "<<arrr[3]<<" "<<"(1-True, 0-False): ";
    cout<<zort->hasSequence(arrr, 4);
    cout<<endl<<endl;
    delete[]arrr;


    //Merge Control
    BST *kort = new BST();
    (*kort).insertItem(1);
    (*kort).insertItem(0);
    (*kort).insertItem(3);
    (*kort).insertItem(10);
    (*kort).insertItem(16);
    (*kort).insertItem(34);
    (*kort).insertItem(12);
    cout<<"Other BST's elements in order: ";
    arr = kort->inorderTraversal(l);
    for (int i = 0; i < kort->count; i++)
        cout << arr[i] << ", ";
    cout<<endl;
    delete[]arr;
    cout<<endl;
    BST* res = merge(*zort, *kort);
    cout<<"Merged BST's elements in order: ";
    arr = res->inorderTraversal(l);
    for (int i = 0; i < res->count; i++)
        cout << arr[i] << ", ";
    cout<<endl;
    delete[]arr;
    timeAnalysis();
    delete res;
    delete zort;
    delete kort;
}