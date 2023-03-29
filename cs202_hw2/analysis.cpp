#include "analysis.h"
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

void analysis::printTheResults(int length, int timePeriod){
    int* arr = new int[length];
    long* result1 = new long[length/timePeriod+1];
    for (int i = 0; i < length; i++) {
        arr[i] = 1 + rand() % length * 100;
    }
    //Insertion
    BST* tree = new BST();
    int k = 0;
    while(k < length/timePeriod){
        //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int result = 0;
      for(int i = 0; i < timePeriod;i++){
          std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
          tree->insertItem(arr[i + k * timePeriod]);
          std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
          int res = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
          result = result + res;
      }
        //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        //result1[k] = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        result1[k] = result;
        k++;
     }
    random_shuffle(&arr[0], &arr[length]);
    long* result2 = new long[length/timePeriod+1];
    k = 0;
    while(k < length/timePeriod){
        //std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
        int result = 0;
        for(int i = 0; i < timePeriod;i++){
            std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
            tree->deleteItem(arr[i + k * timePeriod]);
            std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
            int res = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count();
            result = result + res;
        }
        //std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
        //result2[k] = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count();
        result2[k] = result;
        k++;
    }
    cout<<"Part E - Time Analysis of Binary Search Tree - Part 1"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    printf("%-15s%-20s%-20s%-20s\n", "", "Tree Size", "Time Elapsed", "");
    cout<<"-----------------------------------------------------"<<endl;
    for(int i = 0; i < length/timePeriod; i++)
    printf("%-15s%-20i%-20i%-20s\n", "", (i+1) * timePeriod, result1[i], "");
    cout<<endl;
    cout<<"Part E - Time Analysis of Binary Search Tree - Part 2"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    printf("%-15s%-20s%-20s%-20s\n", "", "Tree Size", "Time Elapsed", "");
    cout<<"-----------------------------------------------------"<<endl;
    for(int i = 0; i < length/timePeriod; i++)
        printf("%-15s%-20i%-20i%-20s\n", "", length - timePeriod * (i+1), result2[i], "");

    delete[]arr;
    delete[]result1;
    delete[]result2;
    tree->destroyTree(tree->root);
    delete tree;
}