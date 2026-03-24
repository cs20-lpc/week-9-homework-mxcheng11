#include "ArrayQueue.hpp"

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    // initialize
    maxSize = i; 
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;

}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    buffer = nullptr;
    maxSize = 0;
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
    delete[] buffer;
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    //return element at back of queue

    //check if empty
    if (isEmpty())
    {
        throw string("Queue is empty, no value at back");
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    if(isEmpty()) return; 

    //reset to initial state (not deallocated for reuse)
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;

}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    //copy values from copyObj to this
    maxSize = copyObj.maxSize;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    this->length = copyObj.length;

    //allocate new buffer and copy elements
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }

}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    //check if empty
    if (isEmpty())
    {
        throw string("Queue is empty, no element to dequeue");
    }

    //remove front element and update frontIndex and length
    frontIndex = (frontIndex + 1) % maxSize; //circular increment
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    //check if full
    if (isFull())
    {
        throw string("Queue is full, cannot enqueue new element");
    }
   
   //add element to back of queue and update backIndex and length
   backIndex = (backIndex + 1) % maxSize; //circular increment
   buffer[backIndex] = elem;
   this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    //return element at front of queue  

    //check if empty
    if(isEmpty())
    {
        throw string("Queue is empty, no value at front");
    }

    return buffer[frontIndex];
}


template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
