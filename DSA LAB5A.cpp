#include <iostream>
using namespace std;

struct Node {
    int marks;
    Node* prev;
    Node* next;
};

// Head pointer (global or can be encapsulated in a class)
Node* head = nullptr;

// Function to create list from user input
void createList(int n) {
    if (n <= 0) return;

    Node* newNode;
    Node* temp;

    for (int i = 0; i < n; i++) {
        newNode = new Node;
        cout << "Enter marks for node " << i + 1 << ": ";
        cin >> newNode->marks;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

// Display function
void display() {
    Node* temp = head;
    cout << "\nCurrent List: ";
    while (temp != nullptr) {
        cout << temp->marks << " ";
        temp = temp->next;
    }
    cout << endl;
}

// (b) Add node at beginning
void addAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->marks = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
    cout << "\nNode added at beginning with value " << value << endl;
}

// (c) Add node after node having value 45
void addAfter45(int value) {
    Node* temp = head;

    while (temp != nullptr && temp->marks != 45)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "\nNode with value 45 not found.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->marks = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
    cout << "\nNode added after value 45 with value " << value << endl;
}

// (d) Delete node from beginning
void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    cout << "\nDeleted node from beginning with value " << temp->marks << endl;
    delete temp;
}

// (e) Delete node after node having value 45
void deleteAfter45() {
    Node* temp = head;

    while (temp != nullptr && temp->marks != 45)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "\nNo node found to delete after value 45.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (nodeToDelete->next != nullptr)
        nodeToDelete->next->prev = temp;

    cout << "\nDeleted node after value 45 with value " << nodeToDelete->marks << endl;
    delete nodeToDelete;
}

// Main Function
int main() {
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;

    createList(n);
    display();

    // Example operations
    addAtBeginning(99);
    display();

    addAfter45(88);
    display();

    deleteAtBeginning();
    display();

    deleteAfter45();
    display();

    return 0;
}
