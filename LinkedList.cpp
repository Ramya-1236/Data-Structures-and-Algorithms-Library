#include <iostream>

class LinkedList {
private:
    // Node structure definition
    struct Node {
        int data;      // Data stored in the node
        Node* next;    // Pointer to the next node
        Node(int val) : data(val), next(nullptr) {}  // Constructor
    };

    Node* head;  // Head pointer to the first node in the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head;             // Link it to the previous head
        head = newNode;                   // Update head to new node
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (!head) {                     // If the list is empty
            head = newNode;              // Set new node as head
        } else {
            Node* temp = head;           // Start from head
            while (temp->next) {         // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;        // Link last node to new node
        }
    }

    // Function to delete a node by its value
    void deleteNode(int value) {
        if (!head) return;               // Check if the list is empty
        if (head->data == value) {      // If head needs to be deleted
            Node* temp = head;
            head = head->next;          // Update head to next node
            delete temp;                // Free the deleted node
            return;
        }
        Node* temp = head;              // Start from head
        while (temp->next && temp->next->data != value) {
            temp = temp->next;          // Traverse the list
        }
        if (temp->next) {               // If the node to delete is found
            Node* toDelete = temp->next; // Store the node to delete
            temp->next = temp->next->next; // Bypass the node
            delete toDelete;            // Free the deleted node
        }
    }

    // Function to display the contents of the list
    void display() const {
        Node* temp = head;              // Start from head
        while (temp) {                  // Traverse through the list
            std::cout << temp->data << " -> "; // Print data
            temp = temp->next;          // Move to next node
        }
        std::cout << "NULL\n";          // Indicate end of list
    }

    // Destructor to clean up the list when done
    ~LinkedList() {
        while (head) {                  // Loop until all nodes are deleted
            Node* temp = head;          // Store the current head
            head = head->next;          // Move head to next node
            delete temp;                // Free the deleted node
        }
    }
};

// Main function to demonstrate linked list functionality
int main() {
    LinkedList list;                  // Create a LinkedList object
    list.insertAtBeginning(10);       // Insert 10 at the beginning
    list.insertAtBeginning(20);       // Insert 20 at the beginning
    list.insertAtEnd(30);             // Insert 30 at the end
    list.insertAtEnd(40);             // Insert 40 at the end

    std::cout << "Linked List: ";
    list.display();                   // Display the current list

    list.deleteNode(20);              // Delete node with value 20
    std::cout << "After deleting 20: ";
    list.display();                   // Display the updated list

    return 0;                         // End of program
}
