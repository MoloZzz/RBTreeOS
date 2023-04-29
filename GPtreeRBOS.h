#pragma once
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int value;
    Color color;
    Node* left, * right, * parent;
    int size; // кількість вузлів в піддереві з коренем у даному вузлі

    Node(int v, Color c, Node* p) : value(v), color(c), left(nullptr), right(nullptr), parent(p), size(1) {}
};

class RedBlackTree {
private:
    

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;

        // оновлюємо розмір піддерева
        x->size = 1 + (x->left ? x->left->size : 0) + (x->right ? x->right->size : 0);
        y->size = 1 + x->size + (y->right ? y->right->size : 0);
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->right = x;
        x->parent = y;

        // оновлюємо розмір піддерева
        x->size = 1 + (x->left ? x->left->size : 0) + (x->right ? x->right->size : 0);
        y->size = 1 + (y->left ? y->left->size : 0) + x->size;
    }

    void fixInsert(Node* x) {
        while (x != root && x->parent->color == RED) {
            if (x->parent == x->parent->parent->left) {
                Node* y = x->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                }
                else {
                    if (x == x->parent->right) {
                        x = x->parent;
                        leftRotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    rightRotate(x->parent->parent);
                }
            }
            else {
                Node* y = x->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                }
                else {
                    if (x == x->parent->left) {
                        x = x->parent;
                        rightRotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    leftRotate(x->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

public:

    Node* root;
    RedBlackTree() : root(nullptr) {}

        // рекурсивна функція вставки
        Node* insert(Node* node, int value, Node* parent) {
        if (node == nullptr)
            return new Node(value, RED, parent);
        else if (value < node->value)
            node->left = insert(node->left, value, node);
        else
            node->right = insert(node->right, value, node);

        // оновлюємо розмір піддерева
        node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);

        // викликаємо функцію виправлення
        fixInsert(node);
        return node;
    }

    // інтерфейсна функція вставки
    void insert(int value) {
        root = insert(root, value, nullptr);
        root->color = BLACK;
    }

    // рекурсивна функція пошуку і-го елементу
    Node* select(Node* node, int i) {
        if (node == nullptr)
            return nullptr;

        int r = node->left ? node->left->size : 0;

        if (i == r + 1)
            return node;
        else if (i <= r)
            return select(node->left, i);
        else
            return select(node->right, i - r - 1);
    }

    // інтерфейсна функція пошуку і-го елементу
    Node* select(int i) {
        return select(root, i);
    }

    void inorderTraversal(Node* x) {
        if (x != nullptr) {
            inorderTraversal(x->left);
            std::cout << x->value << " ";
            inorderTraversal(x->right);
        }
    }

    void printSimple() {
        inorderTraversal(root);
    }

    void print(Node* node) {
        if (node != nullptr) {
            std::cout << "((" << node->value << ")";
            std::cout << "(п1ддерев:" << node->size-1 << "))";

            print(node->left);
            print(node->right);
        }
    }
};

