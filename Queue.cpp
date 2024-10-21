#include <iostream>

using namespace std;

class Queue {
private:
    int* arr;      // Array to hold queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int capacity;  // Maximum size of the queue
    int count;     // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Enqueue an element
    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        count++;
    }

    // Dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return -1 if empty
        }
        int item = arr[front];
        front = (front + 1) % capacity; // Circular increment
        count--;
        return item;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Get the size of the queue
    int size() const {
        return count;
    }

    // Destructor to clean up memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue myQueue(5); // Create a queue of size 5

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Dequeued: " << myQueue.dequeue() << endl; // Remove element
    cout << "Current size: " << myQueue.size() << endl; // Show size

    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60); // This will show "Queue is full!"

    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.dequeue() << endl; // Dequeue remaining elements
    }

    return 0; // End of program
}
