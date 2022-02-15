//
// Created by geanc on 11 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_PRIORITYQUEUE_H
#define DATASTRUCTUREPROJECT_PRIORITYQUEUE_H

template<class Type>
class PriorityQueue {
private:
    Type **H;
    int size;
protected:

    int parent(int i);

    int leftChild(int i);

    int rightChild(int i);

    void shiftUp(int i);

    void shiftDown(int i);

    bool exist(Type* object);

    void swap(int i , int j);



public:

    PriorityQueue();

    bool insert(Type* p);

    int quantity();

    Type* extractMax();

    Type* getMax();

    virtual ~PriorityQueue();

};

template<class Type>
PriorityQueue<Type>::PriorityQueue() {
    this->size = -1;
    H = new Type*[200];
    for(int i = 0 ; i <=size; i++) H[i] = nullptr;
}

template<class Type>
int PriorityQueue<Type>::parent(int i) {
    // Function to return the index of the
    // parent node of a given node
    return (i-1)/2;
}

template<class Type>
int PriorityQueue<Type>::leftChild(int i) {
    // Function to return the index of the
    // left child of the given node
    return ((2*i)+1);
}

template<class Type>
int PriorityQueue<Type>::rightChild(int i) {

    // Function to return the index of the
    // right child of the given node
    return ((2 * i) + 2);
}

template<class Type>
void PriorityQueue<Type>::shiftUp(int i) {
    // Function to shift up the node in order
    // to maintain the heap property
    while (i > 0 && *H[parent(i)] < *H[i]) {
        // Swap parent and current node
        swap(parent(i), i);
        // Update i to parent of i
        i = parent(i);
    }
}

template<class Type>
void PriorityQueue<Type>::shiftDown(int i) {

    // Function to shift down the node in
    // order to maintain the heap property
    int maxIndex = i;
    // Left Child

    int l = leftChild(i);

    if (l <= size && *H[l] > *H[maxIndex]) {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= size && *H[r] > *H[maxIndex]) {
        maxIndex = r;
    }

    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(i, maxIndex);
        shiftDown(maxIndex);
    }

}

template<class Type>
bool PriorityQueue<Type>::insert(Type *p) {
    // Function to insert a new element
    // in the Binary Heap
    if(size<200)
    {
        if(!exist(p)){
            size++;
            H[size] = p;
            // Shift Up to maintain heap property
            shiftUp(size);
            return true;
        }
        return false;
    }
    return false;
}

template<class Type>
Type* PriorityQueue<Type>::extractMax() {

    // Function to extract the element with
    // maximum priority
    Type* result = H[0];
    // Replace the value at the root
    // with the last leaf
    H[0] = H[size];
    size--;
    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}


template<class Type>
Type* PriorityQueue<Type>::getMax() {
    // Function to get value of the current
    // maximum element
    return H[0];
}

template<class Type>
int PriorityQueue<Type>::quantity() {
    return size;
}

template<class Type>
PriorityQueue<Type>::~PriorityQueue() {
    for(int i = 0; i<=size; i++)delete H[i];
    delete H;
}
template<class Type>
bool PriorityQueue<Type>::exist(Type *object) {
    for(int i = 0; i <= size; i++) if(*object == *H[i]) return true;
    return false;
}

template<class Type>
void PriorityQueue<Type>::swap(int i, int j) {
    Type* temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}


#endif //DATASTRUCTUREPROJECT_PRIORITYQUEUE_H
