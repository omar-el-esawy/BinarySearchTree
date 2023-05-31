//
// Created by Esawy on 5/31/2023.
//

#include "BSTFCI.h"


template<class T>
typename BSTFCI<T>::BSTNode *BSTFCI<T>::createNode(T data) {
    BSTNode *new_Node = new BSTNode;
    new_Node->left = NULL;
    new_Node->right = NULL;
    new_Node->data = data;
    return new_Node;
}

template<class T>
typename BSTFCI<T>::BSTNode *BSTFCI<T>::getTheRightPlace(BSTFCI::BSTNode *node, T value) {
    if (node == nullptr)
        return createNode(value);

    if (node->data > value)
        node->left = getTheRightPlace(node->left, value);

    else if (node->data < value)
        node->right = getTheRightPlace(node->right, value);

    return node;
}

template<class T>
void BSTFCI<T>::PrintInorderTraverse(BSTFCI::BSTNode *node) {
    if (node == nullptr)
        return;
    PrintInorderTraverse(node->left);
    cout << node->data << ' ';
    PrintInorderTraverse(node->right);

}

template<class T>
int BSTFCI<T>::balanceHeight(BSTFCI::BSTNode *currentNode) {
    if (currentNode == nullptr) {
        return 0;
    }

    int leftSubtreeHeight = balanceHeight(currentNode->left);
    if (leftSubtreeHeight == -1) return -1;

    int rightSubtreeHeight = balanceHeight(currentNode->right);
    if (rightSubtreeHeight == -1) return -1;

    if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
        return -1;
    }
    return (max(leftSubtreeHeight, rightSubtreeHeight) + 1);
}

template<class T>
BSTFCI<T>::BSTFCI() {
    rootPtr = nullptr;
}

template<class T>
void BSTFCI<T>::insert(T value) {
    if (!rootPtr)
        rootPtr = getTheRightPlace(rootPtr, value);
    else {
        getTheRightPlace(rootPtr, value);
    }
}

template<class T>
void BSTFCI<T>::PrintInorder() {
    PrintInorderTraverse(rootPtr);
}

template<class T>
bool BSTFCI<T>::isBalance() {
    return balanceHeight(rootPtr) != -1;
}

template<class T>
typename BSTFCI<T>::BSTNode *BSTFCI<T>::getroot() const {
    return rootPtr;
}

template<class T>
typename BSTFCI<T>::BSTNode *BSTFCI<T>::getTheRoot(BSTFCI::BSTNode *node, T value) {
    if (node == nullptr)
        return nullptr;

    if (node->data > value) {
        BSTNode *otherNode = getTheRightPlace(node->left, value);
        if (otherNode != nullptr)
            return otherNode;
    } else if (node->data < value) {
        BSTNode *otherNode = getTheRightPlace(node->right, value);
        if (otherNode != nullptr)
            return otherNode;
    } else
        return node;
    return nullptr;
}

template<class T>
bool BSTFCI<T>::isSimilar(BSTFCI::BSTNode *node, BSTFCI::BSTNode *root2) {
    if (node == nullptr && root2 == nullptr)
        return true;

    if (node == nullptr || root2 == nullptr)
        return false;


    return (node->data == root2->data &&
            isSimilar(node->left, root2->left) &&
            isSimilar(node->right, root2->right));
}

template<class T>
bool BSTFCI<T>::isSubTreeNodes(BSTFCI::BSTNode *n2) {
    BSTNode *node = getTheRoot(rootPtr, n2->data);
//        if (node != nullptr)
//            cout << node->data << '\n';
    cout << (isSimilar(node, n2) ? "YES" : "NO") << '\n';

}

template<class T>
void BSTFCI<T>::printInRange(BSTFCI::BSTNode *root, int k1, int k2) {
    if (NULL == root)
        return;
    if (k1 < root->data)
        printInRange(root->left, k1, k2);
    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";
    if (k2 > root->data)
        printInRange(root->right, k1, k2);
}

template<class T>
void BSTFCI<T>::deleteNodes(BSTFCI::BSTNode *node) {
    BSTNode *d = node;
    if (node != nullptr) {
        BSTNode *dr = node->right;
        BSTNode *dl = node->left;
        delete d;
        deleteNodes(dr);
        deleteNodes(dl);
    } else return;
}

template<class T>
BSTFCI<T>::~BSTFCI() {
    deleteNodes(rootPtr);
}
