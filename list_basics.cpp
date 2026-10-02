#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int v) {val=v;next=nullptr;}
    Node(int v, Node* nt) {val=v; next=nt;}
};

void displayList(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
}

// inserting in linkedlist
Node* insertAtEnd(Node *head, int value){
    Node *temp = new Node(value);

    if(head->next == nullptr){
        head->next = temp;
        return head;
    }

    Node *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
} 

Node* insertAtHead(Node *head, int value){
    Node *newHead = new Node(value);
    newHead->next = head;
    return newHead; 
}

Node* insertAtPos(Node *head, int value, int pos){
    // if pos out of range then making no change to the list and returning the list.
    if(pos <= 0){
        return head;
    }

    if(pos == 1){
        head = insertAtHead(head, value);
        return head;
    }

    Node *curr = head;
    int currPos = 1;
    bool posFound = false;
    while(currPos < pos && curr->next != nullptr){
        curr = curr->next;
        currPos++;
    }

    if(curr->next != nullptr && currPos == pos){
        Node *currPosNodeCpy = new Node(curr->val);
        currPosNodeCpy->next = curr->next;
        curr->val = value;
        curr->next = currPosNodeCpy;
    }

    return head;
}

int main(){
    Node *tail = new Node(5);
    Node *third= new Node(12, tail);
    Node *second = new Node(15, third);
    Node *head = new Node(32, second);

    head = insertAtEnd(head, 87);
    head = insertAtHead(head, 1);
    head = insertAtPos(head, 2, 2);

    displayList(head);
    return 0;
}