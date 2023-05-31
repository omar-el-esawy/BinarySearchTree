#include <bits/stdc++.h>
#include "BSTFCI.cpp"

using namespace std;


template<class T>
bool isSubTree(BSTFCI<T> *t1, BSTFCI<T> *t2) {
    t1->isSubTreeNodes(t2->getroot());
}

void test_1() {

    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {9, 3, 4, 11, 10};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';

    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {9};
    for (auto x: aa)c->insert(x);
    cout << '\n';

    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_2() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 2, 10, 8};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {9, 3, 4, 11, 10};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_3() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 7, 8, 5};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {3, 4};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_4() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 7, 3};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {3, 4};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_5() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {5, 6, 9};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {6};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}


int main() {
    cout << "--------test one -------\n";
    test_1();
    cout << "--------test two -------\n";
    test_2();
    cout << "--------test three -------\n";
    test_3();
    cout << "--------test four -------\n";
    test_4();
    cout << "--------test five -------\n";
    test_5();
    return 0;
}