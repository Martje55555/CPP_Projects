/****************************************************************
* Queue                                                         *
*****************************************************************/
#include <iostream>
#include <cstdlib>

#define SIZE 1000

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = SIZE);
    ~Queue();

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    std::cout << "Removing " << x << std::endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        std::cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting " << item << std::endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "The front element is " << q.peek() << std::endl;
    q.dequeue();

    q.enqueue(4);

    std::cout << "The queue size is " << q.size() << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
        std::cout << "The queue is empty\n";
    else
        std::cout << "The queue is not empty\n";
    return 0;
}