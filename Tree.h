//
// Created by geanc on 9 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_TREE_H
#define DATASTRUCTUREPROJECT_TREE_H

#include "Node.h"

template <class Type,class Key>
class Tree{
private:
    Node<Type, Key>* root;
    int n;
    Node<Type, Key>* destruct(Node<Type, Key> * node);
    Node<Type, Key>*insert(Type* object,Node<Type, Key>* node, Key *key );
    Node<Type, Key>*findMin(Node<Type,Key> *node);
    Node<Type, Key>* findMax(Node<Type, Key> * node);
    Node<Type, Key> * find(Node<Type, Key> * node,  Key *key);
    void inOrder(Node<Type, Key> * node, string &data);
    void inOrderKeys(Node<Type,Key>*node, string &data );

public:
    explicit Tree();
    virtual ~Tree();
    void insert(Type* object, Key*  key);
    string display();
    Type* search(Key* key);
    int size();
    string allkeys();

};

template<class Type, class Key>
Tree<Type, Key>::Tree() {
    this->root = nullptr;
    this->n = 0;
}

template<class Type, class Key>
Tree<Type, Key>::~Tree() {
    destruct(root);
}

template<class Type, class Key>
Node<Type, Key> *Tree<Type, Key>::destruct(Node<Type, Key> *node) {
    if(!node) return nullptr;
    else{
        destruct(node->getLeft());
        destruct(node->getRight());
        delete node;
    }
    return nullptr;
}
template<class Type, class Key>
Node<Type, Key> *Tree<Type, Key>::insert(Type *object, Node<Type, Key> *node, Key *key) {
    if(!node)node = new Node<Type,Key>(object,key);
    else if(*key < *node->getKey()) node->setLeft(insert(object, node->getLeft(), key));
    else if(*key> *node->getKey()) node->setRight(insert(object,node->getRight(), key));
    return node;
}

template<class Type, class Key>
Node<Type, Key> *Tree<Type, Key>::findMin(Node<Type, Key> *node) {
    if(!node) return nullptr;
    else if(!node->getLeft()) return node;
    else return findMin(node->getLeft());
}

template<class Type, class Key>
Node<Type, Key> *Tree<Type, Key>::findMax(Node<Type, Key> *node) {
    if(!node) return nullptr;
    else if(!node->getRight()) return node;
    else return findMax(node->getRight());
}
template<class Type, class Key>
Node<Type, Key> *Tree<Type, Key>::find(Node<Type, Key> *node, Key *key) {
    if(!node) return nullptr;
    else if(*key< *node->getKey()) return find(node->getLeft(),  key);
    else if(*key > *node->getKey()) return find(node->getRight(),  key);
    else return node;
}
template<class Type, class Key>
void Tree<Type, Key>::inOrder(Node<Type, Key>* node, string &data) {
    if(!node) return;
    inOrder(node->getLeft(),data);
    data += *node->getData();
    inOrder(node->getRight(),data);
}
template<class Type, class Key>
void Tree<Type, Key>::insert(Type *object, Key *key) {
    root = insert(object, root, key);
    n++;
}
template<class Type, class Key>
Type *Tree<Type, Key>::search(Key *key) {
    Node<Type, Key>* variable = find(root, key);
    if(!variable) return nullptr;
    return variable->getData();
}

template<class Type, class Key>
string Tree<Type, Key>::display() {
    string data;
    inOrder(root, data);
    return data;
}

template<class Type, class Key>
int Tree<Type, Key>::size() {
    return n;
}

template<class Type, class Key>
string Tree<Type, Key>::allkeys() {
    string data;
    inOrderKeys(root,data);
    return data;
}

template<class Type, class Key>
void Tree<Type, Key>::inOrderKeys(Node<Type, Key> *node, string &data) {
    if(!node) return;
    inOrderKeys(node->getLeft(),data);
    data += to_string(*node->getKey())+",";
    inOrderKeys(node->getRight(),data);
}

#endif //DATASTRUCTUREPROJECT_TREE_H
