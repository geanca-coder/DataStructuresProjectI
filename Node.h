//
// Created by geanc on 9 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_NODE_H
#define DATASTRUCTUREPROJECT_NODE_H

#include <iostream>
using namespace std;
template <class Type, class Key>
class Node{
private:
    Type *data;
    Key* key;
    Node* left;
    Node* right;;
public:
    explicit Node(Type *data= nullptr, Key *key= nullptr, Node *left= nullptr, Node *right = nullptr);

    Type *getData() const;

    void setData(Type *data);

    Key *getKey() const;

    void setKey(Key *key);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);

    virtual ~Node();
};

template<class Type, class Key>
Node<Type, Key>::Node(Type *data, Key *key, Node *left, Node *right):data(data), key(key), left(left), right(right) {}

template<class Type, class Key>
Type *Node<Type, Key>::getData() const {
    return data;
}

template<class Type, class Key>
void Node<Type, Key>::setData(Type *data) {
    Node::data = data;
}

template<class Type, class Key>
Key *Node<Type, Key>::getKey() const {
    return key;
}

template<class Type, class Key>
void Node<Type, Key>::setKey(Key *key) {
    Node::key = key;
}

template<class Type, class Key>
Node<Type, Key>*Node<Type, Key>::getLeft() const {
    return left;
}

template<class Type, class Key>
void Node<Type, Key>::setLeft(Node *left) {
    Node::left = left;
}

template<class Type, class Key>
Node<Type, Key> *Node<Type, Key>::getRight() const {
    return right;
}

template<class Type, class Key>
void Node<Type, Key>::setRight(Node *right) {
    Node::right = right;
}
template<class Type, class Key>
Node<Type, Key>::~Node() = default;


#endif //DATASTRUCTUREPROJECT_NODE_H
