#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* elements;      // Array to hold stack elements
    int top;          // Index of the top element
    int maxSize;      // Maximum size of the stack

public:
    Stack(int size) : top(-1), maxSize(size) {
        elements = new T[maxSize];  // Allocate memory for stack
    }

    // Add an element to the stack
    void push(T value) {
        if (top >= maxSize - 1) {
            throw std::overflow_error("Stack Overflow");
        }
        elements[++top] = value;     // Place value on top
    }

    // Remove and return the top element
    T pop() {
        if (top < 0) {
            throw std::underflow_error("Stack Underflow");
        }
        return elements[top--];       // Return top element
    }

    // Return the top element without removing it
    T peek() const {
        if (top < 0) throw std::underflow_error("Stack is Empty");
        return elements[top];         // Return the top element
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top < 0;               // Return true if empty
    }

    ~Stack() {
        delete[] elements;            // Free allocated memory
    }
};

int main() {
    Stack<int> myStack(5);           // Create a stack of integers

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.peek() << std::endl;
    std::cout << "Popped element: " << myStack.pop() << std::endl;
    std::cout << "Top element after pop: " << myStack.peek() << std::endl;

    return 0;                         // End of program
}
