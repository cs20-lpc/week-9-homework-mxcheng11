#include "LinkedQueue.hpp" 

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    // initalize front (head) and back (last) to nullptr 
    head = nullptr;
    last = nullptr;

    // initalize length to 0 
    this->length = 0;

}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
    
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();

}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (isEmpty())
    {
        throw string("Empty Queue (can't access back)");
    }
    // return val of back node
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    // while queue not empty, dequeue
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    // if copyObj is empty, return
    if (copyObj.isEmpty()) return; 

    // create ptr to traverse copyObj 
    Node *copyPtr = copyObj.head; 

    // while copyPtr not null, enqueue 
    while (copyPtr != nullptr) {
        enqueue(copyPtr->value);
        copyPtr = copyPtr->next;
    }




}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    // if queue is empty, return
    if (isEmpty()) 
    {
        throw string("Empty Queue (can't dequeue)");
        return;
    }

    // create temp ptr to front node
    Node *temp = head; 
    head = head->next;

    // if front and back are the same, set back to nullptr
    if (head == nullptr) {
        last = nullptr;
    }

    // delete temp node 
    delete temp;

    // update length
    this->length--;

}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node *newNode = new Node(elem);

    // queue empty, set front and back to new node
    if (isEmpty())
    {
        head = newNode;
        last = newNode;
    }

    // queue not empty, back's next is new node, set back to new node
    else
    {
        last->next = newNode;
        last = newNode;
    }

    // update length 
    this->length++;

}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) 
    {
        throw string("Empty Queue (can't access front)");
    }


    // return val of front node 
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
