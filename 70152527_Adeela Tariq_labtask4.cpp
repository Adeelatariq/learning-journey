#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
    node* prev;
};

node* head = NULL;
node*tail =NULL;
void createDLL();
void display();
int Length();
void insertAtHead();
void insertAtTail();
void insertAfterPosition();
void insertBeforePosition();
void delHead();
void delTail();
void delAtPosition();
void delByValue();
void sortAscending();
void sortDescending();
void tailToHead();
void headToTail();
void swapNodes();
void reverseDLL();
void deleteDuplicates();

int main() {
    int choice, count;
    do {
        cout << "1:  Create Doubly Linked List\n";
        cout << "2: Display List\n";
        cout << "3: Get Length of List\n";
        cout << "4:  Insert at Head\n";
        cout << "5:  Insert After Position\n";
        cout << "6:  Delete Head\n";
        cout << "7:  Delete Tail\n";
        cout << "8:  Delete At Position\n";
        cout << "9: Remove Duplicates\n";
        cout << "10: Reverse Doubly Linked List\n";
       
        cin >> choice;

        switch (choice) {
            case 1: createDLL(); break;
            case 4: insertAtHead(); break;
            case 5: insertAfterPosition(); break;
            case 6: delHead(); break;
            case 7: delTail(); break;
            case 8: delAtPosition(); break;
            case 10: reverseDLL(); break;
            case 3: cout << "Length: " << Length() << endl; break;
            case 2: display(); break;
            case 9: deleteDuplicates(); break;
            default: cout << "Invalid choice!\n";
        }

        cout << "\nPress 0 to exit, any other key for main menu: ";
        cin >> count;
    } while (count != 0);

    return 0;
}
void createDLL() {
    int x;
    do {
        node* newnode = new node();
        cout << "Enter node value: ";
        cin >> newnode->value;
        newnode->next = newnode->prev = NULL;

        if (head == NULL)
        head = newnode;
        else {
            node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }

        cout << "Press 0 to stop, any other key to continue: ";
        cin >> x;
    } while (x != 0);
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* temp = head;
    cout << "dOUBLE lINKED lIST ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}


int Length() {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void insertAtHead() {
    node* newnode = new node();
    cout << "Enter value: ";
    cin >> newnode->value;
    newnode->next = head;
    newnode->prev = NULL;

    if (head != NULL)
    head->prev = newnode;
    head = newnode;
}

void insertAtTail() {
    node* newnode = new node();
    cout << "Enter value: ";
    cin >> newnode->value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void insertAfterPosition() {
    int pos;
    cout << "Enter position to insert AFTER: ";
    cin >> pos;
    int len = Length();

    if (pos < 1 || pos > len) {
        cout << "Invalid position.\n";
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    node* newnode = new node();
    cout << "Enter value: ";
    cin >> newnode->value;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void delHead() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void delTail() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

void delAtPosition() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    int len = Length();

    if (pos < 1 || pos > len) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        delHead();
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

void reverseDLL() {
    node* temp = NULL;
    node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

void deleteDup() {
    for (node* i = head; i != nullptr; i = i->next) {
        node* j = i->next;
        while (j != nullptr) {
            if (i->value == j->value) {
                node* dup = j;           
                j = j->next;           

                
                if (dup->prev)
                    dup->prev->next = dup->next;
                if (dup->next)
                    dup->next->prev = dup->prev;

                
                if (dup == head)
                    head = dup->next;

                delete dup;              
            } 
            else {
                j = j->next;            
            }
        }
    }
}

