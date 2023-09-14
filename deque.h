//
// Created by vitor on 9/13/23.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};

class Deque {
private:
    Node *tail; // Elemento mais a direita
    Node *head; // Elemento mais a esquerda
    int count;

public:
    Deque() {
        count = 0;
        tail = nullptr;
        head = nullptr;
    }

    bool isEmpty() {
        return (tail == nullptr && head == nullptr);
    }

    void insertLast(int element) {
        Node *new_node = new Node();
        new_node->data = element;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (isEmpty()) {
            cout << "A deque está vazia, inserindo o primeiro elemento" << endl;
            tail = head = new_node;
        };

        /**
         * O elemento a direita do ultimo, se torna o new_node
         * o elemento a esquerda do new_node se torna o ultimo elemento
         * o ultimo elemento se torna o new_node
         * */
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;

        count++;
    }

    void insertFirst(int element) {
        Node *new_node = new Node();
        new_node->data = element;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (isEmpty()) {
            cout << "A deque está vazia, inserindo o primeiro elemento" << endl;
            tail = head = new_node;
        };

        /**
         * O elemento a esquerda do primeiro elemento se torna new_node
         * O elemento a direita de new_node se torna o primeiro elemento
         * O primeiro elemento se torna new_node
         * */
        head->prev = new_node;
        new_node->next = head;
        head = new_node;

        count++;
    }

    void removeLast() {
       if (isEmpty()) {
           cout << "A deque está vazia" << endl;
           exit(1);
       };

       Node *aux = tail;
       tail = tail->prev;
       tail->next = nullptr;
       delete(aux);

       count--;
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "A deque está vazia" << endl;
            exit(1);
        };

        Node *aux = head;
        head = head->next;
        head->prev = nullptr;
        delete (aux);

        count--;
    }

    int size() {
        return count;
    }

    int first() {
        return head->data;
    }

    int last() {
        return tail->data;
    }

    void printAll() {
        Node *current = head;

        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

#endif //DEQUE_DEQUE_H
