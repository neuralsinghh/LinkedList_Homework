#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Linked List Class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insertion
    void insertFront(int x);
    void insertEnd(int x);
    void insertPosition(int pos, int x);

    // Deletion
    void deleteFront();
    void deleteLast();
    void deletePosition(int pos);

    // Searching
    bool search(int key);

    // Display
    void display();

    // Utility Functions
    int length();
    int sum();
    int maximum();
    int minimum();
    double average();

    // Counting
    int countEven();
    int countOdd();

    // Updating
    void update(int oldValue, int newValue);

    // Special Operations
    int findMiddle();
    bool isSorted();

    // Destructor
    ~LinkedList();
};

// INSERTION FUNCTIONS

void LinkedList::insertFront(int x) {
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}

void LinkedList::insertEnd(int x) {
    Node* temp = new Node(x);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

void LinkedList::insertPosition(int pos, int x) {
    if (pos == 1) {
        insertFront(x);
        return;
    }

    Node* p = head;

    for (int i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL)
        return;

    Node* temp = new Node(x);

    temp->next = p->next;
    p->next = temp;
}

// DELETION FUNCTIONS

void LinkedList::deleteFront() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    delete temp;
}

void LinkedList::deleteLast() {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* p = head;

    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

void LinkedList::deletePosition(int pos) {
    if (pos == 1) {
        deleteFront();
        return;
    }

    Node* p = head;

    for (int i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL || p->next == NULL)
        return;

    Node* temp = p->next;

    p->next = temp->next;

    delete temp;
}

// SEARCH

bool LinkedList::search(int key) {
    Node* p = head;

    while (p != NULL) {
        if (p->data == key)
            return true;

        p = p->next;
    }

    return false;
}

// DISPLAY

void LinkedList::display() {
    Node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// UTILITY FUNCTIONS

int LinkedList::length() {
    int count = 0;

    Node* p = head;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int LinkedList::sum() {
    int s = 0;

    Node* p = head;

    while (p != NULL) {
        s += p->data;
        p = p->next;
    }

    return s;
}

int LinkedList::maximum() {
    if (head == NULL)
        return -1;

    int max = head->data;

    Node* p = head;

    while (p != NULL) {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

int LinkedList::minimum() {
    if (head == NULL)
        return -1;

    int min = head->data;

    Node* p = head;

    while (p != NULL) {
        if (p->data < min)
            min = p->data;

        p = p->next;
    }

    return min;
}

double LinkedList::average() {
    if (length() == 0)
        return 0;

    return (double)sum() / length();
}

// COUNTING

int LinkedList::countEven() {
    int count = 0;

    Node* p = head;

    while (p != NULL) {
        if (p->data % 2 == 0)
            count++;

        p = p->next;
    }

    return count;
}

int LinkedList::countOdd() {
    int count = 0;

    Node* p = head;

    while (p != NULL) {
        if (p->data % 2 != 0)
            count++;

        p = p->next;
    }

    return count;
}

// UPDATE

void LinkedList::update(int oldValue, int newValue) {
    Node* p = head;

    while (p != NULL) {
        if (p->data == oldValue)
            p->data = newValue;

        p = p->next;
    }
}

// SPECIAL OPERATIONS

int LinkedList::findMiddle() {
    if (head == NULL)
        return -1;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

bool LinkedList::isSorted() {
    if (head == NULL)
        return true;

    Node* p = head;

    while (p->next != NULL) {
        if (p->data > p->next->data)
            return false;

        p = p->next;
    }

    return true;
}

// DESTRUCTOR

LinkedList::~LinkedList() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// MAIN FUNCTION

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Linked List: ";
    list.display();

    cout << "Length: " << list.length() << endl;
    cout << "Sum: " << list.sum() << endl;
    cout << "Maximum: " << list.maximum() << endl;
    cout << "Minimum: " << list.minimum() << endl;
    cout << "Average: " << list.average() << endl;

    cout << "Even Count: " << list.countEven() << endl;
    cout << "Odd Count: " << list.countOdd() << endl;

    cout << "Middle Element: " << list.findMiddle() << endl;

    cout << "Search 20: "
         << (list.search(20) ? "Found" : "Not Found")
         << endl;

    cout << "Sorted: "
         << (list.isSorted() ? "Yes" : "No")
         << endl;

    return 0;
}