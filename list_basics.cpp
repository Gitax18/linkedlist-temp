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

int main(){
    Node *tail = new Node(5);
    Node *third= new Node(12, tail);
    Node *second = new Node(15, third);
    Node *head = new Node(32, second);

    displayList(head);
    return 0;
}