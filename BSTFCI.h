//
// Created by Esawy on 5/31/2023.
//

#ifndef BINARYSEARCHTREE_BSTFCI_H
#define BINARYSEARCHTREE_BSTFCI_H

#include <bits/stdc++.h>

using namespace std;

template<class T>
class BSTFCI {
public:
    struct BSTNode {
        T data;
        BSTNode *left, *right;
    };
private:
    BSTNode *rootPtr;

    BSTNode *createNode(T data);

    BSTNode *getTheRightPlace(BSTNode *node, T value);

    void PrintInorderTraverse(BSTNode *node);

    int balanceHeight(BSTNode *currentNode);


public:
    BSTFCI();

    void insert(T value);

    void PrintInorder();

    bool isBalance();

    BSTNode *getroot() const;

    BSTNode *getTheRoot(BSTNode *node, T value);

    bool isSimilar(BSTNode *node, BSTNode *root2);

    bool isSubTreeNodes(BSTNode *n2);


    void printInRange(BSTNode *root, int k1, int k2);

    void deleteNodes(BSTNode *node);

    ~BSTFCI();
};




#endif //BINARYSEARCHTREE_BSTFCI_H
