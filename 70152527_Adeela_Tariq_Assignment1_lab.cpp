#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};
node* h = NULL;
node* temp = NULL;
node* prev = NULL;

// a) Insert node with value 7 at even positions
void insertionatevenpos() {
    int pos = 1;
    node* current = h;
    node* prev = NULL;

    while (current != NULL) {
        if (pos % 2 == 0) {
            node* newnode = new node;
            newnode->value = 7;
            newnode->next = current;

            if (prev != NULL)
                prev->next = newnode;
            else
                h = newnode;

            prev = newnode;
            pos++;
        } else {
            prev = current;
            current = current->next;
            pos++;
        }
    }
}

// b) Delete node by value
void deletionbyvalue() {
    int value;
    cout << "Enter the value you want to delete: ";
    cin >> value;

    node* temp = h;
    node* prev = NULL;

    while (temp != NULL) {
        if (temp->value == value) {
            if (prev == NULL)
                h = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Node containing value " << value << " is deleted\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Value not found in the list.\n";
}

// c) Swap two nodes by their values
void swapnodes() {
    int a, b;
    cout << "Enter two values to swap: ";
    cin >> a >> b;

    if (a == b)
        return;

    node* currenta = h;
    node* currentb = h;
    node* preva = NULL;
    node* prevb = NULL;
    while (currenta != NULL && currenta->value != a) {
        preva = currenta;
        currenta = currenta->next;
    }

    
    while (currentb != NULL && currentb->value != b) {
        prevb = currentb;
        currentb = currentb->next;
    }

    if (!currenta || !currentb) {
        cout << "One or both nodes not found.\n";
        return;
    }

    if (preva != NULL)
        preva->next = currentb;
    else
        h = currentb;

    if (prevb != NULL)
        prevb->next = currenta;
    else
        h = currenta;
    node* temp = currenta->next;
    currenta->next = currentb->next;
    currentb->next = temp;

    cout << "Nodes swapped successfully.\n";
}

// d) Bubble sort the linked list
void bubblesort() {
    node* temp = h;
    while (temp != NULL) {
        node* nextnode = temp->next;
        while (nextnode != NULL) {
            if (temp->value > nextnode->value) {
                int swap = temp->value;
                temp->value = nextnode->value;
                nextnode->value = swap;
            }
            nextnode = nextnode->next;
        }
        temp = temp->next;
    }
    cout << "List Sorting Done\n";
}

// e) Reverse the linked list
void reverselist() {
    node* current = h;
    node* prev = NULL;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    h = prev;

    cout << "List Reversed Successfully.\n";
}
void display() {
    node* temp = h;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int choice;
    cout << "1. Insert node at even positions\n";
    cout << "2. Delete node by value\n";
    cout << "3. Swap two nodes\n";
    cout << "4. Bubble sort the list\n";
    cout << "5. Reverse the list\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            insertionatevenpos();
            break;
        case 2:
            deletionbyvalue();
            break;
        case 3:
            swapnodes();
            break;
        case 4:
            bubblesort();
            break;
        case 5:
            reverselist();
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    display();
    return 0;
}

