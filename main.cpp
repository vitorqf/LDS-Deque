#include <iostream>
#include "deque.h"

using namespace std;

int main() {
    Deque deque;

    deque.insertLast(10);
    deque.insertLast(20);
    deque.insertLast(30);

    deque.insertFirst(40);
    deque.insertFirst(50);
    deque.insertFirst(60);

    cout << "O primeiro elemento é " << deque.first() << endl;
    cout << "O último elemento é " << deque.last() << endl;

    cout << "Tamanho da deque: " << deque.size() << endl;
    deque.printAll();

    deque.removeLast();
    deque.removeLast();
    deque.removeFirst();

    cout << endl;
    cout << "O primeiro elemento é " << deque.first() << endl;
    cout << "O último elemento é " << deque.last() << endl;

    cout << "Tamanho da deque: " << deque.size() << endl;
    deque.printAll();

    return 0;
};