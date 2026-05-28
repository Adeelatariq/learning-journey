#include <iostream>
using namespace std;
#define N 5

int q[N];
int f = -1, r = -1;

void enqueueinarray(int x) {
    if (r == N - 1) {
        cout << "Queue is full\n";
    } else if (f == -1 && r == -1) {
        f = r = 0;
        q[r] = x;
        cout<<"You enqueued the value : "<<q[r];
    } else {
        r++;
        q[r] = x;
        cout<<"You enqueued the value : "<<q[r];
    }
}

void dequeueinarray() {
    if (f ==r== -1) {
        cout << "Queue is empty\n";
    } else if (f == r) {
        cout << "Deleted: " << q[f] << endl;
        f = r = -1;
    } else {
        cout << "Deleted: " << q[f] << endl;
        f++;
    }
}
struct node {
    int value;
    node* next;
};

node* frontLL = NULL;
node* rearLL = NULL;

void enqueueinlinkedlist(int x) {
    node* nn = new node();
    nn->value = x;
    nn->next = NULL;

    if (frontLL == NULL) {
        frontLL = rearLL = nn;
        cout<<"You enqueued the value : "<<rearLL->value;
    } else {
        rearLL->next = nn;
        rearLL = nn;
        cout<<"You enqueued the value : "<<rearLL->value;
    }
}

void dequeueinlinkedlist() {
    if (frontLL == NULL) {
        cout << "Queue is empty\n";
    } else if (frontLL == rearLL) {
        cout << "Deleted: " << frontLL->value << endl;
        delete frontLL;
        frontLL = rearLL = NULL;
    } else {
        node* temp = frontLL;
        cout << "Deleted: " << temp->value << endl;
        frontLL = frontLL->next;
        delete temp;
    }
}
int cq[N];
int cf = -1, cr = -1;

void enqueueCircular(int x) {
    if ((cr + 1) % N == cf) {
        cout << "Queue is full\n";
    }
    else if (cf == -1 && cr == -1) {
        cf = cr = 0;
        cq[cr] = x;
    }
    else {
        cr = (cr + 1) % N;
        cq[cr] = x;
    }
}

void dequeueCircular() {
    if (cf == -1) {
        cout << "Queue is empty\n";
    }
    else if (cf == cr) {
        cout << "Deleted: " << cq[cf] << endl;
        cf = cr = -1;
    }
    else {
        cout << "Deleted: " << cq[cf] << endl;
        cf = (cf + 1) % N;
    };
//int findMinTarget(int target, int second) {
   // if (second < target)
   //     return second;
   // else
      //  return target;
}
int main(){
	enqueueinlinkedlist(4);
	enqueueinarray(5);
}


