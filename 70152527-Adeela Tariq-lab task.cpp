#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // for isalnum
using namespace std;

//stacks using arrays
int arrStack[5];
int top = -1;

void PushInStackArray() {
    if (top == 4) {
        cout << "Stack is full!\n";
        return;
    }
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    arrStack[top+1] = value;
    cout << value << " pushed into stack (Array)\n";
}

void PopInStackArray() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << arrStack[top--] << " popped from stack (Array)\n";
}

void DisplayInStackArray() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack (Array): ";
    for (int i = top; i >= 0; i--)
        cout << arrStack[i] << " ";
    cout << endl;
}

void TopInStackArray() {
    if (top == -1)
        cout << "Stack is empty!\n";
    else
        cout << "Top element (Array): " << arrStack[top] << endl;
}

//stacks using linked list
struct node {
    int data;
    node* next;
};

node* topL = NULL;

void PushInStackLinkedList() {
    node* nn = nn;
    cout << "Enter value to push: ";
    cin >> nn->data;
    nn->next = topL;
    topL = nn;
    cout << nn->data << " pushed into stack (Linked List)\n";
}

void PopInStackLinkedList() {
    if (topL == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    node* temp = topL;
    cout << temp->data << " popped from stack (Linked List)\n";
    topL = topL->next;
    delete temp;
}

void DisplayInStackLinkedList() {
    if (topL == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack (Linked List): ";
    node* temp = topL;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void TopInStackLinkedList() {
    if (topL == NULL)
        cout << "Stack is empty!\n";
    else
        cout << "Top element (Linked List): " << topL->data << endl;
}

// conversion of infix to postfix
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

void ConvertingInfixStringIntoPostfix() {
    string infix;
    string postfix ;
    int c;
    cout << "Enter infix expression (e.g. A+B*C): ";
    cin >> infix;

    stack<char> st;

   for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
	} {
        if (isalnum(c)) {  
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();  
        } else { 
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    int choice;
    do {
        cout << "1. PushInStackArray\n";
        cout << "2. PopInStackArray\n";
        cout << "3. DisplayInStackArray\n";
        cout << "4. TopInStackArray\n";
        cout << "5. PushInStackLinkedList\n";
        cout << "6. PopInStackLinkedList\n";
        cout << "7. DisplayInStackLinkedList\n";
        cout << "8. TopInStackLinkedList\n";
        cout << "9. ConvertingInfixStringIntoPostfix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: PushInStackArray(); break;
            case 2: PopInStackArray(); break;
            case 3: DisplayInStackArray(); break;
            case 4: TopInStackArray(); break;
            case 5: PushInStackLinkedList(); break;
            case 6: PopInStackLinkedList(); break;
            case 7: DisplayInStackLinkedList(); break;
            case 8: TopInStackLinkedList(); break;
            case 9: ConvertingInfixStringIntoPostfix(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

