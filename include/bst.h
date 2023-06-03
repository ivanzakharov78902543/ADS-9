// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
    T value;
    int k;
    Node* l, *r;
    };
    Node* root;
    Node* addN(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->k = 1;
            root->l = root->r = nullptr;
        } else if (root->value < value) {
            root->r = addN(root->r, value);
        } else if (root->value > value) {
            root->l = addN(root->l, value);
        } else {
            root->k += 1;
        }
        return root;
    }
    Node* searchN(Node* root, const T& value) {
        if (root == nullptr || root->value == value) {
            return root;
        }
        if (value < root->value) {
            return searchN(root->l, value);
        } else {
            return searchN(root->r, value);
        }
    }
    int getD(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(getDepth(root->l), getDepth(root->r));
    }
 public:
    BST() : root(nullptr) {}
    void add(const T& value) {
        root = addN(root, value);
    }
    int depth() {
        return getD(root)-1;
    }
    int search(const T& value) {
        Node* current = searchN(root, value);
        if (current != nullptr) {
            return current->k;
        } else {
            return 0;
        }
    }
};
#endif  // INCLUDE_BST_H_
