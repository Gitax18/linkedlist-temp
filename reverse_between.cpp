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

// generate linkedlist from array
Node* generateFromVector(vector<int> array){
    if (array.size() == 0) {
        return nullptr;
    }

    Node* head = new Node(array[0]);
    Node* curr = head;
    for (int i = 1; i < array.size(); i++){
        Node* node = new Node(array[i]);
        curr->next = node;
        curr = curr->next;
    } 
    return head;
} 

// reverse the linkedlist from position left to position right
Node* reverseBetween(Node* head, int left, int right) {
    if( head->next == nullptr || !head) return head;

    Node dummyHead = Node(0, head); 

    Node* prevToLeft = &dummyHead;
    Node* curr = head;
    for (int i = 1; i < left; i++){
        prevToLeft = curr;
        curr = curr->next;
    }

    Node* prev = nullptr;
    for(int i = 0; i < (right-left)+1; i++){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    prevToLeft->next->next = curr;
    prevToLeft->next = prev;

    head = dummyHead.next;

    return head;
}


int main(){
    Node* head = generateFromVector({1,2,3,4,5});
    cout << "Linked list original:  ";
    displayList(head);
    head = reverseBetween(head, 2,4);
    cout << "After l-r reverse:  ";
    displayList(head);
    return 0;
}